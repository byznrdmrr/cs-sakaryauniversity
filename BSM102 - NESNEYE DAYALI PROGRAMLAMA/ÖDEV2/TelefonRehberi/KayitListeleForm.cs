using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TelefonRehberi
{
    public partial class KayitListeleForm : Form
    {

        public KayitListeleForm()
        {
            InitializeComponent();
            string fileName = "veriler.txt";
            try
            {
                //Dosya okuma modunda açılıyor
                var iStream = new FileStream(fileName, FileMode.Open, FileAccess.Read, FileShare.ReadWrite);
                var sr = new System.IO.StreamReader(iStream);

                //Renkler kolay kullanım için ikili değerler olarak bir Dictionary'e atılıyor.
                Dictionary<string, Color> colors = new Dictionary<string, Color>();
                colors.Add("k", Color.Red);
                colors.Add("m", Color.Blue);
                colors.Add("y", Color.Green);

                string line;
                int counter = 0;
                bool bold;

                //Dosya satır satır okunuyor
                while ((line = sr.ReadLine()) != null)
                {
                    counter++;
                    //Satırın numarasına göre kalınlık ayarlanıyor.
                    if (counter % 2 == 0)
                    {
                        bold = false;
                    }
                    else
                    {
                        bold = true;
                    }

                    //Satır boşluklarına göre ayırılıyor
                    String[] s = line.Split(' ');
                    for (int i = 0; i < 3; i++)
                    {
                        //İlk kısmından renk bilgisi alınıyor ve bold bilgisiyle beraber yazdırılıyor
                        Color color = colors.FirstOrDefault(t => t.Key == s[0][i].ToString()).Value;
                        AppendText(s[i + 1], color, bold);
                        //Aralarına boşluk bırakılıyor
                        AppendText(" ");
                    }
                    //Bir satır aşşağı iniliyor
                    AppendText("\n");
                }
            }
            catch (FileNotFoundException e)
            {
                //Eğer daha önce bir kayıt girilmediyse dosya oluşturulmadığı için hata gösteriyor.
                MessageBox.Show("Dosya bulunamadı lütfen önce kayıt ekleyiniz.\n"+e.Message, "Dosya bulunamadı.",MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        //Renk ve bold parametreleri ile yazmak için kullanılan method
        private void AppendText(string text, Color color, bool bold)
        {
            richTextBox1.SelectionStart = richTextBox1.TextLength;
            richTextBox1.SelectionColor = color;
            richTextBox1.SelectionFont = new Font(richTextBox1.Font, bold ? FontStyle.Bold : FontStyle.Regular);
            richTextBox1.SelectedText = text;
        }

        //Direk yazmak için kullanılan method
        private void AppendText(string text)
        {
            richTextBox1.AppendText(text);
        }
    }


}

