#include <iostream>  // serve per includere le definizioni della libreria
#include <cmath>
#include <iomanip>

// bubble sort

using namespace std;  // permette di usare gli oggetti e le funzioni 

void qsort(int * array , int ini , int fin); // dichiarazione: e' prima di main
void stampa(int dati[],int ini , int fin);
int main()
  {
  int  lista[]={33, 3, 2, 5, 6,23,43,88, 9, 5,34,23,33,55};
  // dim array :  dimensione in bytes dell'array / dimensione dell'elemento
  qsort (lista, 0,sizeof(lista) / sizeof(lista[0]) -1); // dim dell'array
  stampa(lista,0,sizeof(lista) / sizeof(lista[30] ) -1 );
  
  }
void stampa(int dati[], int ini , int fin)
  {
  for (int i=0;i<=fin;i++)
    {
        cout << setw(3);
    if (i>=ini)   cout<< dati[i]; else cout<< "";
    }
  cout << endl;
  }  

void qsort(int * array , int ini , int fin)
  {
  int pivot; int temp;
  int temp_ini,temp_fin;
  temp_ini=ini;temp_fin=fin;
  pivot= array[ (temp_ini+temp_fin) /2 ] ; // valore a meta'
  printf("pivot: %d  ini: %d  fin: %d\n",pivot,temp_ini,temp_fin);
  stampa(array,ini,fin) ; 
  while (temp_ini <= temp_fin)
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
    stampa(array,ini,fin) ; 
    //printf("%5d %5d\n",temp_ini,temp_fin);
    //return;
    printf("   blocco1: %d-%d  blocco2: %d-%d\n",ini,temp_fin,temp_ini,fin);
    //if (temp_fin<temp_ini) 
    if (ini < temp_fin ) qsort(array,ini,temp_fin);  
    if (temp_ini < fin ) qsort(array,temp_ini,fin);  
    //stampa(array,ini,fin) ; 
    }
      
      
