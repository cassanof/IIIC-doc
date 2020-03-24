#include <iostream>  // serve per includere le definizioni della libreria
#include <cmath>
#include <iomanip>

// Capitolo 7.7: PAG 200
// FUSIONE O MERGE DI DUE ARRAY ORDINATI


using namespace std;  // permette di usare gli oggetti e le funzioni 

const short Max = 100;
// DICHIARAZIONI DI FUNZIONI IMPLEMENTATE OLTRE
short leggiDimensione(string, short massimo);
void leggiArray(int dati[], short dim);
void scriviArray(const int dati[], short dim);
void ordina(int dati[], short dim);
void merge(const int dati1[], const int dati2[], short dim1, short
dim2, int fusione[], short& dimF);

int main(void){
  short n1, n2, n3;
  int a[Max], b[Max], c[Max+Max];
  n1 = leggiDimensione("elem",Max);
  leggiArray(a, n1);
  ordina (a,n1);
  n2 = leggiDimensione("elem",Max);
  leggiArray(b, n2);
  ordina(b,n2);
  cout << "Primo array:\n";
  scriviArray(a, n1);
  cout << "Secondo array:\n";
  scriviArray(b, n2);
  merge(a, b, n1, n2, c, n3);
  cout << "Merge:\n";
  scriviArray(c, n3);
  fflush(stdin);
  getchar();
  return 0;
  }//main
  
void merge(const int dati1[], const int dati2[], short dim1, short
dim2, int fusione[], short& dimF)
  {
  short i = 0, j = 0, k = -1;
  while((i < dim1) && (j < dim2))
    {
    if(dati1[i] < dati2[j])
      fusione[++k] = dati1[i++];
    else
      fusione[++k] = dati2[j++];
    }  
  if(i < dim1)
    for(short h = i; h < dim1; h++)
      fusione[++k] = dati1[h];
  else
    for(short h = j; h < dim2; h++)
      fusione[++k] = dati2[h];
  dimF = k + 1; //qui k contiene l'ultimo valore di indice valido
  }//merge

short leggiDimensione(string s, short massimo)
  {
  short dim;
  do{
    cout << "Inserire il numero di " << s
    << " (da 1 a " << massimo << ") ";
    cin >> dim;
  } while(!((dim >= 1) && (dim <= massimo)));
  return dim;
  }//leggiDimensione

void leggiArray(int dati[], short dim){
cout << "Inserire gli elementi dell'array" << endl;
for(short i = 0; i < dim; i++){
cout << "Elemento di indice " << i << endl;
cin >> dati[i] ;
}//for
}//leggiArray

void scriviArray(const int dati[], short dim){
for(short i = 0; i < dim; i++){
cout << dati[i] << endl;}
}//scriviArray

void scambia(int& a, int& b){
int c;
c = a; a = b;b = c;
}//scambia    

void ordina(int dati[], short dim)
{
short ultimoScambio, sup;
bool scambi;
ultimoScambio = dim - 1;
do{
  scambi = false;
  sup = ultimoScambio - 1;
  for(short i = 0; i <= sup; i++)
  if(dati[i] > dati[i+1])
    {
    scambia(dati[i], dati[i+1]);
    scambi = true;
    ultimoScambio = i;
    //stampa(dati,dim);
    }//if
}while(scambi);
}//ordina
