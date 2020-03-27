#include <iostream>  // serve per includere le definizioni della libreria
#include <cmath>
#include <ctime>
#include <iomanip>
// g++ qsorttest.cpp -o qsorttest
// ./qsorttest
// bubble sort


// bubble sort
#define N 10000000
using namespace std;  // permette di usare gli oggetti e le funzioni 

void qsort(int * array , int ini , int fin); // dichiarazione: e' prima di main
void stampa(int dati[],int ini , int fin);
int ricerca_binaria(int dati[], int dim ,int dato_cercato);
int main()
  {
  int numero=35;
  int  *lista=(int*)malloc(N * sizeof(lista[0]));
  if (!lista) printf("err");
  srand(-time(0)); // inizializzo il generatore random
  // dim array :  dimensione in bytes dell'array / dimensione dell'elemento
   for (int i=0;i<N;i++) lista[i]=rand() ;
  stampa(lista,0, 100 );
  qsort (lista, 0, N -1); // dim dell'array
 
  stampa(lista,0, 100 );
  for (int o=0 ; o<10000000 ; o++) 
    ricerca_binaria( lista, N,numero) ;
  printf("Il numero %d e' in posizione %d\n" ,numero ,
  ricerca_binaria( lista, N,numero) ); 
  
  }
  



  int ricerca_binaria(int dati[], int dim ,int dato_cercato)
  { //ricerca dat_cercato e restituisce la posizione 
    // returns -1 if not found. DATI DEVE ESSERE SORTED (ORDINATO)
  int ini,mid,fin; // indice inizio, meta e fine blocco  
  int valore_mid;
  ini=0 ; fin = dim-1;
  mid=(ini+fin)/2; // divisione intera
  valore_mid=dati[mid];
  while (ini <= fin)
    {
    //printf("%d %d %d  %d\n",ini,mid,fin,valore_mid);
    if (dati[mid]== dato_cercato ) // ho trovato
      return mid;
    if (dati[mid] < dato_cercato )
      ini=mid+1;
    else
      fin=mid-1;
    mid=(ini+fin)/2; // divisione intera
    valore_mid=dati[mid];  
    }
    return -1;
  }  


void stampa(int dati[], int ini , int fin)
  {
  for (int i=0;i<=fin;i++)
    {
        cout << setw(12);
    if (i>=ini)   cout<< dati[i]; else cout<< "";
    }
  cout << endl;
  }  

void qsort(int * array , int ini , int fin)
  {
  int pivot; int temp;
  int temp_ini,temp_fin;
  temp_ini=ini;temp_fin=fin;
  pivot= array[ (temp_ini+temp_fin) >>1] ; // valore a meta'
  //printf("pivot: %d  ini: %d  fin: %d\n",pivot,temp_ini,temp_fin);
  //stampa(array,ini,fin) ; 
  while (temp_ini < temp_fin)
    {
    while (array[temp_ini] < pivot && temp_ini < fin )
      temp_ini++;
    while (pivot < array[temp_fin] && temp_fin >ini  )
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
    //stampa(array,ini,fin) ; 
    //printf("%5d %5d\n",temp_ini,temp_fin);
    //return;
    //printf("   blocco1: %d-%d  blocco2: %d-%d\n",ini,temp_fin,temp_ini,fin);
    //if (temp_fin<temp_ini) 
    if (ini < temp_fin ) qsort(array,ini,temp_fin);  
    if (temp_ini < fin ) qsort(array,temp_ini,fin);  
    //stampa(array,ini,fin) ; 
    }
      
      
