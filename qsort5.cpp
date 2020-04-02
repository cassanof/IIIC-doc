#include <iostream>  // serve per includere le definizioni della libreria
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdio>
// QUI INCLUDO IL CODICE PER IL QSORT E LA RICERCA BINARIA
#include "qsort_lib.cpp"  

using namespace std;
// PER COMPILARE E USARE SOTTO SHELL :
// A SCELTA UNA DELLE SEGUENTI PER COMPILARE
// g++ qsort5.cpp                  --->>> genera a.out come eseguibile
// g++ qsort5.cpp -o qsort5.out    --->>> genera qsort5.out come eseguibile
// A SCELTA UNA DELLE SEGUENTI PER ESEGUIRE
//  ./a.out
//  ./qsort5


// QUI INSERISCO I CAMPI DELLA MIA NUOVA STRUTTURA
struct struttura
  {                        // STRUTTURA PER LE STELLE
  double  distanza;
  double  magnitudo;  // numero che indica la brillantezza apparente
  char nome[100];
  char costellazione [100];
  char colore[30];
  };
// http://www.astrofiliastrumcaeli.it/STELLE/luminosita-distanza.php
struttura a1={   8.6,   4.8,     "Alpha Carinae",   "Carena","G2V"};
struttura a2={    25  ,0.58,     "Alpha Lyrae",     "Lira",  "A0V"};
struttura a3={};
struttura a4={};
struttura a5={};
struttura a6={};
struttura a7={};
struttura a8={};


// ordine per magnitudo + distanza
int compara_1(struttura &a, struttura &b)
  { // ret: 0 se uguali. -1 se a<b   +1 se a> b
   double c;  // variabile temporanea per il confronto
   c=a.magnitudo-b.magnitudo;  
   if (c>0) return 1; // la prima e' maggiore della seconda -> return +1
   if (c<0) return -1;
   c=a.distanza-b.distanza;  // stessa magnitudo: confronto la distanza
   if (c>0) return 1;
   if (c<0) return -1;
   return 0;    
  }

// ordino per colore + magnitudo decrescente + distanza
int compara_2(struttura &a, struttura &b)
  { // ret: 0 se uguali. -1 se a<b   +1 se a> b
   double c;  // variabile temporanea per il confronto
   c=strcmp(a.colore,b.colore); // <=> -> -1 0 1 
   if (c!=0 ) return c;
   c= - (  a.magnitudo-b.magnitudo  );  //  MAGNITUDO IN ORDINE DECRESCENTE !!!!!  
   if (c>0) return 1; // la prima e' maggiore della seconda -> return +1
   if (c<0) return -1;
   c=a.distanza-b.distanza;  // stessa magnitudo: confronto la distanza
   if (c>0) return 1;
   if (c<0) return -1;
   return 0;      
  }  

// DA FARE  DA FARE  DA FARE  DA FARE  DA FARE  DA FARE  DA FARE  
// ordino per NOME + COLORE DISTANZA + magnitudo decrescente 
int compara_3(struttura &a, struttura &b)
  {
  return 0    ;
  }

// DA FARE  DA FARE  DA FARE  DA FARE  DA FARE  DA FARE  DA FARE  
// ordino per COLORE +  DISTANZA + NOME + magnitudo 
int compara_4(struttura &a, struttura &b)
  {
  return 0    ;
  }
  
  
  
void stampa_struttura(struttura dati[], int ini , int fin)
  {
  for (int i=0;i<=fin;i++)
    {
        //cout << setw(12);
    if (i>=ini)   
      cout<< dati[i].nome <<" "<<dati[i].colore<<" "<<
        dati[i].magnitudo<<" "<< dati[i].distanza<<"  " ;
       else cout<< "";
    }
  cout << endl;
  } 



// indice per cilindrata
// 6 2 7 1 0 3 4 5  --> indice[]
//lista [i]   i 0..7

//lista [ indice [i] ]   i 0..7

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
  


 
