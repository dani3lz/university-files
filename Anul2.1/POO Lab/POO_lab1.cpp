#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Jocuri{
public:
  string denumire;
  int pret;
};

struct DVD{
private:
	string denumire[5];
  	int pret[5];
  	int n;
  	
public:	
DVD(){
  for(int i=0; i<5; i++)
  	pret[i]=0;
  n=0;
}

int Suma(){
	cout << endl;
    int sum=0;
    for(int i=0;i<n;i++)
    	sum+=pret[i];
    return sum;
}

void Adauga(Jocuri* x){
    for(int i=0;i<3;i++){
    	if(n==5){
      		cout << "\nDVD-ul este plin!" << endl;
      		break;
		  }
      denumire[i] = (*x).denumire;
      pret[i] = (*x).pret;
      x++;
      n++;
    }
}

void Elimina(string x){
    for(int i=0;i<n;i++){
      if(denumire[i].find(x) != string::npos){
        for(int j=i;j<n;j++){
        	denumire[j]=denumire[j+1];
        	pret[j]=pret[j+1];
		    }
		  n--;
      break;
      }
    }
}

void Import(const string &file_name){
    ifstream file;
    file.open(file_name.c_str());
    if(file.is_open()){
      string str;
      int nr=0;
      while(!file.eof()){
      	if(n==5){
      		cout << "\nDVD-ul este plin!" << endl;
      		break;
		  }
          str="";
          file >> str;
          if(str!=""){
            nr++;
            if(nr==1){
              denumire[n]=str;
            }
            if(nr==2){
              istringstream(str) >> pret[n];
              n++;
              nr=0;
            }
          }
      }
      file.close();
    }
    else{
      cout << "File-ul nu a putut fi deschis!" << endl;
    }
  }
};

int main()
{
  DVD dvd;
  Jocuri *jocuri = new Jocuri[3];
  jocuri[0].denumire = "GTA";
  jocuri[0].pret = 200;
  jocuri[1].denumire = "OVC";
  jocuri[1].pret = 100;
  jocuri[2].denumire = "WW2";
  jocuri[2].pret = 150;
  dvd.Adauga(jocuri);
  cout << dvd.Suma();
  dvd.Elimina("WW2");
  cout << dvd.Suma();
  dvd.Import("jocuri.txt");
  cout << dvd.Suma();
  
  return 0;
}