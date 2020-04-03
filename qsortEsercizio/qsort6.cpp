// Federico Cassano 3c qsort6
// Struttura alimenti

#include <iostream>  // serve per includere le definizioni della libreria
#include <cstring>
#include <cstdio>
// QUI INCLUDO IL CODICE PER IL QSORT E LA RICERCA BINARIA
#include "qsort_lib.cpp"  

using namespace std;

// QUI INSERISCO I CAMPI DELLA MIA NUOVA STRUTTURA
struct struttura
  {                        // STRUTTURA PER GLI ALIMENTI
   char nome[100];
   char alimento[100];
   int kcal;
   double proteine;
   double lipidi;
   double glucidiDisponibili;
  };
// https://lifesalute.blogspot.com/2014/09/valori-tabelle-nutrizionali.html
struttura a1={"Kiwi", "Frutta Fresca",44,1.2,0.6,9.0};
struttura a2={"Pinoli Secchi", "Frutta Secca", 567, 29.6, 47.8, 5.0};
struttura a3={"Birra chiara", "Bevande Alcooliche", 34, 0.2, 0, 3.5};
struttura a4={"Polpo", "Pescato", 57, 10.6, 1.0, 1.4};
struttura a5={"Cicoria", "Verdura", 10, 1.4, 0.2, 0.7};
struttura a6={"Fagiolini", "Legumi", 17, 2.1, 0.1, 2.4};
struttura a7={"Yogurt", "Latticini", 63, 3.5, 3.9, 3.6};
struttura a8={"Cannoli alla crema", "Dolci", 369, 6.2, 20.7, 42.2};


// ordine per proteine, lipidi
int compara_prot_lip(struttura &a, struttura &b)
  {
   double c;
   c=a.proteine-b.proteine;
   if (c>0) return 1;
   if (c<0) return -1;
   c=a.lipidi-b.lipidi;
   if (c>0) return 1;
   if (c<0) return -1;
   return 0;    
  }

// ordine per kcal, lipidi
int compara_kcal_lip(struttura &a, struttura &b)
  {
      double c;
      c=a.kcal-b.kcal;
      if (c>0) return 1;
      if (c<0) return -1;
      c=a.lipidi-b.lipidi;
      if (c>0) return 1;
      if (c<0) return -1;
      return 0;
  }

// ordine per nome, kcal (creata per sfizio :D)
int compara_nome_kcal(struttura &a, struttura &b)
{
    double c;
    c=strcmp(a.nome,b.nome);
    if (c!=0 ) return c;
    c=a.kcal-b.kcal;
    if (c>0) return 1;
    if (c<0) return -1;
    return 0;
}
  
void stampa_struttura(struttura dati[], int ini , int fin)
  {
  for (int i=0;i<=fin;i++)
    {
    if (i>=ini)
        cout<< "- "<< dati[i].nome << " (" << dati[i].alimento <<") Kcal{"
            <<dati[i].kcal<<"} Proteine{"<< dati[i].proteine<<"} Lipidi{"
            << dati[i].lipidi<<"} GlucidiDisp{"<< dati[i].glucidiDisponibili <<"}  \n" ;
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
  struttura  lista[]={a1,a2,a3,a4,a5,a6,a7,a8};
  printf("Struttura non ordinata:\n");
  stampa_struttura(lista,0, 7 );
  printf("Struttura ordinata:\n");
  qsort (lista, 0,sizeof(lista) / sizeof(lista[0]) -1 ,compara_kcal_lip); // dim dell'array
 
  stampa_struttura(lista,0, 7 );
  for (int o=0 ; o<10000000 ; o++) 
    ricerca_binaria( lista, sizeof(lista) / sizeof(lista[0]) ,a3,compara_prot_lip) ;
  printf("la scheda %s e' in posizione %d\n" ,
         a3.nome,ricerca_binaria( lista, sizeof(lista) / sizeof(lista[0]) ,a3,compara_kcal_lip));
  }
  


 
