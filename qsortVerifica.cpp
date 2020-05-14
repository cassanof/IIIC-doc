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
  int anno;
  char artista[100];
  char titolo [100];
  int vendite;
  };
struttura a1={1985, "Claudio Baglioni","La vita è adesso",4000000};
struttura a2={1972,"Claudio Baglioni","Questo Piccolo Grande Amore",2250000};
struttura a3={1999, "Adriano Celentano", "Io non so parlar d'amore", 2200000};
struttura a4={1998, "Mina e Adriano Celentano", "Mina Celentano", 2000000};
struttura a5={1989, "Zucchero Fornaciari", "Oro, incenso e birra", 2000000};
struttura a6={1981, "Claudio Baglioni", "Strada Facendo", 1800000};
struttura a7={2001, "Adriano Celentano", "Esco di rado e parlo ancora meno", 1800000};
struttura a8={1996, "Eros Ramazzotti", "Dove c'è musica", 1650000};
struttura a9={1986, "Madonna", "True Blue", 1500000};
struttura a10={1987, "Zucchero Fornaciari", "Blue's",1500000};

// Anno + vendite
int compara_1(struttura &a, struttura &b)
  {
   double c;
   c=a.anno-b.anno;
   if (c>0) return 1;
   if (c<0) return -1;
   c=a.vendite-b.vendite;
   if (c>0) return 1;
   if (c<0) return -1;
   return 0;    
  }

// anno + titolo
int compara_2(struttura &a, struttura &b)
  { // ret: 0 se uguali. -1 se a<b   +1 se a> b
      double c;
      c=a.anno-b.anno;
      if (c>0) return 1;
      if (c<0) return -1;
      c=strcmp(a.titolo,b.titolo);
      if (c!=0 ) return c;
      return 0;
  }

// artista + titolo
int compara_3(struttura &a, struttura &b)
  {
      double c;
      c=strcmp(a.artista,b.artista);
      if (c!=0 ) return c;
      c=strcmp(a.titolo,b.titolo);
      if (c!=0 ) return c;
      return 0;
  }

// anno(decrescente) + titolo
int compara_4(struttura &a, struttura &b)
  {
      double c;
      c=-(a.anno-b.anno);
      if (c>0) return 1;
      if (c<0) return -1;
      c=strcmp(a.titolo,b.titolo);
      if (c!=0 ) return c;
      return 0;
  }
  
void stampa_struttura(struttura dati[], int ini , int fin)
  {
  for (int i=0;i<=fin;i++)
    {
    if (i>=ini)   
      cout<< "- "<< dati[i].anno << " (" << dati[i].artista <<") Titolo{"
      <<dati[i].titolo<<"} Vendite{"<< dati[i].vendite<<"}\n" ;
    else cout<< "";
    }
  cout << endl;
  }

int main()
  {
  //double numero=35;
  struttura  lista[]={a1,a2,a3,a4,a5,a6,a7,a8,a9,a10};
  printf("Struttura non ordinata:\n");
  stampa_struttura(lista,0, 9 );
  printf("Struttura ordinata:\n");
  qsort (lista, 0,sizeof(lista) / sizeof(lista[0]) -1 ,compara_4 ); // dim dell'array
 
  stampa_struttura(lista,0, 9 );
  for (int o=0 ; o<10000000 ; o++) 
    ricerca_binaria( lista, sizeof(lista) / sizeof(lista[0]) ,a3,compara_1) ;
  printf("la scheda %s e' in posizione %d\n" ,
         a3.titolo,ricerca_binaria( lista, sizeof(lista) / sizeof(lista[0]) ,a3,compara_4));
  }
 
