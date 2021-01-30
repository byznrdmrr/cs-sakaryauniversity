using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApplication21
{
    class kare:sekil
    {
        public float width;
        Pen pen;
       

        public kare(Color renk)
        {
            width = 0;
            pen = new Pen(renk, 3);
            
        }

        public override void BitisAta(float bx, float by)
        {
            width = bx - X;
           
        }

        public override void ciz(Graphics cizimAraci)
        {
            cizimAraci.DrawRectangle(pen, X, Y, width, width);
            
        }
    }
    
}
