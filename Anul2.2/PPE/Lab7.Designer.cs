
namespace WindowsFormsApp
{
     partial class Form1
     {
          /// <summary>
          ///  Required designer variable.
          /// </summary>
          private System.ComponentModel.IContainer components = null;

          /// <summary>
          ///  Clean up any resources being used.
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
          ///  Required method for Designer support - do not modify
          ///  the contents of this method with the code editor.
          /// </summary>
          private void InitializeComponent()
          {
               this.components = new System.ComponentModel.Container();
               System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea1 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
               System.Windows.Forms.DataVisualization.Charting.Legend legend1 = new System.Windows.Forms.DataVisualization.Charting.Legend();
               System.Windows.Forms.DataVisualization.Charting.Series series1 = new System.Windows.Forms.DataVisualization.Charting.Series();
               this.timer1 = new System.Windows.Forms.Timer(this.components);
               this.label1 = new System.Windows.Forms.Label();
               this.labelex2 = new System.Windows.Forms.Label();
               this.startb = new System.Windows.Forms.Button();
               this.nextb = new System.Windows.Forms.Button();
               this.prevb = new System.Windows.Forms.Button();
               this.finishb = new System.Windows.Forms.Button();
               this.labelex1 = new System.Windows.Forms.Label();
               this.radioButton1 = new System.Windows.Forms.RadioButton();
               this.radioButton2 = new System.Windows.Forms.RadioButton();
               this.radioButton3 = new System.Windows.Forms.RadioButton();
               this.label2 = new System.Windows.Forms.Label();
               this.checkBox1 = new System.Windows.Forms.CheckBox();
               this.checkBox2 = new System.Windows.Forms.CheckBox();
               this.checkBox3 = new System.Windows.Forms.CheckBox();
               this.checkBox4 = new System.Windows.Forms.CheckBox();
               this.checkBox5 = new System.Windows.Forms.CheckBox();
               this.checkBox6 = new System.Windows.Forms.CheckBox();
               this.labelex3 = new System.Windows.Forms.Label();
               this.labelex31 = new System.Windows.Forms.Label();
               this.labelex32 = new System.Windows.Forms.Label();
               this.numericUpDown1 = new System.Windows.Forms.NumericUpDown();
               this.numericUpDown2 = new System.Windows.Forms.NumericUpDown();
               this.labelinfo = new System.Windows.Forms.Label();
               this.labelnota = new System.Windows.Forms.Label();
               this.labeltrue = new System.Windows.Forms.Label();
               this.labelfalse = new System.Windows.Forms.Label();
               this.buttonagain = new System.Windows.Forms.Button();
               this.chart1 = new System.Windows.Forms.DataVisualization.Charting.Chart();
               ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).BeginInit();
               ((System.ComponentModel.ISupportInitialize)(this.numericUpDown2)).BeginInit();
               ((System.ComponentModel.ISupportInitialize)(this.chart1)).BeginInit();
               this.SuspendLayout();
               // 
               // timer1
               // 
               this.timer1.Interval = 1000;
               this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
               // 
               // label1
               // 
               this.label1.AutoSize = true;
               this.label1.Font = new System.Drawing.Font("Palatino Linotype", 12F);
               this.label1.Location = new System.Drawing.Point(10, 8);
               this.label1.Name = "label1";
               this.label1.Size = new System.Drawing.Size(141, 22);
               this.label1.TabIndex = 0;
               this.label1.Text = "Timpul: 60 secunde";
               this.label1.Visible = false;
               this.label1.Click += new System.EventHandler(this.label1_Click);
               // 
               // labelex2
               // 
               this.labelex2.AutoSize = true;
               this.labelex2.Font = new System.Drawing.Font("Arial Narrow", 12F);
               this.labelex2.Location = new System.Drawing.Point(10, 101);
               this.labelex2.Name = "labelex2";
               this.labelex2.Size = new System.Drawing.Size(0, 20);
               this.labelex2.TabIndex = 6;
               // 
               // startb
               // 
               this.startb.Font = new System.Drawing.Font("Arial Narrow", 27.75F, System.Drawing.FontStyle.Bold);
               this.startb.Location = new System.Drawing.Point(142, 162);
               this.startb.Name = "startb";
               this.startb.Size = new System.Drawing.Size(237, 62);
               this.startb.TabIndex = 15;
               this.startb.Text = "Incepe";
               this.startb.UseVisualStyleBackColor = true;
               this.startb.Click += new System.EventHandler(this.startb_Click);
               // 
               // nextb
               // 
               this.nextb.Font = new System.Drawing.Font("Arial Narrow", 12F);
               this.nextb.Location = new System.Drawing.Point(409, 330);
               this.nextb.Name = "nextb";
               this.nextb.Size = new System.Drawing.Size(107, 29);
               this.nextb.TabIndex = 16;
               this.nextb.Text = "Urmatorul >";
               this.nextb.UseVisualStyleBackColor = true;
               this.nextb.Click += new System.EventHandler(this.nextb_Click);
               // 
               // prevb
               // 
               this.prevb.Font = new System.Drawing.Font("Arial Narrow", 12F);
               this.prevb.Location = new System.Drawing.Point(10, 330);
               this.prevb.Name = "prevb";
               this.prevb.Size = new System.Drawing.Size(110, 29);
               this.prevb.TabIndex = 17;
               this.prevb.Text = "< Precedentul";
               this.prevb.UseVisualStyleBackColor = true;
               this.prevb.Click += new System.EventHandler(this.prevb_Click);
               // 
               // finishb
               // 
               this.finishb.Font = new System.Drawing.Font("Arial Narrow", 15.75F, System.Drawing.FontStyle.Bold);
               this.finishb.Location = new System.Drawing.Point(397, 324);
               this.finishb.Name = "finishb";
               this.finishb.Size = new System.Drawing.Size(119, 36);
               this.finishb.TabIndex = 18;
               this.finishb.Text = "Finish";
               this.finishb.UseVisualStyleBackColor = true;
               this.finishb.Click += new System.EventHandler(this.finishb_Click);
               // 
               // labelex1
               // 
               this.labelex1.AutoSize = true;
               this.labelex1.Font = new System.Drawing.Font("Arial Narrow", 20.25F, System.Drawing.FontStyle.Bold);
               this.labelex1.Location = new System.Drawing.Point(151, 66);
               this.labelex1.Name = "labelex1";
               this.labelex1.Size = new System.Drawing.Size(217, 31);
               this.labelex1.TabIndex = 19;
               this.labelex1.Text = "Legea 1 a lui Ohm?";
               this.labelex1.Visible = false;
               // 
               // radioButton1
               // 
               this.radioButton1.AutoSize = true;
               this.radioButton1.Font = new System.Drawing.Font("Arial Narrow", 18F);
               this.radioButton1.Location = new System.Drawing.Point(40, 162);
               this.radioButton1.Name = "radioButton1";
               this.radioButton1.Size = new System.Drawing.Size(64, 33);
               this.radioButton1.TabIndex = 20;
               this.radioButton1.Text = "R/U";
               this.radioButton1.UseVisualStyleBackColor = true;
               this.radioButton1.Visible = false;
               // 
               // radioButton2
               // 
               this.radioButton2.AutoSize = true;
               this.radioButton2.Font = new System.Drawing.Font("Arial Narrow", 18F);
               this.radioButton2.Location = new System.Drawing.Point(223, 162);
               this.radioButton2.Name = "radioButton2";
               this.radioButton2.Size = new System.Drawing.Size(54, 33);
               this.radioButton2.TabIndex = 21;
               this.radioButton2.Text = "I/U";
               this.radioButton2.UseVisualStyleBackColor = true;
               this.radioButton2.Visible = false;
               // 
               // radioButton3
               // 
               this.radioButton3.AutoSize = true;
               this.radioButton3.Font = new System.Drawing.Font("Arial Narrow", 18F);
               this.radioButton3.Location = new System.Drawing.Point(422, 162);
               this.radioButton3.Name = "radioButton3";
               this.radioButton3.Size = new System.Drawing.Size(54, 33);
               this.radioButton3.TabIndex = 22;
               this.radioButton3.Text = "U/I";
               this.radioButton3.UseVisualStyleBackColor = true;
               this.radioButton3.Visible = false;
               // 
               // label2
               // 
               this.label2.AutoSize = true;
               this.label2.Font = new System.Drawing.Font("Arial Narrow", 20.25F, System.Drawing.FontStyle.Bold);
               this.label2.Location = new System.Drawing.Point(45, 66);
               this.label2.Name = "label2";
               this.label2.Size = new System.Drawing.Size(428, 31);
               this.label2.TabIndex = 23;
               this.label2.Text = "Alegeti elementele din chimie organica:";
               this.label2.Visible = false;
               // 
               // checkBox1
               // 
               this.checkBox1.AutoSize = true;
               this.checkBox1.Font = new System.Drawing.Font("Arial Narrow", 18F);
               this.checkBox1.Location = new System.Drawing.Point(39, 126);
               this.checkBox1.Name = "checkBox1";
               this.checkBox1.Size = new System.Drawing.Size(83, 33);
               this.checkBox1.TabIndex = 24;
               this.checkBox1.Text = "Na2O";
               this.checkBox1.UseVisualStyleBackColor = true;
               this.checkBox1.Visible = false;
               // 
               // checkBox2
               // 
               this.checkBox2.AutoSize = true;
               this.checkBox2.Font = new System.Drawing.Font("Arial Narrow", 18F);
               this.checkBox2.Location = new System.Drawing.Point(223, 126);
               this.checkBox2.Name = "checkBox2";
               this.checkBox2.Size = new System.Drawing.Size(111, 33);
               this.checkBox2.TabIndex = 25;
               this.checkBox2.Text = "C2H5OH";
               this.checkBox2.UseVisualStyleBackColor = true;
               this.checkBox2.Visible = false;
               // 
               // checkBox3
               // 
               this.checkBox3.AutoSize = true;
               this.checkBox3.Font = new System.Drawing.Font("Arial Narrow", 18F);
               this.checkBox3.Location = new System.Drawing.Point(422, 126);
               this.checkBox3.Name = "checkBox3";
               this.checkBox3.Size = new System.Drawing.Size(71, 33);
               this.checkBox3.TabIndex = 26;
               this.checkBox3.Text = "K2O";
               this.checkBox3.UseVisualStyleBackColor = true;
               this.checkBox3.Visible = false;
               // 
               // checkBox4
               // 
               this.checkBox4.AutoSize = true;
               this.checkBox4.Font = new System.Drawing.Font("Arial Narrow", 18F);
               this.checkBox4.Location = new System.Drawing.Point(39, 198);
               this.checkBox4.Name = "checkBox4";
               this.checkBox4.Size = new System.Drawing.Size(82, 33);
               this.checkBox4.TabIndex = 27;
               this.checkBox4.Text = "C6H6";
               this.checkBox4.UseVisualStyleBackColor = true;
               this.checkBox4.Visible = false;
               // 
               // checkBox5
               // 
               this.checkBox5.AutoSize = true;
               this.checkBox5.Font = new System.Drawing.Font("Arial Narrow", 18F);
               this.checkBox5.Location = new System.Drawing.Point(223, 198);
               this.checkBox5.Name = "checkBox5";
               this.checkBox5.Size = new System.Drawing.Size(95, 33);
               this.checkBox5.TabIndex = 28;
               this.checkBox5.Text = "BaSO4";
               this.checkBox5.UseVisualStyleBackColor = true;
               this.checkBox5.Visible = false;
               // 
               // checkBox6
               // 
               this.checkBox6.AutoSize = true;
               this.checkBox6.Font = new System.Drawing.Font("Arial Narrow", 18F);
               this.checkBox6.Location = new System.Drawing.Point(422, 198);
               this.checkBox6.Name = "checkBox6";
               this.checkBox6.Size = new System.Drawing.Size(86, 33);
               this.checkBox6.TabIndex = 29;
               this.checkBox6.Text = "CaCl2";
               this.checkBox6.UseVisualStyleBackColor = true;
               this.checkBox6.Visible = false;
               // 
               // labelex3
               // 
               this.labelex3.AutoSize = true;
               this.labelex3.Font = new System.Drawing.Font("Arial Narrow", 20.25F, System.Drawing.FontStyle.Bold);
               this.labelex3.Location = new System.Drawing.Point(135, 66);
               this.labelex3.Name = "labelex3";
               this.labelex3.Size = new System.Drawing.Size(251, 31);
               this.labelex3.TabIndex = 30;
               this.labelex3.Text = "Cate nuclee are celula:";
               this.labelex3.Visible = false;
               // 
               // labelex31
               // 
               this.labelex31.AutoSize = true;
               this.labelex31.Font = new System.Drawing.Font("Arial Narrow", 20.25F, System.Drawing.FontStyle.Bold);
               this.labelex31.Location = new System.Drawing.Point(106, 123);
               this.labelex31.Name = "labelex31";
               this.labelex31.Size = new System.Drawing.Size(103, 31);
               this.labelex31.TabIndex = 31;
               this.labelex31.Text = "animala:";
               this.labelex31.Visible = false;
               // 
               // labelex32
               // 
               this.labelex32.AutoSize = true;
               this.labelex32.Font = new System.Drawing.Font("Arial Narrow", 20.25F, System.Drawing.FontStyle.Bold);
               this.labelex32.Location = new System.Drawing.Point(106, 196);
               this.labelex32.Name = "labelex32";
               this.labelex32.Size = new System.Drawing.Size(108, 31);
               this.labelex32.TabIndex = 32;
               this.labelex32.Text = "vegetala:";
               this.labelex32.Visible = false;
               // 
               // numericUpDown1
               // 
               this.numericUpDown1.Font = new System.Drawing.Font("Arial Narrow", 14.25F);
               this.numericUpDown1.Location = new System.Drawing.Point(215, 128);
               this.numericUpDown1.Name = "numericUpDown1";
               this.numericUpDown1.Size = new System.Drawing.Size(62, 29);
               this.numericUpDown1.TabIndex = 33;
               this.numericUpDown1.Visible = false;
               // 
               // numericUpDown2
               // 
               this.numericUpDown2.Font = new System.Drawing.Font("Arial Narrow", 14.25F);
               this.numericUpDown2.Location = new System.Drawing.Point(215, 201);
               this.numericUpDown2.Name = "numericUpDown2";
               this.numericUpDown2.Size = new System.Drawing.Size(62, 29);
               this.numericUpDown2.TabIndex = 34;
               this.numericUpDown2.Visible = false;
               // 
               // labelinfo
               // 
               this.labelinfo.AutoSize = true;
               this.labelinfo.Font = new System.Drawing.Font("Arial Narrow", 20.25F, System.Drawing.FontStyle.Bold);
               this.labelinfo.Location = new System.Drawing.Point(127, 227);
               this.labelinfo.Name = "labelinfo";
               this.labelinfo.Size = new System.Drawing.Size(277, 31);
               this.labelinfo.TabIndex = 35;
               this.labelinfo.Text = "Timp la dispozitie: 1 min.";
               // 
               // labelnota
               // 
               this.labelnota.AutoSize = true;
               this.labelnota.Font = new System.Drawing.Font("Arial Narrow", 20.25F, System.Drawing.FontStyle.Bold);
               this.labelnota.Location = new System.Drawing.Point(116, 101);
               this.labelnota.Name = "labelnota";
               this.labelnota.Size = new System.Drawing.Size(76, 31);
               this.labelnota.TabIndex = 36;
               this.labelnota.Text = "Nota: ";
               this.labelnota.Visible = false;
               // 
               // labeltrue
               // 
               this.labeltrue.AutoSize = true;
               this.labeltrue.Font = new System.Drawing.Font("Arial Narrow", 18F, System.Drawing.FontStyle.Bold);
               this.labeltrue.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
               this.labeltrue.Location = new System.Drawing.Point(116, 157);
               this.labeltrue.Name = "labeltrue";
               this.labeltrue.Size = new System.Drawing.Size(87, 29);
               this.labeltrue.TabIndex = 37;
               this.labeltrue.Text = "Corecte";
               this.labeltrue.Visible = false;
               // 
               // labelfalse
               // 
               this.labelfalse.AutoSize = true;
               this.labelfalse.Font = new System.Drawing.Font("Arial Narrow", 18F, System.Drawing.FontStyle.Bold);
               this.labelfalse.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))));
               this.labelfalse.Location = new System.Drawing.Point(116, 182);
               this.labelfalse.Name = "labelfalse";
               this.labelfalse.Size = new System.Drawing.Size(81, 29);
               this.labelfalse.TabIndex = 38;
               this.labelfalse.Text = "Gresite";
               this.labelfalse.Visible = false;
               // 
               // buttonagain
               // 
               this.buttonagain.Font = new System.Drawing.Font("Arial Narrow", 15.75F, System.Drawing.FontStyle.Bold);
               this.buttonagain.Location = new System.Drawing.Point(189, 267);
               this.buttonagain.Name = "buttonagain";
               this.buttonagain.Size = new System.Drawing.Size(118, 38);
               this.buttonagain.TabIndex = 39;
               this.buttonagain.Text = "Din nou?";
               this.buttonagain.UseVisualStyleBackColor = true;
               this.buttonagain.Click += new System.EventHandler(this.buttonagain_Click);
               // 
               // chart1
               // 
               this.chart1.AccessibleName = "chart1";
               this.chart1.BackColor = System.Drawing.Color.Transparent;
               this.chart1.BorderlineColor = System.Drawing.Color.Transparent;
               chartArea1.Name = "ChartArea1";
               this.chart1.ChartAreas.Add(chartArea1);
               legend1.Name = "Legend1";
               this.chart1.Legends.Add(legend1);
               this.chart1.Location = new System.Drawing.Point(300, 8);
               this.chart1.Name = "chart1";
               series1.ChartArea = "ChartArea1";
               series1.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Doughnut;
               series1.Legend = "Legend1";
               series1.Name = "Raspuns";
               this.chart1.Series.Add(series1);
               this.chart1.Size = new System.Drawing.Size(216, 216);
               this.chart1.TabIndex = 40;
               this.chart1.Text = "chart1";
               // 
               // Form1
               // 
               this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
               this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
               this.ClientSize = new System.Drawing.Size(528, 369);
               this.Controls.Add(this.chart1);
               this.Controls.Add(this.buttonagain);
               this.Controls.Add(this.labelfalse);
               this.Controls.Add(this.labeltrue);
               this.Controls.Add(this.labelnota);
               this.Controls.Add(this.labelinfo);
               this.Controls.Add(this.numericUpDown2);
               this.Controls.Add(this.numericUpDown1);
               this.Controls.Add(this.labelex32);
               this.Controls.Add(this.labelex31);
               this.Controls.Add(this.labelex3);
               this.Controls.Add(this.checkBox6);
               this.Controls.Add(this.checkBox5);
               this.Controls.Add(this.checkBox4);
               this.Controls.Add(this.checkBox3);
               this.Controls.Add(this.checkBox2);
               this.Controls.Add(this.checkBox1);
               this.Controls.Add(this.label2);
               this.Controls.Add(this.radioButton3);
               this.Controls.Add(this.radioButton2);
               this.Controls.Add(this.radioButton1);
               this.Controls.Add(this.labelex1);
               this.Controls.Add(this.finishb);
               this.Controls.Add(this.prevb);
               this.Controls.Add(this.nextb);
               this.Controls.Add(this.startb);
               this.Controls.Add(this.labelex2);
               this.Controls.Add(this.label1);
               this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
               this.MaximizeBox = false;
               this.Name = "Form1";
               this.Text = "> Lab 4-5 Zavorot Daniel TI-194";
               ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).EndInit();
               ((System.ComponentModel.ISupportInitialize)(this.numericUpDown2)).EndInit();
               ((System.ComponentModel.ISupportInitialize)(this.chart1)).EndInit();
               this.ResumeLayout(false);
               this.PerformLayout();

          }

          #endregion

          private System.Windows.Forms.Timer timer1;
          private System.Windows.Forms.Label label1;
          private System.Windows.Forms.Label labelex2;
          private System.Windows.Forms.Button startb;
          private System.Windows.Forms.Button nextb;
          private System.Windows.Forms.Button prevb;
          private System.Windows.Forms.Button finishb;
          private System.Windows.Forms.Label labelex1;
          private System.Windows.Forms.RadioButton radioButton1;
          private System.Windows.Forms.RadioButton radioButton2;
          private System.Windows.Forms.RadioButton radioButton3;
          private System.Windows.Forms.Label label2;
          private System.Windows.Forms.CheckBox checkBox1;
          private System.Windows.Forms.CheckBox checkBox2;
          private System.Windows.Forms.CheckBox checkBox3;
          private System.Windows.Forms.CheckBox checkBox4;
          private System.Windows.Forms.CheckBox checkBox5;
          private System.Windows.Forms.CheckBox checkBox6;
          private System.Windows.Forms.Label labelex3;
          private System.Windows.Forms.Label labelex31;
          private System.Windows.Forms.Label labelex32;
          private System.Windows.Forms.NumericUpDown numericUpDown1;
          private System.Windows.Forms.NumericUpDown numericUpDown2;
          private System.Windows.Forms.Label labelinfo;
          private System.Windows.Forms.Label labelnota;
          private System.Windows.Forms.Label labeltrue;
          private System.Windows.Forms.Label labelfalse;
          private System.Windows.Forms.Button buttonagain;
          private System.Windows.Forms.DataVisualization.Charting.Chart chart1;
     }
}

