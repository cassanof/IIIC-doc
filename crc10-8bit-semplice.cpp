#include <stdio.h>
#include <string.h>  // per strdup e strlen
//  link utili
//  http://chrisballance.com/wp-content/uploads/2015/10/CRC-Primer.html
//  http://www.zorc.breitbandkatze.de/crc.html
//  https://crccalc.com

typedef unsigned char byte; // ora uso "byte" al posto di "unsigned char"
  
int shift_left_1(byte *frase,int len) 
  {
  // scorre verso sinistra di un bit l'intera stringa
  // aggiunge a sinistra un bit 0
  // puo' essere velocizzata usando registri da 32 o 64 bit
  unsigned short a=0;     // il registro temporaneo deve essere di 16 bit per il riporto
  for (int i=len-1;i>=0;i--) // parto dal fondo per gestire il riporto
    {
    if (a>255)               // a contiene il riporto. all'inizio e' nullo
      a=(frase[i] << 1) + 1  ; // aggiungo il riporto del precedente passo
    else
      a=(frase[i] << 1)  ;    // non c'era riporto
    frase[i]=a & 0xff ;       // metto in array il byte shiftato senza il bit di riporto
    }
 return (a>255);    // ultimo riporto   
 }
 
void print_exadecimal( byte *frase , int l1)
  { // stampa la frase in esadecimale
  for (int i=0;i<l1;i++)  // per ogni byte
    {
    if (i>0) printf("-"); // separatore tra bytes per leggere meglio. solo dopo il primo 
    printf ("0x%2x",frase[i] ); // 0x e' il prefisso %2x: format per esadecimale due posizioni
    }
  }
  
 
void print_binary( byte *frase , int l1)
  { // stampa la frase in binario
  byte temp,valore_and;
  for (int i=0;i<l1;i++)  // per ogni byte
    {
    if (i>0) printf("-"); // separatore tra bytes per leggere meglio. solo dopo il primo 
    temp=frase[i];
    valore_and=128; // 0x80 , 0b1000000  parto con il bit alto
    printf("0b");   // prefisso
    for (int bi=0;bi<8;bi++)  // per ogni bit
      {
      if (temp & valore_and) // il bit e' 1 ?
        printf("1");
      else
        printf("0");
      valore_and =valore_and >> 1; // divido per due con lo shift a destra di un bit    
      }
    }  
  }
 
 void crc_8(byte *frase,int len,byte poly)
   { // calcola il crc-8
   byte riporto;
   frase[len]=0; // aggiungo in coda 8 bit vuoti (0)
   printf("sequenza    ");print_binary( frase ,  len);printf("  "); // stampo in vari modi la fras iniziale
         print_exadecimal(frase,len);printf(" \"%s\"\n",frase);
  
   for (int i=0;i< len*8 ; i++)
    {
    riporto=shift_left_1(frase,len+1);  // eseguo shift left di 1 bit e catturo il riporto eventuale
    
    // ora stampo messaggistica
    printf("shift 1 bit ");print_binary( frase ,  len);
    if (!riporto)  puts("  No riporto dallo shift"); else puts("  RIPORTO DALLO SHIFT");
    printf("polinomio   ");print_binary( & poly ,  1);puts("");

    if (riporto) // eseguo lo XOR (^) se c'e' stato riporto
      frase[0] ^= poly;
    // stampo messaggistica  
    printf("XOR         ");print_binary( frase , len);
    if (!riporto)  puts("  xor non effettuato "); else puts("  XOR EFFETTUATO");
    }
   }
 
 
int main()
  { // 
  int length;
  char  testo[102];          // spazio in piu' per il byte di riporto
  char poly=0x07 , *copia;   // polinomio generatore classico per 8bit (CRC-8)
  printf("Testo da elaborare: "); 
  scanf("%100s",testo);      // leggo la stringa (cin >> testo)
  length=strlen(testo) ;     //calcolo la lunghezza
  copia=strdup(testo);       // crea una copia della stringa allocando nuova memoria
  // crc_8 distrugge la stringa di partenza quindi devo copiarla altrove
  crc_8( (byte*)testo,length , poly); 
  printf("\nil CRC-8 di (%s) e': ",copia);
  printf("0x%x\n",(byte)testo[0]);
  }    
