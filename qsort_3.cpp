#include <iostream>  // serve per includere le definizioni della libreria
#include <cmath>
#include <cstring>
#include <iomanip>
#include "qsort_lib.cpp"

using namespace std;

struct anagrafica
  {
  int eta;
  char cognome[20];
  char nome[20];
   };

int compara_angrafica1(anagrafica & a, anagrafica &b)
  {
  int c;    
  c=strcmp(a.cognome,b.cognome );
  if (c!=0 ) return c; // cognomi diversti
  c=strcmp(a.nome,b.nome );
  if (c!=0 ) return c; // nomi diversi
  if (a.eta-b.eta > 0) return 1;
  if (a.eta-b.eta < 0) return -1;
  return 0;
  //return a.eta-b.eta;

  }
int compara_angrafica2(anagrafica & a, anagrafica &b)
  {
  int c;    
  if (a.eta-b.eta > 0) return 1;
  if (a.eta-b.eta < 0) return -1;
  c=strcmp(a.cognome,b.cognome );
  if (c!=0 ) return c; // cognomi diversti
  c=strcmp(a.nome,b.nome );
 
  return c;

  }

void stampa(anagrafica dati[], int ini , int fin)
  {
  for (int i=0;i<=fin;i++)
    {
    cout << setw(25);
    if (i>=ini)   
       cout<< dati[i].cognome<<" "<< dati[i].nome <<" "<<dati[i].eta <<", "; 
    else cout<< "";
    }
  cout << endl;
  } 


anagrafica a1={12,"Rossi","qMario"};
anagrafica a2={22,"Verrdi","Mario"};
anagrafica a3={32,"GialliRossi","Mario"};
anagrafica a4={12,"RosiniRossi","wMario"};
anagrafica a5={4,"Lunghi","rMario"};
anagrafica a6={0x42,"BluRossi","Acqario"};

int main()
  {
  anagrafica  lista[]={a1,a2,a3,a4,a5,a6 };
  // dim array :  dimensione in bytes dell'array / dimensione dell'elemento
  qsort (lista, 0,sizeof(lista) / sizeof(lista[0]) -1 , compara_angrafica2); // dim dell'array
  stampa(lista,0,sizeof(lista) / sizeof(lista[0] ) -1 );
   for (int o=0 ; o<1000000 ; o++) 
    ricerca_binaria( lista, sizeof(lista) / sizeof(lista[0]) ,a3,compara_angrafica1) ;
  printf("la scheda  e' in posizione %d\n" ,
    ricerca_binaria( lista, sizeof(lista) / sizeof(lista[0]) ,a3,compara_angrafica1)) ; ; 
  }
