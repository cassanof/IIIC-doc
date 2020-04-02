#include <iostream>  // serve per includere le definizioni della libreria
#include <cmath>
#include <cstring>
#include <iomanip>
using namespace std;
// bubble sort
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
    if (i>=ini)   cout<< dati[i].cognome<<dati[i].eta ; else cout<< "";
    }
  cout << endl;
  } 



using namespace std;  // permette di usare gli oggetti e le funzioni 

template <class X>
void qsort(X * array , int ini , int fin,int (*cmp)(X& ,X &));// dichiarazione: e' prima di main
template <class X>  
void stampa(X dati[], int ini , int fin);

template <class X>  
int compara_numeri(X & a,X & b) // ><=0 a segìconda che a>b a>b a==b
 {if (a-b > 0) return 1;
  if (a-b < 0) return -1;
  return 0;
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
  
  }
template <class X>  
void stampa(X dati[], int ini , int fin)
  {
  for (int i=0;i<=fin;i++)
    {
    cout << setw(6);
    if (i>=ini)   cout<< dati[i]; else cout<< "";
    }
  cout << endl;
  }  

template <class X>
void qsort(X * array , int ini , int fin,int (*cmp)(X& ,X &))
  {
  X pivot; X temp;
  int temp_ini,temp_fin;
  temp_ini=ini;temp_fin=fin;
  pivot= array[ (temp_ini+temp_fin) /2 ] ; // valore a meta'
  //printf("pivot: %d  ini: %d  fin: %d\n",pivot,temp_ini,temp_fin);
  stampa(array,ini,fin) ; 
  while (temp_ini <= temp_fin)
    {
    while (cmp( array[temp_ini] , pivot)<0   && temp_ini < fin )   // array[temp_ini] < pivot 
      temp_ini++;
    while (cmp( pivot , array[temp_fin])<0   && temp_fin >ini  )
      temp_fin--;
    if (temp_ini <= temp_fin)
      {
      temp=array[temp_ini];
      array[temp_ini]=array[temp_fin];
      array[temp_fin]=temp;
      temp_ini++;
      temp_fin--;
      }
      
    }
    stampa(array,ini,fin) ; 
    //printf("%5d %5d\n",temp_ini,temp_fin);
    //return;
    printf("   blocco1: %d-%d  blocco2: %d-%d\n",ini,temp_fin,temp_ini,fin);
    //if (temp_fin<temp_ini) 
    if (ini < temp_fin ) qsort(array,ini,temp_fin,cmp);  
    if (temp_ini < fin ) qsort(array,temp_ini,fin,cmp);  
    //stampa(array,ini,fin) ; 
    }
      
      
