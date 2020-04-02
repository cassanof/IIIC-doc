#include <iostream>  // serve per includere le definizioni della libreria
#include <cmath>
#include <iomanip>
#include <unistd.h>
// g++ sort_scambio.cpp -o sort_scambio
// bubble sort

using namespace std;  // permette di usare gli oggetti e le funzioni 

template <class X>
void ordina(X dati[], int dim,int (*cmp)(X& ,X &)  ); // dichiarazione: e' prima di main
template <class X>  
int ricerca_lineare(X dati[], int dim ,X dato_cercato);
template <class X>
int ricerca_binaria(X dati[], short dim ,X dato_cercato);
template <class X>
int compara_interi(X & a,X & b) // ><=0 a segìconda che a>b a>b a==b
  {if (a-b>0) return 1;
  if (a-b<0) return -1;
  return 0;
  }


int main()
  {
  double numero=35;
  //int  lista[]={34, 3, 2, 5, 6,23.8,43,88, 9, 5,43,23};
  double  lista[]={34, 3, 2, 5.6, 6,23.8,43,88, 9, 5,43,23};
  printf("Il numero %d e' in posizione %d\n" ,numero ,
    ricerca_lineare( lista, sizeof(lista) / sizeof(lista[-50]),(double)numero) );
  // dim array :  dimensione in bytes dell'array / dimensione dell'elemento
  ordina (lista, sizeof(lista) / sizeof(lista[20]) ,compara_interi ); // dim dell'array
  printf("Il numero %d e' in posizione %d\n" ,numero ,
    ricerca_binaria( lista, sizeof(lista) / sizeof(lista[-50]),numero) );
  
  
  }

template <class X>  
int ricerca_binaria(X dati[], short dim ,X dato_cercato)
  { //ricerca dat_cercato e restituisce la posizione 
    // returns -1 if not found. DATI DEVE ESSERE SORTED (ORDINATO)
  int ini,mid,fin; // indice inizio, meta e fine blocco  
  X valore_mid;
  ini=0 ; fin = dim-1;
  mid=(ini+fin)/2; // divisione intera
  valore_mid=dati[mid];
  while (ini <= fin)
    {
    printf("%d %d %d  %d\n",ini,mid,fin,valore_mid);
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
  
template <class X>  
int ricerca_lineare(X dati[], int dim ,X dato_cercato)
  { //ricerca dat_cercato e restituisce la posizione 
    // returns -1 if not found
  for (int i=0; i< dim ;i++)
    {
    if (dato_cercato == dati[i])
      return i;
    }
  return -1;
  }  
template <class X>
void stampa(X dati[], int dim)
  {
  for (int i=0;i< dim;i++)
    {
    cout << setw(6) << dati[i];
    }
  cout << endl;
  }  
   
template <class X>   
void scambia(X& a, X& b){  //"a,b=b,a;"?
X c;
c = a; a = b;b = c;
}//scambia    

template <class X>
void ordina(X dati[], int dim,int (*cmp)(X& ,X &)  ) // parametrizzato la funzione ordina
  { 
  cout<< " i  j   ";stampa(dati,dim);
  for (int i=0; i< dim-1;i++) // [0 .. dim -1]
    {
    for (int j=i+1;j<dim;j++)  // [ i+1 .. dim]
      {
      if(cmp(dati[i],dati[j] )>0 )
        { // dati[i],dati[j] = dati[j],dati[i]
        cout <<setw(2)<<i<<"  "<<setw(2)<<j<<"  "; 
        scambia(dati[i], dati[j]);
        //c=dati[i];dati[i]=dati[j];dati[j]=c;
        stampa(dati,dim);
        }
      }
    }  
}//ordina
