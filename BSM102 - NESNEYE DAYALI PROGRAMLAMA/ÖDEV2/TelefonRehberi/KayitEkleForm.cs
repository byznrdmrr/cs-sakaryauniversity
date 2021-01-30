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
    public partial class KayitEkleForm : Form
    {
        private List<ComboBox> comboBoxList;
        private StreamWriter sw;
        public KayitEkleForm()
        {
            InitializeComponent();

            //Dosya yazma için açılıyor
            string fileName = "veriler.txt";
            var oStream = new FileStream(fileName, FileMode.Append, FileAccess.Write, FileShare.Read);
            sw = new System.IO.StreamWriter(oStream);

            //Comboboxlar dolduruluyor
            comboBoxList = new List<ComboBox>();
            comboBoxList.Add(comboBoxRenkAd);
            comboBoxList.Add(comboBoxRenkSoyad);
            comboBoxList.Add(comboBoxRenkTelefon);
            foreach (var comboBox in comboBoxList)
            {
                comboBox.DisplayMember = "Text";
                comboBox.ValueMember = "Value";
                var items = new[] {
                new { Text = "Kırmızı", Value = "k" },
                new { Text = "Mavi", Value = "m" },
                new { Text = "Yeşil", Value = "y" }
            };
                comboBox.DataSource = items;
            }

        }

        private void buttonKayitEkle_Click(object sender, EventArgs e)
        {
            //Girilen değerler ve renkler alınıyor
            string name = textBoxAd.Text;
            string surname = textBoxSoyad.Text;
            string tel = textBoxTelefon.Text;
            string colors = "";
            foreach (var comboBox in comboBoxList)
            {
                colors += comboBox.SelectedValue;
            }

            //Dosyaya yazma işlemi
            sw.WriteLine(colors + " " + name + " " + surname + " " + tel);
            sw.Flush();

            //Alanları sıfırlama
            textBoxAd.Text = "";
            textBoxSoyad.Text = "";
            textBoxTelefon.Text = "";
            foreach (var comboBox in comboBoxList)
            {
                comboBox.SelectedIndex = 0;
            }
        }
    }
}
