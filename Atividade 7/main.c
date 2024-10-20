#include <stdio.h>

void quick(int v[], int f, int l);
int bb (int a[], int n, int x);
int bbrec(int a[], int c, int f, int x);

int main()
{
    int n, k;
    scanf("%d", &n);
    
    int vetor[n];
    for(int i=0; i<n; i++) {
    scanf("%d", &vetor[i]);
    }
    
    scanf("%d", &k);
    
    int busca[k];
    for(int i=0; i<k; i++) {
        scanf("%d", &busca[i]);
    }
    
    quick(vetor, 0, n-1);
    
    for (int i=0; i<k; i++) {
        if ((bb(vetor, n, busca[i])) == -1) printf("0\n");
        else printf ("1\n");
    }
    
    return 0;
}

void quick(int v[], int f, int l) {
    if (f >= l) {
        return;
    }

    int m = (l + f) / 2;
    
    int pivot = v[m];
    int i = f;
    int j = l;
 

    while (1) {
        while (v[i] < pivot) {
            i++;
        }
        while (v[j] > pivot) {
            j--;
        }
 
        if (i >= j) {
            break;
        }
        int aux = v[i];
        v[i] = v[j];
        v[j] = aux;
  
        i++;
        j--;
    }
    quick(v, f, j);  
    quick(v, j + 1, l);  
}

int bb (int a[], int n, int x) {
   return bbrec(a,0,n-1,x);
}

int bbrec(int a[], int c, int f, int x) {
   if(c > f) {
      return -1;
   }
   int m = (c+f)/2;
   if(x == a[m]) {
         return m;
   }  
   if (x > a[m]) {
         return bbrec(a,m+1,f,x);
   } 
   return bbrec(a,c,m-1,x);
}

