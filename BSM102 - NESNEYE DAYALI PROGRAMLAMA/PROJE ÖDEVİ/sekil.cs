using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApplication21
{
    class sekil
    {
       
        private float x;
        private float y;

      


        public float X
        {
            get
            {
                return x;
            }
            set
            {
                x = value;
            }
        }
        public float Y
        {
            get
            {
                return y;
            }
            set
            {
                y = value;
            }
        }


        public virtual void BitisAta(float bx, float by)
        {

        }

        public virtual void ciz(Graphics cizimAraci)
        {

        }

        internal void ciz(object cizimAraci)
        {
            throw new NotImplementedException();
        }
    }

}
