namespace TelefonRehberi
{
    partial class KayitEkleForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.textBoxAd = new System.Windows.Forms.TextBox();
            this.comboBoxRenkAd = new System.Windows.Forms.ComboBox();
            this.buttonKayitEkle = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.textBoxSoyad = new System.Windows.Forms.TextBox();
            this.comboBoxRenkSoyad = new System.Windows.Forms.ComboBox();
            this.label3 = new System.Windows.Forms.Label();
            this.textBoxTelefon = new System.Windows.Forms.TextBox();
            this.comboBoxRenkTelefon = new System.Windows.Forms.ComboBox();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(18, 14);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(20, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Ad";
            // 
            // textBoxAd
            // 
            this.textBoxAd.Location = new System.Drawing.Point(64, 12);
            this.textBoxAd.Name = "textBoxAd";
            this.textBoxAd.Size = new System.Drawing.Size(165, 20);
            this.textBoxAd.TabIndex = 1;
            // 
            // comboBoxRenkAd
            // 
            this.comboBoxRenkAd.FormattingEnabled = true;
            this.comboBoxRenkAd.Location = new System.Drawing.Point(235, 11);
            this.comboBoxRenkAd.Name = "comboBoxRenkAd";
            this.comboBoxRenkAd.Size = new System.Drawing.Size(128, 21);
            this.comboBoxRenkAd.TabIndex = 2;
            // 
            // buttonKayitEkle
            // 
            this.buttonKayitEkle.Location = new System.Drawing.Point(21, 90);
            this.buttonKayitEkle.Name = "buttonKayitEkle";
            this.buttonKayitEkle.Size = new System.Drawing.Size(347, 49);
            this.buttonKayitEkle.TabIndex = 3;
            this.buttonKayitEkle.Text = "Kayıt Ekle";
            this.buttonKayitEkle.UseVisualStyleBackColor = true;
            this.buttonKayitEkle.Click += new System.EventHandler(this.buttonKayitEkle_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(18, 40);
            this.label2.Name = "label2";
            this.label2.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.label2.Size = new System.Drawing.Size(37, 13);
            this.label2.TabIndex = 0;
            this.label2.Text = "Soyad";
            // 
            // textBoxSoyad
            // 
            this.textBoxSoyad.Location = new System.Drawing.Point(64, 38);
            this.textBoxSoyad.Name = "textBoxSoyad";
            this.textBoxSoyad.Size = new System.Drawing.Size(165, 20);
            this.textBoxSoyad.TabIndex = 1;
            // 
            // comboBoxRenkSoyad
            // 
            this.comboBoxRenkSoyad.FormattingEnabled = true;
            this.comboBoxRenkSoyad.Location = new System.Drawing.Point(235, 37);
            this.comboBoxRenkSoyad.Name = "comboBoxRenkSoyad";
            this.comboBoxRenkSoyad.Size = new System.Drawing.Size(128, 21);
            this.comboBoxRenkSoyad.TabIndex = 2;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(18, 66);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(43, 13);
            this.label3.TabIndex = 0;
            this.label3.Text = "Telefon";
            // 
            // textBoxTelefon
            // 
            this.textBoxTelefon.Location = new System.Drawing.Point(64, 64);
            this.textBoxTelefon.Name = "textBoxTelefon";
            this.textBoxTelefon.Size = new System.Drawing.Size(165, 20);
            this.textBoxTelefon.TabIndex = 1;
            // 
            // comboBoxRenkTelefon
            // 
            this.comboBoxRenkTelefon.FormattingEnabled = true;
            this.comboBoxRenkTelefon.Location = new System.Drawing.Point(235, 63);
            this.comboBoxRenkTelefon.Name = "comboBoxRenkTelefon";
            this.comboBoxRenkTelefon.Size = new System.Drawing.Size(128, 21);
            this.comboBoxRenkTelefon.TabIndex = 2;
            // 
            // KayitEkleForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(380, 150);
            this.Controls.Add(this.buttonKayitEkle);
            this.Controls.Add(this.comboBoxRenkTelefon);
            this.Controls.Add(this.comboBoxRenkSoyad);
            this.Controls.Add(this.comboBoxRenkAd);
            this.Controls.Add(this.textBoxTelefon);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.textBoxSoyad);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.textBoxAd);
            this.Controls.Add(this.label1);
            this.Name = "KayitEkleForm";
            this.Text = "KayitEkleForm";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBoxAd;
        private System.Windows.Forms.ComboBox comboBoxRenkAd;
        private System.Windows.Forms.Button buttonKayitEkle;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBoxSoyad;
        private System.Windows.Forms.ComboBox comboBoxRenkSoyad;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textBoxTelefon;
        private System.Windows.Forms.ComboBox comboBoxRenkTelefon;
    }
}