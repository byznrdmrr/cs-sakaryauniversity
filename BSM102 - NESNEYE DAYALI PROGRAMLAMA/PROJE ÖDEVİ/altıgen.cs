using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApplication21
{
    
    class altıgen:sekil
    {
        private float width;
        private float height;
        Pen pen;

        public altıgen(float x, float y, float width, float height,Color renk)
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
            PointF point1 = new PointF(X, Y);
            PointF point2 = new PointF(X + (width / 2), (Y + height));
            PointF point3 = new PointF(X + 3 * (width / 2), (Y + height));
            PointF point4 = new PointF(X + (2 * width), Y);
            PointF point5 = new PointF(X + 3 * (width / 2), (Y - height));
            PointF point6 = new PointF(X + (width / 2), (Y - height));
            PointF[] CornerPoints = new PointF[6];
            CornerPoints[0] = point1;
            CornerPoints[1] = point2;
            CornerPoints[2] = point3;
            CornerPoints[3] = point4;
            CornerPoints[4] = point5;
            CornerPoints[5] = point6;
            pen.Width = 3;
            cizimAraci.DrawPolygon(pen, CornerPoints);
           
        }
    }
}
