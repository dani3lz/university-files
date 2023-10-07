using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp
{
     public partial class Form1 : Form
     {
          int timeleft = 60;
          int quiz, punct, nota;
          public Form1()
          {
               InitializeComponent();
               label1.Visible = false;
               prevb.Visible = false;
               nextb.Visible = false;
               finishb.Visible = false;
               startb.Visible = true;
               labelinfo.Visible = true;
               buttonagain.Visible = false;
               chart1.Visible = false;
               chart1.Series["Raspuns"].IsVisibleInLegend = false;
               chart1.ChartAreas[0].BackColor = Color.Transparent;
          }

          private void label1_Click(object sender, EventArgs e)
          {

          }

          private void timer1_Tick(object sender, EventArgs e)
          {
               if (timeleft > 0)
               {
                    timeleft = timeleft - 1;
                    label1.Text = "Timpul: " + Convert.ToString(timeleft) + " secunde";
               }
               else
               {
                    timer1.Stop();
               }
          }

          private void label_Click(object sender, EventArgs e)
          {

          }

          private void Form1_Load(object sender, EventArgs e)
          {

          }

          private void startb_Click(object sender, EventArgs e)
          {
               radioButton1.Checked = false;
               radioButton2.Checked = false;
               radioButton3.Checked = false;

               checkBox1.Checked = false;
               checkBox2.Checked = false;
               checkBox3.Checked = false;
               checkBox4.Checked = false;
               checkBox5.Checked = false;
               checkBox6.Checked = false;

               numericUpDown1.Value = 0;
               numericUpDown2.Value = 0;

               label1.Location = new Point(12, 9);
               punct = 0;
               timeleft = 60;
               label1.Text = "Timpul: 60 secunde";
               label1.Visible = true;
               labelinfo.Visible = false;
               timer1.Start();
               startb.Visible = false;
               nextb.Visible = true;
               labelex1.Visible = true;
               radioButton1.Visible = true;
               radioButton2.Visible = true;
               radioButton3.Visible = true;
               quiz = 1;
          }

          private void nextb_Click(object sender, EventArgs e)
          {
               if (quiz == 1)
               {
                    quiz++;
                    prevb.Visible = true;
                    labelex1.Visible = false;
                    radioButton1.Visible = false;
                    radioButton2.Visible = false;
                    radioButton3.Visible = false;

                    label2.Visible = true;
                    checkBox1.Visible = true;
                    checkBox2.Visible = true;
                    checkBox3.Visible = true;
                    checkBox4.Visible = true;
                    checkBox5.Visible = true;
                    checkBox6.Visible = true;
               }
               else
               {
                    if (quiz == 2)
                    {
                         quiz++;
                         label2.Visible = false;
                         checkBox1.Visible = false;
                         checkBox2.Visible = false;
                         checkBox3.Visible = false;
                         checkBox4.Visible = false;
                         checkBox5.Visible = false;
                         checkBox6.Visible = false;

                         labelex3.Visible = true;
                         labelex31.Visible = true;
                         labelex32.Visible = true;
                         numericUpDown1.Visible = true;
                         numericUpDown2.Visible = true;

                         nextb.Visible = false;
                         finishb.Visible = true;
                    }
               }
               
          }

          private void buttonagain_Click(object sender, EventArgs e)
          {
               startb.Visible = true;
               labelinfo.Visible = true;
               buttonagain.Visible = false;
               labelnota.Visible = false;
               labeltrue.Visible = false;
               labelfalse.Visible = false;
               label1.Visible = false;
               chart1.Visible = false;
               chart1.Series[0].Points.Clear();
          }

          private void prevb_Click(object sender, EventArgs e)
          {
               if(quiz == 2)
               {
                    quiz--;
                    prevb.Visible = false;
                    labelex1.Visible = true;
                    radioButton1.Visible = true;
                    radioButton2.Visible = true;
                    radioButton3.Visible = true;
                    
                    label2.Visible = false;
                    checkBox1.Visible = false;
                    checkBox2.Visible = false;
                    checkBox3.Visible = false;
                    checkBox4.Visible = false;
                    checkBox5.Visible = false;
                    checkBox6.Visible = false;
               }
               else
               {
                    if(quiz == 3)
                    {
                         quiz--;
                         labelex3.Visible = false;
                         labelex31.Visible = false;
                         labelex32.Visible = false;
                         numericUpDown1.Visible = false;
                         numericUpDown2.Visible = false;

                         label2.Visible = true;
                         checkBox1.Visible = true;
                         checkBox2.Visible = true;
                         checkBox3.Visible = true;
                         checkBox4.Visible = true;
                         checkBox5.Visible = true;
                         checkBox6.Visible = true;

                         nextb.Visible = true;
                         finishb.Visible = false;
                    }
               }
          }

          private void finishb_Click(object sender, EventArgs e)
          {
               timer1.Stop();

               if (radioButton3.Checked) punct++;
               if (checkBox2.Checked) punct++;
               if (checkBox4.Checked) punct++;
               if (numericUpDown1.Value == 1) punct++;
               if (numericUpDown2.Value == 1) punct++;

               labelex3.Visible = false;
               labelex31.Visible = false;
               labelex32.Visible = false;
               numericUpDown1.Visible = false;
               numericUpDown2.Visible = false;

               chart1.Series["Raspuns"].Points.AddXY("Corecte", punct);
               chart1.Series["Raspuns"].Points[0].Color = Color.Green;
               chart1.Series["Raspuns"].Points.AddXY("Gresite", 5 - punct);
               chart1.Series["Raspuns"].Points[1].Color = Color.Red;
               chart1.Visible = true;

               prevb.Visible = false;
               finishb.Visible = false;

               label1.Location = new Point(116, 216);
               label1.Text = "Timpul ramas: " + Convert.ToString(timeleft) + " secunde";

               nota = punct * 2;
               labelnota.Visible = true;
               labeltrue.Visible = true;
               labelfalse.Visible = true;
               labelnota.Text = "Nota: " + Convert.ToString(nota);
               labeltrue.Text = "Corecte: " + Convert.ToString(punct);
               labelfalse.Text = "Gresite: " + Convert.ToString(5 - punct);

               buttonagain.Visible = true;
          }
     }
}
