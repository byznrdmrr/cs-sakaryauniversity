using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TelefonRehberi
{
    public partial class Form1 : Form
    {
        KayitEkleForm kayitEkleForm;
        KayitListeleForm kayitListeleForm;
        public Form1()
        {
            InitializeComponent();
        }

        private void buttonKayıtEkle_Click(object sender, EventArgs e)
        {
            //Kayıt ekleme sayfası açılıyor
            kayitEkleForm = new KayitEkleForm();
            kayitEkleForm.ShowDialog();
        }

        private void buttonKayıtListele_Click(object sender, EventArgs e)
        {
            //Kayıt listeleme sayfası açılıyor
            kayitListeleForm = new KayitListeleForm();
            kayitListeleForm.ShowDialog();
        }
    }
}
