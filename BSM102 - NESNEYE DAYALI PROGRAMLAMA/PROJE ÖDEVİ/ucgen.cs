using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApplication21
{
    class ucgen:sekil
    {
        private float width;
        private float height;
        Pen pen;

        public ucgen( float x, float y, float width, float height,Color renk)
        {
            pen = new Pen(renk, 3);
            X = x;
            Y = y;
            this.width = width;
            this.height = height;          
        }

        public override void BitisAta(float bx, float by)
        {
            height = by - Y;
            width = bx - X;
        }

        public override void ciz(Graphics cizimAraci)
        {
            PointF point1 = new PointF(X, Y - height);
            PointF point2 = new PointF(X + width, Y + height);
            PointF point3 = new PointF(X - width, Y + height);
            PointF[] CornerPoints = new PointF[3];
            CornerPoints[0] = point1;
            CornerPoints[1] = point2;
            CornerPoints[2] = point3;
            pen.Width = 3;
            cizimAraci.DrawPolygon(pen, CornerPoints);
        }

    }

    
}
