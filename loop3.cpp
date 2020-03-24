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
  
 
     
  // 1) GOTO  uguale a WHILE ( controllo anticipato )=
  // inizializzo i=0
  // controllo se NON e' valido ed esco 
  // eseguo il mio codice che dipende da i
  // incremento i
  // ritorno su (al controllo di validita')
  cout << "primo array \n"; 
  i=0;
  
  CONTINUA: // etichetta: nome seguito da :
  if (i >= N ) 
    goto USCITA;
  cout << "dammi il valore # "<< i+1 <<" " ; cin >> a1[i];  
  i=i+1;
  goto CONTINUA;
  USCITA:  
 // 2)
  // esegui il codice seguente N volte con i che va da 0 a N-1
  // for (inizializzazioni ; condizione di continuazione ; codice di avanzamento
  cout << "secondo array \n"; 
  for ( i=0    ; i< N  ;i=i+1   )
    {
    cout << "dammi il valore # "<< i+1 <<" " ; cin >> a2[i]; //i=i+1;  // [] selezionano elemento dall array
    } 
  //  WHILE
  // inizializzo i
  // finche' i <N
  // eseguo codice e incremento la i
  i=0;
  while (i<N)
    {
    asomma[i] = a1[i] + a2[i] ;
    i++ ;
    }
  
  // inizializzo i
  // eseguo codice e incremento la i
  // finche' i <N
  //  
   i=0;
  cout << "risultati  \n"; 
  do
    {
    cout << "valore # "<< i+1  << " " << asomma[i] << endl ; 
    i=i+1; 
    } while (i<N) ;
  
 
 
  }
