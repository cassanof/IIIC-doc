#include <iostream>  // serve per includere le definizioni della libreria
#include <cmath>
#include <iomanip>

// bubble sort

using namespace std;  // permette di usare gli oggetti e le funzioni 

void ordina(int elenco [], short lunghezza ); // dichiarazione: e' prima di main
int ricerca_lineare(int dati[], short dim ,int dato_cercato);
int ricerca_binaria(int dati[], short dim ,int dato_cercato);

int main()
  {
  int numero=35;
  int  lista[]={34, 3, 2, 5, 6,23,43,88, 9, 5,43,23};
  printf("Il numero %d e' in posizione %d\n" ,numero ,
    ricerca_lineare( lista, sizeof(lista) / sizeof(lista[-50]),numero) );
  // dim array :  dimensione in bytes dell'array / dimensione dell'elemento
  ordina (lista, sizeof(lista) / sizeof(lista[20]) ); // dim dell'array
  printf("Il numero %d e' in posizione %d\n" ,numero ,
    ricerca_binaria( lista, sizeof(lista) / sizeof(lista[-50]),numero) );
  
  
  }
int ricerca_binaria(int dati[], short dim ,int dato_cercato)
  { //ricerca dat_cercato e restituisce la posizione 
    // returns -1 if not found. DATI DEVE ESSERE SORTED (ORDINATO)
  int ini,mid,fin; // indice inizio, meta e fine blocco  
  int valore_mid;
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
  
int ricerca_lineare(int dati[], short dim ,int dato_cercato)
  { //ricerca dat_cercato e restituisce la posizione 
    // returns -1 if not found
  for (int i=0; i< dim ;i++)
    {
    if (dato_cercato == dati[i])
      return i;
    }
  return -1;
  }  

stampa(int dati[], short dim)
  {
  for (int i=0;i< dim;i++)
    {
    cout << setw(3) << dati[i];
    }
  cout << endl;
  }  
   
void scambia(int& a, int& b){  //"a,b=b,a;"?
int c;
c = a; a = b;b = c;
}//scambia    

void ordina(int dati[], short dim)
  { int c;
  cout<< " i  j   ";stampa(dati,dim);
  for (int i=0; i< dim-1;i++) // [0 .. dim -1]
    {
    for (int j=i+1;j<dim;j++)  // [ i+1 .. dim]
      {
      if(dati[i] > dati[j])
        { // dati[i],dati[j] = dati[j],dati[i]
        cout <<setw(2)<<i<<"  "<<setw(2)<<j<<"  "; 
        scambia(dati[i], dati[j]);
        //c=dati[i];dati[i]=dati[j];dati[j]=c;
        stampa(dati,dim);
        }
      }
    }  
}//ordina
