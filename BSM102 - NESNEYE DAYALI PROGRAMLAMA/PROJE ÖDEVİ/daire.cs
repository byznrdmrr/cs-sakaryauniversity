using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApplication21
{
    class daire:sekil
    {
        Pen pen;
        private float cap;

        public daire(Color renk)
        {
            pen = new Pen(renk, 3);
        }
        public override void BitisAta(float bx, float by)
        {
            cap = bx - X;
        }

        public override void ciz(Graphics cizimAraci)
        {
            cizimAraci.DrawEllipse(pen, X, Y, cap, cap);
        }
    }
}
