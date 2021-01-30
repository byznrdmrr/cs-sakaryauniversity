namespace TelefonRehberi
{
    partial class Form1
    {
        /// <summary>
        ///Gerekli tasarımcı değişkeni.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///Kullanılan tüm kaynakları temizleyin.
        /// </summary>
        ///<param name="disposing">yönetilen kaynaklar dispose edilmeliyse doğru; aksi halde yanlış.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer üretilen kod

        /// <summary>
        /// Tasarımcı desteği için gerekli metot - bu metodun 
        ///içeriğini kod düzenleyici ile değiştirmeyin.
        /// </summary>
        private void InitializeComponent()
        {
            this.buttonKayıtEkle = new System.Windows.Forms.Button();
            this.buttonKayıtListele = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // buttonKayıtEkle
            // 
            this.buttonKayıtEkle.Location = new System.Drawing.Point(12, 12);
            this.buttonKayıtEkle.Name = "buttonKayıtEkle";
            this.buttonKayıtEkle.Size = new System.Drawing.Size(229, 74);
            this.buttonKayıtEkle.TabIndex = 0;
            this.buttonKayıtEkle.Text = "Kayıt Ekleme";
            this.buttonKayıtEkle.UseVisualStyleBackColor = true;
            this.buttonKayıtEkle.Click += new System.EventHandler(this.buttonKayıtEkle_Click);
            // 
            // buttonKayıtListele
            // 
            this.buttonKayıtListele.Location = new System.Drawing.Point(12, 91);
            this.buttonKayıtListele.Name = "buttonKayıtListele";
            this.buttonKayıtListele.Size = new System.Drawing.Size(229, 74);
            this.buttonKayıtListele.TabIndex = 0;
            this.buttonKayıtListele.Text = "Kayıt Listeleme";
            this.buttonKayıtListele.UseVisualStyleBackColor = true;
            this.buttonKayıtListele.Click += new System.EventHandler(this.buttonKayıtListele_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(253, 171);
            this.Controls.Add(this.buttonKayıtListele);
            this.Controls.Add(this.buttonKayıtEkle);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button buttonKayıtEkle;
        private System.Windows.Forms.Button buttonKayıtListele;
    }
}

