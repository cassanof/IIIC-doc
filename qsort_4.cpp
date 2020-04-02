#include <iostream>  // serve per includere le definizioni della libreria
#include <cmath>
#include <cstring>
#include <iomanip>
#include "qsort_lib.cpp"

using namespace std;

struct autoveicolo
  {
  int cilindrata;
  char modello[40];
  int potenza;
  int lunghezza;
  int costo;
   };

int compara_autoveicolo(autoveicolo & a, autoveicolo &b)
  {
  int c;  
  if (a.potenza < b.potenza)   return -1;
  if (a.potenza > b.potenza)   return 1;
  if (a.cilindrata < b.cilindrata)   return -1;
  if (a.cilindrata > b.cilindrata)   return 1;

  c=strcmp(a.modello,b.modello );
  return c;

  }


int compara_autoveicolo1(autoveicolo & a, autoveicolo &b)
  {
  int c;  
  if (a.lunghezza < b.lunghezza)   return -1;
  if (a.lunghezza > b.lunghezza)   return 1;
  c=strcmp(a.modello,b.modello );
  if (c!=0) return c;

  if (a.cilindrata < b.cilindrata)   return -1;
  if (a.cilindrata > b.cilindrata)   return 1;
  return 0;

  }



void stampa(autoveicolo dati[], int ini , int fin)
  {
  for (int i=0;i<=fin;i++)
    {
    cout << setw(25);
    if (i>=ini)   
       cout<< dati[i].modello<<" "<< dati[i].potenza <<" "<<dati[i].lunghezza <<", "; 
    else cout<< "";
    }
  cout << endl;
  } 


autoveicolo a1={1600,"FPanda",45,355,13000};
autoveicolo a2={1400,"Panda",55,445,13000};
autoveicolo a3={2600,"XPanda",45,445,13000};
autoveicolo a4={600,"RPanda",45,375,13000};
autoveicolo a5={1600,"Panda",25,343,13000};
autoveicolo a6={1200,"Panda",45,346,12000};

int main()
  {
  autoveicolo  lista[]={a1,a2,a3,a4,a5,a6 };
  // dim array :  dimensione in bytes dell'array / dimensione dell'elemento
  qsort (lista, 0,sizeof(lista) / sizeof(lista[0]) -1 , compara_autoveicolo1); // dim dell'array
  stampa(lista,0,sizeof(lista) / sizeof(lista[0] ) -1 );
   for (int o=0 ; o<100000000 ; o++) 
    ricerca_binaria( lista, sizeof(lista) / sizeof(lista[0]) ,a3,compara_autoveicolo) ;
  printf("la scheda  e' in posizione %d\n" ,
    ricerca_binaria( lista, sizeof(lista) / sizeof(lista[0]) ,a3,compara_autoveicolo)) ; ; 
  }
