#include <iostream>  // serve per includere le definizioni della libreria
#include <cmath>
#include <iomanip>
#include <cstdio>

// bubble sort

using namespace std;  // permette di usare gli oggetti e le funzioni 

void qsort(int * array , int ini , int fin); // dichiarazione: e' prima di main
void stampa(int dati[], short dim);
int main()
  {
  int  lista[]={34, 3, 2, 5, 6,23,43,88, 9, 5,43,23};
  // dim array :  dimensione in bytes dell'array / dimensione dell'elemento
  qsort (lista, 0,sizeof(lista) / sizeof(lista[0]) -1); // dim dell'array
  stampa(lista,sizeof(lista) / sizeof(lista[0]) );
  
  }
void stampa(int dati[], short dim)
  {
  for (int i=0;i< dim;i++)
    {
    cout << setw(3) << dati[i];
    }
  cout << endl;
  }  

void qsort(int * array , int ini , int fin)
  {
  int pivot; int temp;
  int temp_ini,temp_fin;
  temp_ini=ini;temp_fin=fin;
  pivot= array[ (temp_ini+temp_fin) >>1] ; // valore a meta'
  printf("%5d %5d\n",temp_ini,temp_fin);
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
    //printf("%5d %5d\n",temp_ini,temp_fin);
    //return;
    if (ini < temp_fin ) qsort(array,ini,temp_fin);  
    if (temp_ini < fin ) qsort(array,temp_ini,fin);  
    }
      
      
