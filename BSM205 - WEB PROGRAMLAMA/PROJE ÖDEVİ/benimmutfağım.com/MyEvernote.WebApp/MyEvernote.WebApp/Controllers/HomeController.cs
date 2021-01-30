using MyEvernote.BusinessLayer;
using MyEvernote.BusinessLayer.Results;
using MyEvernote.Entities;
using MyEvernote.Entities.Messages;
using MyEvernote.Entities.ValueObjects;
using MyEvernote.WebApp.Filters;
using MyEvernote.WebApp.Models;
using MyEvernote.WebApp.ViewModels;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;

namespace MyEvernote.WebApp.Controllers
{
    [Exc]
    public class HomeController : Controller
    {
        private NoteManager noteManager = new NoteManager();
        private CategoryManager categoryManager = new CategoryManager();
        private EvernoteUserManager evernoteUserManager = new EvernoteUserManager();

        // GET: Home
        public ActionResult Index()
        {
            //object o = 0;
            //int a = 1;
            //int c = a / (int)o;

            //throw new Exception("Herhangi bir hata oluştu.");



            // CategoyController üzerinden gelen view talebi ve model..
            //
            //if (TempData["mm"] != null)
            //{
            //    return View(TempData["mm"] as List<Note>);
            //}


            return View(noteManager.ListQueryable().Where(x => x.IsDraft == false).OrderByDescending(x => x.ModifiedOn).ToList());
            //return View(nm.GetAllNoteQueryable().OrderByDescending(x => x.ModifiedOn).ToList());
        }

        public ActionResult ByCategory(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }

            //Category cat = categoryManager.Find(x => x.Id == id.Value);

            //if (cat == null)
            //{
            //    return HttpNotFound();
            //    //return RedirectToAction("Index", "Home");
            //}

            //List<Note> notes = cat.Notes.Where(
            //    x => x.IsDraft == false).OrderByDescending(x => x.ModifiedOn).ToList()

            List<Note> notes = noteManager.ListQueryable().Where(
                x => x.IsDraft == false && x.CategoryId == id).OrderByDescending(
                x => x.ModifiedOn).ToList();

            return View("Index", notes);
        }

        public ActionResult MostLiked()
        {
            return View("Index", noteManager.ListQueryable().OrderByDescending(x => x.LikeCount).ToList());
        }

        public ActionResult About()
        {
            return View();
        }


        [Auth]
        public ActionResult ShowProfile()
        {
            BusinessLayerResult<EvernoteUser> res =
                evernoteUserManager.GetUserById(CurrentSession.User.Id);

            if (res.Errors.Count > 0)
            {
                ErrorViewModel errorNotifyObj = new ErrorViewModel()
                {
                    Title = "Hata Oluştu",
                    Items = res.Errors
                };

                return View("Error", errorNotifyObj);
            }

            return View(res.Result);
        }

        [Auth]
        public ActionResult EditProfile()
        {
            BusinessLayerResult<EvernoteUser> res = evernoteUserManager.GetUserById(CurrentSession.User.Id);

            if (res.Errors.Count > 0)
            {
                ErrorViewModel errorNotifyObj = new ErrorViewModel()
                {
                    Title = "Hata Oluştu",
                    Items = res.Errors
                };

                return View("Error", errorNotifyObj);
            }

            return View(res.Result);
        }

        [Auth]
        [HttpPost]
        public ActionResult EditProfile(EvernoteUser model, HttpPostedFileBase ProfileImage)
        {
            ModelState.Remove("ModifiedUsername");

            if (ModelState.IsValid)
            {
                if (ProfileImage != null &&
                    (ProfileImage.ContentType == "image/jpeg" ||
                    ProfileImage.ContentType == "image/jpg" ||
                    ProfileImage.ContentType == "image/png"))
                {
                    string filename = $"user_{model.Id}.{ProfileImage.ContentType.Split('/')[1]}";

                    ProfileImage.SaveAs(Server.MapPath($"~/images/{filename}"));
                    model.ProfileImageFilename = filename;
                }

                BusinessLayerResult<EvernoteUser> res = evernoteUserManager.UpdateProfile(model);

                if (res.Errors.Count > 0)
                {
                    ErrorViewModel errorNotifyObj = new ErrorViewModel()
                    {
                        Items = res.Errors,
                        Title = "Profil Güncellenemedi.",
                        RedirectingUrl = "/Home/EditProfile"
                    };

                    return View("Error", errorNotifyObj);
                }

                // Profil güncellendiği için session güncellendi.
                CurrentSession.Set<EvernoteUser>("login", res.Result);

                return RedirectToAction("ShowProfile");
            }

            return View(model);
        }

        [Auth]
        public ActionResult DeleteProfile()
        {
            BusinessLayerResult<EvernoteUser> res =
                evernoteUserManager.RemoveUserById(CurrentSession.User.Id);

            if (res.Errors.Count > 0)
            {
                ErrorViewModel errorNotifyObj = new ErrorViewModel()
                {
                    Items = res.Errors,
                    Title = "Profil Silinemedi.",
                    RedirectingUrl = "/Home/ShowProfile"
                };

                return View("Error", errorNotifyObj);
            }

            Session.Clear();

            return RedirectToAction("Index");
        }



        public ActionResult Login()
        {
            return View();
        }

        [HttpPost]
        public ActionResult Login(LoginViewModel model)
        {
            if (ModelState.IsValid)
            {
                BusinessLayerResult<EvernoteUser> res = evernoteUserManager.LoginUser(model);

                if (res.Errors.Count > 0)
                {
                    // Hata koduna göre özel işlem yapmamız gerekirse..
                    // Hatta hata mesajına burada müdahale edilebilir.
                    // (Login.cshtml'deki kısmında açıklama satırı şeklinden kurtarınız)
                    //
                    //if (res.Errors.Find(x => x.Code == ErrorMessageCode.UserIsNotActive) != null)
                    //{
                    //    ViewBag.SetLink = "http://Home/Activate/1234-4567-78980";
                    //}

                    res.Errors.ForEach(x => ModelState.AddModelError("", x.Message));

                    return View(model);
                }

                CurrentSession.Set<EvernoteUser>("login", res.Result); // Session'a kullanıcı bilgi saklama..
                return RedirectToAction("Index");   // yönlendirme..
            }

            return View(model);
        }

        public ActionResult Register()
        {
            return View();
        }

        [HttpPost]
        public ActionResult Register(RegisterViewModel model)
        {
            if (ModelState.IsValid)
            {
                BusinessLayerResult<EvernoteUser> res = evernoteUserManager.RegisterUser(model);

                if (res.Errors.Count > 0)
                {
                    res.Errors.ForEach(x => ModelState.AddModelError("", x.Message));
                    return View(model);
                }


                //EvernoteUser user = null;

                //try
                //{
                //    user = eum.RegisterUser(model);
                //}
                //catch (Exception ex)
                //{
                //    ModelState.AddModelError("", ex.Message);   
                //}



                //if (model.Username == "aaa")
                //{
                //    ModelState.AddModelError("", "Kullanıcı adı kullanılıyor.");
                //}

                //if(model.EMail == "aaa@aa.com")
                //{
                //    ModelState.AddModelError("", "E-posta adresi kullanılıyor.");
                //}

                //foreach (var item in ModelState)
                //{
                //    if(item.Value.Errors.Count > 0)
                //    {
                //        return View(model);
                //    }
                //}

                //if (user == null)
                //{
                //    return View(model);
                //}

                OkViewModel notifyObj = new OkViewModel()
                {
                    Title = "Kayıt Başarılı",
                    RedirectingUrl = "/Home/Login",
                };

                notifyObj.Items.Add("Lütfen e-posta adresinize gönderdiğimiz aktivasyon link'ine tıklayarak hesabınızı aktive ediniz. Hesabınızı aktive etmeden not ekleyemez ve beğenme yapamazsınız.");

                return View("Ok", notifyObj);
            }

            return View(model);
        }

        public ActionResult UserActivate(Guid id)
        {
            BusinessLayerResult<EvernoteUser> res = evernoteUserManager.ActivateUser(id);

            if (res.Errors.Count > 0)
            {
                ErrorViewModel errorNotifyObj = new ErrorViewModel()
                {
                    Title = "Geçersiz İşlem",
                    Items = res.Errors
                };

                return View("Error", errorNotifyObj);
            }

            OkViewModel okNotifyObj = new OkViewModel()
            {
                Title = "Hesap Aktifleştirildi",
                RedirectingUrl = "/Home/Login"
            };

            okNotifyObj.Items.Add("Hesabınız aktifleştirildi. Artık not paylaşabilir ve beğenme yapabilirsiniz.");

            return View("Ok", okNotifyObj);
        }



        public ActionResult Logout()
        {
            Session.Clear();
            return RedirectToAction("Index");
        }


        public ActionResult AccessDenied()
        {
            return View();
        }


        public ActionResult HasError()
        {
            return View();
        }
    }
}