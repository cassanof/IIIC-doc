#include <iostream>
using namespace std;
#define N 5
int main( int argn , char * argv[])
  {
  //const int N=3; // modo 2 di definire la costante
  double a1 [ N ]; // [] dichiaro la dimensione dell' array
  double a2 [ N ];  // 0 .. N-1 
  double asomma[ N ];
  int i; // intero da usare per il ciclo attorno all'array
  i=0;
  cout << "primo array \n"; 
  cout << "dammi il valore # "<< i+1  ; cin >> a1[i];  i=i+1; // [] selezionano elemento dall array
  cout << "dammi il valore # "<< i+1  ; cin >> a1[i];  i=i+1;
  cout << "dammi il valore # "<< i+1  ; cin >> a1[i];  i=i+1;
  cout << "dammi il valore # "<< i+1  ; cin >> a1[i];  i=i+1;
  cout << "dammi il valore # "<< i+1  ; cin >> a1[i];  
  i=0;
  cout << "secondo array \n"; 
  cout << "dammi il valore # "<< i+1  ; cin >> a2[i];i=i+1;      // [] selezionano elemento dall array
  cout << "dammi il valore # "<< i+1  ; cin >> a2[i];i=i+1;
  cout << "dammi il valore # "<< i+1  ; cin >> a2[i];i=i+1;
  cout << "dammi il valore # "<< i+1  ; cin >> a2[i];i=i+1;
  cout << "dammi il valore # "<< i+1  ; cin >> a2[i];i=i+1;
  i=0;
  asomma[i] = a1[i] + a2[i] ; i++ ; 
  asomma[i] = a1[i] + a2[i] ; i++ ; 
  asomma[i] = a1[i] + a2[i] ; i++ ; 
  asomma[i] = a1[i] + a2[i] ; i++ ; 
  asomma[i] = a1[i] + a2[i] ; i++ ; 
  i=0;
  cout << "risultati  \n"; 
  cout << "valore # "<< i+1  << " " << asomma[i] ; i=i+1; 
  cout << "valore # "<< i+1  << " " << asomma[i] ; i=i+1; 
  cout << "valore # "<< i+1  << " " << asomma[i] ; i=i+1; 
  cout << "valore # "<< i+1  << " " << asomma[i] ; i=i+1; 
  cout << "valore # "<< i+1  << " " << asomma[i] ; i=i+1; 
  }
