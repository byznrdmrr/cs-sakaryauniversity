using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication21
{
    public partial class AnaPencerem : Form
    {
        
       // static Point firstPoint = new Point();
        Color renk;
        public int x = 100;
        public int y = 100;
        public int width = 0;
        public int height = 0;
        static Color SlctClr = Color.Black;
        static Color SlctPenClr = Color.Black;

        int maxKareSayisi = 100;
        sekil[] sekiller;  //bu dizi her çizdiğim nesnenin referansını tutacak
        int sekilSayisi = 0;

        bool cizimAktifmi = false;
        // kare karem = new kare(renk);
        sekil aktifSekil = null;
        int secim;
        private Bitmap bm;
       

        public AnaPencerem(int width, int height)
        {
            sekiller = new sekil[maxKareSayisi];

            DoubleBuffered = true; //daha iyi çizmesi için

            renk = Color.Red;
            Height = width;
            Width = height;
            InitializeComponent();

            MouseDown += AnaPencerem_MouseDown;
            MouseMove += AnaPencerem_MouseMove;
            MouseUp += AnaPencerem_MouseUp;
            Paint += AnaPencerem_Paint;

        }

        private void AnaPencerem_Paint(object sender, PaintEventArgs e)
        {
            Graphics cizimAraci = e.Graphics;

            if (aktifSekil != null)
                aktifSekil.ciz(cizimAraci);

            for (int i = 0; i < sekilSayisi; i++) //var olan bütün şekilleri çizdir
                sekiller[i].ciz(cizimAraci);

        }

        private void AnaPencerem_MouseUp(object sender, MouseEventArgs e)
        {

            if (maxKareSayisi != maxKareSayisi - 1)
                cizimAktifmi = false; //fare bırakıldıgı an 

            sekiller[sekilSayisi] = aktifSekil;// Aktif olan nesnenin referansı şekiller dizisindeki boş kısma yerleştiriliyor
            sekilSayisi++;

           

            Invalidate();//forma çizimin tekrardan yapılmasını söylüyor

        }

        private void AnaPencerem_MouseMove(object sender, MouseEventArgs e)
        {
            if (cizimAktifmi) //mousemove hareketi algılayaıp karenin genislik ve yuksekligini atayacak
            {
                aktifSekil.BitisAta(e.X, e.Y);

                Invalidate(); //forma çizimin tekrardan yapılmasını söylüyor
            }      

        }


        private void AnaPencerem_MouseDown(object sender, MouseEventArgs e)
        {


            if (secim == 1)
            {
                aktifSekil = new kare(renk); //tekrar çizim yapıldıkça yeni bir kare oluşuyor
            }
            if (secim == 2)
            {
                aktifSekil = new daire(renk);
            }
            if (secim == 3)
            {
                aktifSekil = new ucgen(0, 0, 0, 0, renk);
            }
            if (secim == 4)
            {
                aktifSekil = new altıgen(0, 0, 0, 0, renk);
            }
           

            cizimAktifmi = true; //mouse'a basılı tutulduğu an aktif olacak
            aktifSekil.X = e.X;
            aktifSekil.Y = e.Y;
            // karem.Y = e.Y;
            Invalidate(); //forma çizimin tekrardan yapılmasını söylüyor

           

        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            secim = 1;
            if (cizimAktifmi == true)
            {
                pictureBox1.BackColor = Color.Azure;
                // cizimAktifmi = false;
            }
            else
            {
                pictureBox1.BackColor = Color.LightPink;
                //cizimAktifmi = true;
            }

        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            renk = Color.Red;
        }

        private void pictureBox3_Click(object sender, EventArgs e)
        {
            secim = 2;
            if (cizimAktifmi == true)
            {
                pictureBox3.BackColor = Color.Azure;
                //cizimAktifmi = false;
            }
            else
            {
                pictureBox3.BackColor = Color.LightPink;
                //cizimAktifmi = true;
            }
        }

        private void pictureBox4_Click(object sender, EventArgs e)
        {
            secim = 3;
            if (cizimAktifmi == true)
            {
                pictureBox4.BackColor = Color.Azure;
                //cizimAktifmi = false;
            }
            else
            {
                pictureBox4.BackColor = Color.LightPink;
                //cizimAktifmi = true;
            }
        }

        private void pictureBox5_Click(object sender, EventArgs e)
        {
            renk = Color.Blue;
        }

        private void pictureBox10_Click(object sender, EventArgs e)
        {
            renk = Color.Green;
        }

        private void AnaPencerem_Load(object sender, EventArgs e)
        {

        }

        private void panel2_Paint(object sender, PaintEventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox6_Click(object sender, EventArgs e)
        {
            renk = Color.Orange;
        }

        private void pictureBox7_Click(object sender, EventArgs e)
        {
            renk = Color.Black;
        }

        private void pictureBox11_Click(object sender, EventArgs e)
        {
            renk = Color.Yellow;
        }

        private void pictureBox8_Click(object sender, EventArgs e)
        {
            renk = Color.Purple;
        }

        private void pictureBox9_Click(object sender, EventArgs e)
        {
            renk = Color.Brown;
        }

        private void pictureBox12_Click(object sender, EventArgs e)
        {
            renk = Color.White;
        }

        private void pictureBox13_Click(object sender, EventArgs e)
        {
            secim = 4;
            if (cizimAktifmi == true)
            {
                pictureBox13.BackColor = Color.Azure;

            }
            else
            {
                pictureBox13.BackColor = Color.LightPink;

            }
        }

        private void pictureBox16_Click(object sender, EventArgs e)
        {
            OpenFileDialog open = new OpenFileDialog();
            open.Filter = "png files| *.png| jpg files| *jpg| bitmap| *bmp";
            if(open.ShowDialog()==DialogResult.OK)
            {
                try
                {
                    Bitmap oldbm = bm;
                    bm = new Bitmap(open.FileName);
                    oldbm.Dispose();
                }
                catch(Exception ex)
                {
                    MessageBox.Show("error loading image" + ex.Message);
                }
            }
        }

        private void pictureBox15_Click(object sender, EventArgs e) //silen fonksiyon
        {
            
        }

        private void pictureBox17_Click(object sender, EventArgs e)
        {
            Bitmap bm = new Bitmap(panel1.Width, panel1.Height);
            Graphics setpaint = Graphics.FromImage(bm);
            Rectangle rect = panel1.RectangleToScreen(panel1.ClientRectangle);
            setpaint.CopyFromScreen(rect.Location, Point.Empty, panel1.Size);
            panel1.Dispose();
            SaveFileDialog save = new SaveFileDialog();
            save.Filter = "Png files| *.png|jpeg files| *jpg| bitmaps| *bmg";
            if(save.ShowDialog()==DialogResult.OK)
            {
                try
                {
                    if (File.Exists(save.FileName))
                    {
                        File.Delete(save.FileName);
                    }
                    if (save.FileName.Contains(".jpg"))
                    {
                        bm.Save(save.FileName, ImageFormat.Jpeg);
                    }
                    else if (save.FileName.Contains(".png"))
                    {
                        bm.Save(save.FileName, ImageFormat.Png);
                    }
                    else if (save.FileName.Contains(".bmg"))
                    {
                        bm.Save(save.FileName, ImageFormat.Bmp);
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show("file save error:" + ex.Message);
                }

                }
            }

        private void panel5_Paint(object sender, PaintEventArgs e)
        {
           
        }
    }
    }

