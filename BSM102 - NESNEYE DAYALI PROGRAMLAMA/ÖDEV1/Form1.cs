using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Emgu.CV;
using Emgu.Util;
using Emgu.CV.Structure;
using Emgu.CV.UI;


namespace WindowsFormsApplication6
{
    public partial class Form1 : Form
    {
        Image<Bgr, byte> ımginput;
        Image<Gray, byte> gri;

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog dialog = new OpenFileDialog();
            dialog.Title = "Open İmage";
            dialog.Filter = "jpg files (*.jpg)|*.jpg";

            if(dialog.ShowDialog() == DialogResult.OK)
            {
                ımginput = new Image<Bgr, byte>(dialog.FileName);
                ımageBox1.Image = ımginput;
            }
            dialog.Dispose();
            
        }


        private void button2_Click(object sender, EventArgs e)

        {
            gri = ımginput.Convert<Gray, byte>();
            ımageBox3.Image = gri;
        }

        public static Image<Gray, byte> BinaryGetir(Image<Gray, byte> gri)
        {
            int threshold = 70;

            Image<Gray, byte> binary = gri.ThresholdBinary(new Gray(threshold),
            new Gray(255));
            return binary;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            gri = BinaryGetir(gri);
            ımageBox2.Image = gri;
        }

        public static Mat HistogramGetir(Image<Gray, byte> gri)

        {

            DenseHistogram hist = new DenseHistogram(256, new RangeF(0, 256));
            hist.Calculate(new Image<Gray, Byte>[] { gri }, false, null);
            Mat m = new Mat();
            hist.CopyTo(m);
            return m;
        }

        private void button4_Click(object sender, EventArgs e)
        {

            gri = ımginput.Convert<Gray, byte>();
            ımageBox3.Image = gri;
            Mat m = HistogramGetir(gri);
            histogramBox1.ClearHistogram();
            histogramBox1.AddHistogram("Gri Histogram", Color.Gray, m, 256, new float[] { 0.0f, 256.0f });
            histogramBox1.Refresh();
        }
    }
}
