#include <cstdio>
#include <iostream>
#include <string.h>
int somma ( int a , int b )
  {
   int smmm;
   smmm=a +b ;   
   return smmm;   
  }

class punto  // equivalente di struct
  {
   public:
   int x ; int y;
   char nome[30];
  };

int main()
  {
  int i;
  int ar[11];
  punto p1;
  punto *pp1 =new punto();
  p1. x= 7; p1.y=8;  strcpy(p1.nome,"centro");
  pp1->x =8;
  std::cout  << "ciao\n";    
  std::cout << "x= " << p1.x<< std::endl;
  std::cout << "nome= " << p1.nome<< std::endl;
  for (i=1;i<11;i=i+1)
    {
      if (i<10) {
          ar[i] = i * i;
          std::cout << i << " :-> " << ar[i] << " - ";
      } else {
          ar[i] = i * i;
          std::cout << i << " :-> " << ar[i];
      }
    }
  std::cout<< std::endl <<somma (8,9);
  }