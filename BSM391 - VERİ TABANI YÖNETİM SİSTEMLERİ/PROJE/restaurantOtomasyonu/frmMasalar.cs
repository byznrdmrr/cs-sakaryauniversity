using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace restaurant
{
    public partial class frmMasalar : Form
    {
        public frmMasalar()
        {
            InitializeComponent();
        }

        private void btnCikis_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Çıkmak istediğinizden emin misiniz?", "UYARI", MessageBoxButtons.YesNo, MessageBoxIcon.Warning) == DialogResult.Yes)
            {
                Application.Exit();
            }

        }

        private void btnGeriDön_Click(object sender, EventArgs e)
        {
            frmMenu frm = new frmMenu();
            this.Close();
            frm.Show();
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void btnMasa1_Click(object sender, EventArgs e)
        {
            frmSiparis frm = new frmSiparis();
            int uzunluk = btnMasa1.Text.Length;

            cGenel._ButtonValue = btnMasa1.Text.Substring(uzunluk -6,6);
            cGenel._ButtonName = btnMasa1.Name;
            this.Close();
            frm.ShowDialog();
        }

        private void btnMasa2_Click(object sender, EventArgs e)
        {
            frmSiparis frm = new frmSiparis();
            int uzunluk = btnMasa2.Text.Length;

            cGenel._ButtonValue = btnMasa2.Text.Substring(uzunluk - 5, 5);
            cGenel._ButtonName = btnMasa2.Name;
            this.Close();
            frm.ShowDialog();
        }

        private void btnMasa3_Click(object sender, EventArgs e)
        {
            frmSiparis frm = new frmSiparis();
            int uzunluk = btnMasa3.Text.Length;

            cGenel._ButtonValue = btnMasa3.Text.Substring(uzunluk - 5, 5);
            cGenel._ButtonName = btnMasa3.Name;
            this.Close();
            frm.ShowDialog();
        }

        private void btnMasa4_Click(object sender, EventArgs e)
        {
            frmSiparis frm = new frmSiparis();
            int uzunluk = btnMasa4.Text.Length;

            cGenel._ButtonValue = btnMasa4.Text.Substring(uzunluk - 5, 5);
            cGenel._ButtonName = btnMasa4.Name;
            this.Close();
            frm.ShowDialog();
        }

        private void btnMasa5_Click(object sender, EventArgs e)
        {
            frmSiparis frm = new frmSiparis();
            int uzunluk = btnMasa5.Text.Length;

            cGenel._ButtonValue = btnMasa5.Text.Substring(uzunluk - 5, 5);
            cGenel._ButtonName = btnMasa5.Name;
            this.Close();
            frm.ShowDialog();
        }

        private void btnMasa6_Click(object sender, EventArgs e)
        {
            frmSiparis frm = new frmSiparis();
            int uzunluk = btnMasa6.Text.Length;

            cGenel._ButtonValue = btnMasa6.Text.Substring(uzunluk - 5, 5);
            cGenel._ButtonName = btnMasa6.Name;
            this.Close();
            frm.ShowDialog();
        }

         cGenel gnl = new cGenel();
        private void frmMasalar_Load(object sender, EventArgs e)
        {

            SqlConnection con = new SqlConnection(gnl.conString);
            SqlCommand cmd = new SqlCommand("Select DURUM,ID from Masalar",con);
            SqlDataReader dr = null;
            if (con.State == ConnectionState.Closed)
            {
                con.Open();

            }
            dr = cmd.ExecuteReader();

            while (dr.Read())
            {
                foreach(Control item in this.Controls)
                {
                       if(item is Button)
                    {
                        if(item.Name=="btnMasa" +dr["ID"].ToString() && dr["DURUM"].ToString()=="1")
                        {
                            item.BackgroundImage = (System.Drawing.Image)(Properties.Resources.kırmızımasa); //BOŞ MASA
                        }
                        else if (item.Name == "btnMasa" + dr["ID"].ToString() && dr["DURUM"].ToString() == "2")
                        {
                            cMasalar ms = new cMasalar();

                            DateTime dt1 = Convert.ToDateTime(ms.SessionSum(2));
                            DateTime dt2 = DateTime.Now;

                            string st1 = Convert.ToDateTime(ms.SessionSum(2)).ToShortTimeString();
                            string st2 = DateTime.Now.ToShortTimeString();

                            DateTime t1 = dt1.AddMinutes(DateTime.Parse(st1).TimeOfDay.TotalMinutes);
                            DateTime t2 = dt1.AddMinutes(DateTime.Parse(st2).TimeOfDay.TotalMinutes);

                            var fark = t2 - t1;

                            item.Text =
                            string.Format("{0}{1}{2}",
                            fark.Days > 0 ? string.Format("{0} Gün", fark.Days) : "",
                            fark.Hours > 0 ? string.Format("{0} Saat", fark.Hours) : "",
                            fark.Minutes > 0 ? string.Format("{0} Dakika", fark.Minutes) : "").Trim() + "\n\n\nMasa" + dr["ID"].ToString();


                            item.BackgroundImage = (System.Drawing.Image)(Properties.Resources.dolumasa); //DOLU MASA
                        }

                        else if(item.Name == "btnMasa" + dr["ID"].ToString() && dr["DURUM"].ToString() == "3")
                            {
                            item.BackgroundImage = (System.Drawing.Image)(Properties.Resources.rezervemasa); //AÇIK REZERVE MASA
                            }

                        else if (item.Name == "btnMasa" + dr["ID"].ToString() && dr["DURUM"].ToString() == "4")
                            {
                                item.BackgroundImage = (System.Drawing.Image)(Properties.Resources.mavi_masa); // REZERVE MASA
                            }
                    }
                }
            }
        }
    }
}
