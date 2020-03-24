#include <iostream>
using namespace std;
#define N 3
int main( int argn , char * argv[])
  {
  //const int N=3; // modo 2 di definire la costante
  double a1_0,a1_1,a1_2,a1_3,a1_4;  // A..Z a..z 0..9 _    #@$%
  double a2_0,a2_1,a2_2,a2_3,a2_4;
  double asomma_0,asomma_1,asomma_2,asomma_3,asomma_4;
  double a1 [ N ];
  double a2 [ N ];
  double asomma[ N ];
  int i; // intero da usare per il ciclo attorno all'array
  i=0;
  cout << "Primo array " << endl ; //riga + acapo 
  cout << "dammi il valore # "<< i+1  ; cin >> a1_0;    i=i+1;
  cout << "dammi il valore # "<< i+1  ; cin >> a1_1;    i=i+1;
  cout << "dammi il valore # "<< i+1  ; cin >> a1_2;    i=i+1;
  cout << "dammi il valore # "<< i+1  ; cin >> a1_3;    i=i+1;
  cout << "dammi il valore # "<< i+1  ; cin >> a1_4;    i=i+1;
  i=0;
  cout << "Secondo array " << endl ; //riga + acapo 
  cout << "dammi il valore # "<< i+1  ; cin >> a2_0;    i=i+1;
  cout << "dammi il valore # "<< i+1  ; cin >> a2_1;    i=i+1;
  cout << "dammi il valore # "<< i+1  ; cin >> a2_2;    i=i+1;
  cout << "dammi il valore # "<< i+1  ; cin >> a2_3;    i=i+1;
  cout << "dammi il valore # "<< i+1  ; cin >> a2_4;    i=i+1;
  i=0;
  asomma_0 = a1_0 + a2_0;   i+=1 ;
  asomma_1 = a1_1 + a2_1;   i+=1 ;
  asomma_2 = a1_2 + a2_2;   i+=1 ;
  asomma_3 = a1_3 + a2_3;   i+=1 ;
  asomma_4 = a1_4 + a2_4;   i+=1 ;
  i=0;
  cout << "Risultati " << endl ; //riga + acapo 
          // la somma di     45 e    12   e'   57
  cout << "valore # "<< i+1 << " " << asomma_0 << endl;    i=i+1;
  cout << "valore # "<< i+1 << " " << asomma_1 << endl;    i=i+1;
  cout << "valore # "<< i+1 << " " << asomma_2 << endl;    i=i+1;
  cout << "valore # "<< i+1 << " " << asomma_3 << endl;    i=i+1;
  cout << "valore # "<< i+1 << " " << asomma_4 << endl;    i=i+1;
  
  }
