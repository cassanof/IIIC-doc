// Federico Cassano 3c qsort5
// Struttura stelle

#include <iostream>  // serve per includere le definizioni della libreria
#include <cstring>
#include <cstdio>
// QUI INCLUDO IL CODICE PER IL QSORT E LA RICERCA BINARIA
#include "qsort_lib.cpp"  

using namespace std;

// QUI INSERISCO I CAMPI DELLA MIA NUOVA STRUTTURA
struct struttura
  {                        // STRUTTURA PER LE STELLE
  double distanza;
  double magnitudo;  // numero che indica la brillantezza apparente
  char nome[100];
  char costellazione [100];
  char colore[30];
  };
// http://www.astrofiliastrumcaeli.it/STELLE/luminosita-distanza.php
struttura a1={0.000016,-26.73,"Sole","Solare","G2V"};
struttura a2={25,0.03,"Alpha Lyrae","Lira","A0V"};
struttura a3={360,2.10,"Gamma Andromedae","Andromeda","K3II+B8V+A0V"};
struttura a4={84, 2.43,"Eta Ophiuchi","Ofiuco","A1V+A3V"};
struttura a5={4,-0.29,"Alpha Centauri","Centauro","G2V+K1V"};
struttura a6={75,2.22,"Alpha Coronae Borealis","Corona Boreale","A0V+G5V"};
struttura a7={11,0.36,"Alpha Canis Minoris","Cane Minore","F5IV-V"};
struttura a8={420,1.92,"Alpha Trianguli Australis","Triangolo Australe","K2Ib-II"};


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

// ordino per NOME + COLORE DISTANZA + magnitudo decrescente 
int compara_3(struttura &a, struttura &b)
  {
      double c;  // variabile temporanea per il confronto
      c=strcmp(a.nome,b.nome); // <=> -> -1 0 1
      if (c!=0 ) return c;
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

// ordino per COLORE +  DISTANZA + NOME + magnitudo (non decrescente suppongo?)
int compara_4(struttura &a, struttura &b)
  {
      double c;  // variabile temporanea per il confronto
      c=strcmp(a.colore,b.colore); // <=> -> -1 0 1
      if (c!=0 ) return c;
      c=a.distanza-b.distanza;  // stessa magnitudo: confronto la distanza
      if (c>0) return 1;
      if (c<0) return -1;
      c=strcmp(a.nome,b.nome); // <=> -> -1 0 1
      if (c!=0 ) return c;
      c=a.magnitudo-b.magnitudo;  //  magnitudo in ordine crescente?
      if (c>0) return 1; // la prima e' maggiore della seconda -> return +1
      if (c<0) return -1;
      return 0;
  }
  
void stampa_struttura(struttura dati[], int ini , int fin)
  {
  for (int i=0;i<=fin;i++)
    {
    if (i>=ini)   
      cout<< "- "<< dati[i].nome << " (" << dati[i].costellazione <<") Colore{"
      <<dati[i].colore<<"} Magnitudo{"<< dati[i].magnitudo<<"} Distanza{"<< dati[i].distanza<<"}  \n" ;
    else cout<< "";
    }
  cout << endl;
  }

int main()
  {
  //double numero=35;
  struttura  lista[]={a1,a2,a3,a4,a5,a6,a7,a8};
  printf("Struttura non ordinata:\n");
  stampa_struttura(lista,0, 7 );
  printf("Struttura ordinata:\n");
  qsort (lista, 0,sizeof(lista) / sizeof(lista[0]) -1 ,compara_4 ); // dim dell'array
 
  stampa_struttura(lista,0, 7 );
  for (int o=0 ; o<10000000 ; o++) 
    ricerca_binaria( lista, sizeof(lista) / sizeof(lista[0]) ,a3,compara_1) ;
  printf("la scheda %s e' in posizione %d\n" ,
         a3.nome,ricerca_binaria( lista, sizeof(lista) / sizeof(lista[0]) ,a3,compara_2));
  }
  


 
