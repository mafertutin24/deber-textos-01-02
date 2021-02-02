#include <iostream>
#include <fstream>
using namespace std;

void registro(string n);
void lectura(string m);

int main(){
  string nombrearchivo;
  int op;
  cout<<"Ingrese el nombre del archivo: ";
  getline(cin,nombrearchivo);
  do{
   cout<<"***********************************"<<endl;
   cout<<" || "<<nombrearchivo<<" || "<<endl;
   cout<<"1.Registro"<<endl;
   cout<<"2.Ver registro"<<endl;
   cout<<"3.salir"<<endl;
   cout<<"Escoga una opcion: ";
   cin>>op;
   while(getchar()!='\n');   
   switch (op){
     case 1: {
       cout<<"- - - - - - - - - - - - - - - - - -"<<endl;
       cout<<"REGISTRO"<<endl;
       registro(nombrearchivo);
       break;
     }
     case 2: {
       cout<<"- - - - - - - - - - - - - - - - - -"<<endl;
       cout<<"VER REGISTRO"<<endl;
       lectura(nombrearchivo);
       break;
     }
    } 
  }while (op!=3);
}

void registro(string n){
  string nombre;
  string apellido;
  string carrera;
  int edad;
  char r;
  ofstream archivoprueba;
  archivoprueba.open(n.c_str(),ios::out);
  do
  {
    cout<<"\t Ingrese el nombre: ";
    getline(cin,nombre); 
    cout<<"\t Ingrese el apellido: ";
    getline(cin,apellido); 
    cout<<"\t Ingrese la edad: ";
    cin>>edad; 
    cout<<"\t Ingrese la carrera: ";
    cin>>carrera;
    archivoprueba<<nombre<<"      "<<apellido<<"      "<<carrera<<"       "<<edad<<endl;
    cout<<"-------------------------------------"<<endl;
    cout<<"Desea ingresar otro contacto s/n ";
    cin>>r;
    cout<<"-------------------------------------"<<endl;
    cin.ignore();
  }
  while(r=='s');
  archivoprueba.close();
}

void lectura(string m)
{
  string nombre;
  string apellido;
  string carrera;
  int edad;
  ifstream archivolectura(m.c_str());
  if(archivolectura.fail()){
   cout<<"El archivo no se pudo leer";
  }
 else{
   while(!archivolectura.eof()){
    archivolectura>>nombre>>apellido>>carrera>>edad;
   if(!archivolectura.eof())
     {
     cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
     cout<<"Nombre: "<<nombre<<endl;
     cout<<"Apellido: "<<apellido<<endl;
     cout<<"Carrera: "<<carrera<<endl;
     cout<<"Edad: "<<edad<<endl;
     }
   }
 }
 archivolectura.close();
}

