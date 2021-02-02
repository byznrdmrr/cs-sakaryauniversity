using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace restaurant
{

    class cPersoneller
    {
        cGenel gnl = new cGenel(); //nesne oluşturduk
        #region Fields
        private int _PersonelId;
        private int _PersonelGorevId;
        private string _PersonelAd;
        private string _PersonelSoyad;
        private string _PersonelParola;
        private string _PersonelKullaniciAdi;
        private bool _PersonelDurum;

        #endregion
        #region Properties
        public int PersonelId
        {
            get
            {
                return _PersonelId;
            }

            set
            {
                _PersonelId = value;
            }
        }

        public int PersonelGorevId
        {
            get
            {
                return _PersonelGorevId;
            }

            set
            {
                _PersonelGorevId = value;
            }
        }

        public string PersonelAd
        {
            get
            {
                return _PersonelAd;
            }

            set
            {
                _PersonelAd = value;
            }
        }

        public string PersonelSoyad
        {
            get
            {
                return _PersonelSoyad;
            }

            set
            {
                _PersonelSoyad = value;
            }
        }

        public string PersonelParola
        {
            get
            {
                return _PersonelParola;
            }

            set
            {
                _PersonelParola = value;
            }
        }

        public string PersonelKullaniciAdi
        {
            get
            {
                return _PersonelKullaniciAdi;
            }

            set
            {
                _PersonelKullaniciAdi = value;
            }
        }

        public bool PersonelDurum
        {
            get
            {
                return _PersonelDurum;
            }

            set
            {
                _PersonelDurum = value;
            }
        }
        #endregion
        public bool personelEntryControl(string password,int UserId)
        {
            bool result = false;
            SqlConnection con = new SqlConnection(gnl.conString);
            SqlCommand cmd = new SqlCommand("Select * from Personeller where ID=@Id and PAROLA=@password", con);
            cmd.Parameters.Add("@Id", SqlDbType.VarChar).Value = UserId;
            cmd.Parameters.Add("@password", SqlDbType.VarChar).Value = password;
            try
            {
               if(con.State==ConnectionState.Closed)
                {
                    con.Open();

                }
                result = Convert.ToBoolean(cmd.ExecuteScalar());
            }
            catch(SqlException ex)
            {
                string hata = ex.Message;
                throw;
            }
            return result;

        }
        public void personelGetbyInformation(ComboBox cb)
        {
            cb.Items.Clear();
            SqlConnection con = new SqlConnection(gnl.conString);
            SqlCommand cmd = new SqlCommand("Select * from Personeller", con);
           
            
                if (con.State == ConnectionState.Closed)
                {
                    con.Open();

                }
            SqlDataReader dr = cmd.ExecuteReader();
            while(dr.Read())
            {
                cPersoneller p = new cPersoneller();
                p._PersonelId = Convert.ToInt32(dr["ID"]);
                p._PersonelGorevId = Convert.ToInt32(dr["GOREVID"]);
                p._PersonelAd = Convert.ToString(dr["AD"]);
                p._PersonelSoyad = Convert.ToString(dr["SOYAD"]);
                p._PersonelParola = Convert.ToString(dr["PAROLA"]);
                p._PersonelKullaniciAdi = Convert.ToString(dr["KULLANICIADI"]);
                p._PersonelDurum = Convert.ToBoolean(dr["DURUM"]);
                cb.Items.Add(p);

            }
            dr.Close();
            con.Close();
                            
            
        }
        public override string ToString()
        {
            return PersonelAd + " " +PersonelSoyad;
        }

    }  

}
