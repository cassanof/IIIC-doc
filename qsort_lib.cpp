

template <class X>
  int ricerca_binaria(X dati[], int dim ,X dato_cercato, int (*FUN) (X& , X&))
  { //ricerca dat_cercato e restituisce la posizione 
    // returns -1 if not found. DATI DEVE ESSERE SORTED (ORDINATO)
  int ini,mid,fin; // indice inizio, meta e fine blocco  
  X valore_mid;
  ini=0 ; fin = dim-1;
  int comparazione;
  mid=(ini+fin)/2; // divisione intera
  valore_mid=dati[mid];
  while (ini <= fin)
    {
    //printf("%d %d %d  %d\n",ini,mid,fin,valore_mid);
    comparazione= FUN (dati[mid],  dato_cercato);
    //if (dati[mid]== dato_cercato ) // ho trovato
    if (comparazione==0)
      return mid;
    //if (dati[mid] < dato_cercato )
    if (comparazione < 0)
      ini=mid+1;
    else
      fin=mid-1;
    mid=(ini+fin)/2; // divisione intera
    valore_mid=dati[mid];  
    }
    return -1;
  }  


template <class X>
void qsort(X * array , int ini , int fin,int (*cmp)(X& ,X &))
  {
  X pivot; X temp;
  int temp_ini,temp_fin;
  temp_ini=ini;temp_fin=fin;
  pivot= array[ (temp_ini+temp_fin) /2 ] ; // valore a meta'
  //printf("pivot: %d  ini: %d  fin: %d\n",pivot,temp_ini,temp_fin);
  //stampa(array,ini,fin) ; 
  while (temp_ini <= temp_fin)
    {
    while (cmp( array[temp_ini] , pivot)<0   && temp_ini < fin )   // array[temp_ini] < pivot 
      temp_ini++;
    while (cmp( pivot , array[temp_fin])<0   && temp_fin >ini  )
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
    //stampa(array,ini,fin) ; 
    //printf("%5d %5d\n",temp_ini,temp_fin);
    //return;
    //printf("   blocco1: %d-%d  blocco2: %d-%d\n",ini,temp_fin,temp_ini,fin);
    //if (temp_fin<temp_ini) 
    if (ini < temp_fin ) qsort(array,ini,temp_fin,cmp);  
    if (temp_ini < fin ) qsort(array,temp_ini,fin,cmp);  
    //stampa(array,ini,fin) ; 
    }
      
      
