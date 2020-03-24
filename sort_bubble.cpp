#include <iostream>  // serve per includere le definizioni della libreria
#include <cmath>
#include <iomanip>
#include <iomanip>

// bubble sort

using namespace std;  // permette di usare gli oggetti e le funzioni 

void ordina(int dati[], short dim); // dichiarazione: e' prima di main

int main()
  {
  int lista[]={34,3,2,5,6,23,43,88,9,5,43,23};
  ordina (lista, sizeof(lista) / sizeof(lista[0]) ); // dim dell'array
  
  }

stampa(int dati[], short dim)
  {
  for (int i=0;i< dim;i++)
    {
    cout << setw(3) << dati[i];
    }
  cout << endl;
  }  
   
void scambia(int& a, int& b){
int c;
c = a; a = b;b = c;
}//scambia    

void ordina(int dati[], short dim)
{
short ultimoScambio, sup;
bool scambi;
ultimoScambio = dim - 1;
cout<< " i  j   ";stampa(dati,dim);
do{
  scambi = false;
  sup = ultimoScambio - 1;
  for(short i = 0; i <= sup; i++)
  if(dati[i] > dati[i+1])
    {
    scambia(dati[i], dati[i+1]);
    scambi = true;
    ultimoScambio = i;
    cout <<setw(2)<<i<<"  "<<setw(2)<<i+1<<"  "; 
    stampa(dati,dim);
    }//if
    cout <<endl;
}while(scambi);
}//ordina
