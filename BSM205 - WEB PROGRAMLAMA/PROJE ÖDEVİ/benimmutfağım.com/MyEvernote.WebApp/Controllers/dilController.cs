using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Threading;
using System.Globalization;

namespace MyEvernote.WebApp.Controllers
{
    public class dilController : Controller
    {
        // GET: dil
        public ActionResult dil()
        {
            return View();
        }
        public ActionResult Change(String LanguageAbbrevation)
        {
            if(LanguageAbbrevation !=null)
            {
                Thread.CurrentThread.CurrentCulture = CultureInfo.CreateSpecificCulture(LanguageAbbrevation);
                Thread.CurrentThread.CurrentUICulture = new CultureInfo(LanguageAbbrevation);
            }

            HttpCookie cookie = new HttpCookie("dil");
            cookie.Value = LanguageAbbrevation;
            Response.Cookies.Add(cookie);
            return View("dil");
        }
    }
}