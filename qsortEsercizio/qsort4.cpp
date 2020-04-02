#include <iostream>  // serve per includere le definizioni della libreria
#include <cstring>
#include <cstdio>
#include "qsort_lib.cpp"

using namespace std;
// g++ qsort3.cpp                  --->>> genera a.out come eseguibile
// g++ qsort3.cpp -o qsort3.out   --->>> genera qsort3.out come eseguibile
// ./qsorttest
// bubble sort
struct struttura
  {
      int cilindrata , potenza ;
      char modello[100];
      int lunghezza;
      char colore[30];
  };
// cilindrata -> potenza -> modello
int compara_1(struttura &a, struttura &b)
  { // ret: 0 se uguali. -1 se a<b   +1 se a> b
   int c;
    c=a.cilindrata-b.cilindrata;
   if (c>0) return 1;
   if (c<0) return -1;
    c=a.potenza-b.potenza;
   if (c>0) return 1;
   if (c<0) return -1;
   c=strcmp(a.modello,b.modello); // <=> -> -1 0 1 
   if (c!=0 ) return c;
   return 0;    
  }

// lunghezza ->  potenza -> modello
int compara_2(struttura &a, struttura &b)
  { // ret: 0 se uguali. -1 se a<b   +1 se a> b
   int c;
    c=a.lunghezza-b.lunghezza;
   if (c>0) return 1;
   if (c<0) return -1;
    c=a.potenza-b.potenza;
   if (c>0) return 1;
   if (c<0) return -1;
   c=strcmp(a.modello,b.modello); // <=> -> -1 0 1 
   if (c!=0 ) return c;
   return 0;    
  }  

void stampa_struttura(struttura dati[], int ini , int fin)
  {
  for (int i=0;i<=fin;i++)
    {
        //cout << setw(12);
    if (i>=ini)   
      cout<< dati[i].modello <<" "<<dati[i].cilindrata<<" "<<
        dati[i].potenza<<" "<< dati[i].lunghezza<<"  " ;
       else cout<< "";
    }
  cout << endl;
  } 

struttura a1={1400,75,"panda",345,"pesce"};
struttura a2={1300,75,"rpanda",346,"giallo"};
struttura a3={1200,55,"apanda",343,"blu"};
struttura a4={1800,95,"vpanda",342,"pesce"};
struttura a5={2400,175,"wpanda",445,"giallo"};
struttura a6={5400,375,"panda",1345,"pesce"};
struttura a7={ 400,175,"bpanda",545,"rosso"};
struttura a8={1250,25,"bpanda",245,"giallo"};





// bubble sort
#define N 10000000
using namespace std;  // permette di usare gli oggetti e le funzioni 


int main()
  {
  //double numero=35;
  struttura  lista[]={a1,a2,a3,a4,a5,a6,a7};
  stampa_struttura(lista,0, 5 );
  qsort (lista, 0,sizeof(lista) / sizeof(lista[0]) -1 ,compara_2 ); // dim dell'array
 
  stampa_struttura(lista,0, 5 );
  for (int o=0 ; o<10000000 ; o++) 
    ricerca_binaria( lista, sizeof(lista) / sizeof(lista[0]) ,a3,compara_1) ;
  printf("la scheda  e' in posizione %d\n" ,
    ricerca_binaria( lista, sizeof(lista) / sizeof(lista[0]) ,a3,compara_1)) ; ; 
  
  }
  


 
