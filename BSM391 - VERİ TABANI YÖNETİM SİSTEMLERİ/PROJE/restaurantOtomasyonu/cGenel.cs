using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace restaurant
{
    class cGenel
    {
        public string conString = ("Server=BEYZANUR\\SQLSERVER2017EXP;Database=RestaurantOtomasyon;Trusted_Connection=True");
        public static int _personelId; //her yerden ulaşabilmek için static yapıyoruz
        public static int _gorevId;

        public static string _ButtonValue;
        public static string _ButtonName;
    }
}
