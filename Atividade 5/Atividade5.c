#include <stdio.h>
#include <string.h>  

void shell(int v[], int n, int *somashell);
void quick(int v[], int f, int l, int *somaquick);

int main() {
    int n = 0;
    scanf("%d", &n);
    
    int vetor[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }
    
    for (int i = 0; i < n; i++) {
        int somashell = 0, somaquick = 0;
        
        int v1[i+1], v2[i+1];
        memcpy(v1, vetor, (i+1) * sizeof(int));
        memcpy(v2, vetor, (i+1) * sizeof(int));
        
        shell(v1, i+1, &somashell);  
        quick(v2, 0, i, &somaquick);
        
        if (somaquick == somashell) {
            printf("- ");
        } else if (somaquick > somashell) {
            printf("S ");
        } else {
            printf("Q ");
        }
    }
    
    return 0;
}

void shell(int v[], int n, int *somashell) {
    int gap = 1;
    while (gap <= n) {
        gap *= 2;
    }
    gap = gap / 2 - 1;
    
    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int x = v[i];
            (*somashell)++;  
            int j = i - gap;
            while (j >= 0 && v[j] > x) {
                v[j + gap] = v[j];
                (*somashell)+=2;  
                j -= gap;
            }
            if (j >= 0 && v[j] <= x) (*somashell)++; 
            v[j + gap] = x;
            (*somashell)++;  
        }
        gap /= 2;
    }
}

void quick(int v[], int f, int l, int *somaquick) {
    if (f >= l) {
        return;
    }

    int m = (l + f) / 2;
    
    int pivot = v[m];
    (*somaquick)++;  
    int i = f;
    int j = l;
 

    while (1) {
        while (v[i] < pivot) {
            (*somaquick)++; 
            i++;
        }
        while (v[j] > pivot) {
            (*somaquick)++;  
            j--;
        }
        (*somaquick)+=2; 
        if (i >= j) {
            break;
        }
        int aux = v[i];
        v[i] = v[j];
        v[j] = aux;
        (*somaquick)+=3;  
        i++;
        j--;
    }
    quick(v, f, j, somaquick);  
    quick(v, j + 1, l, somaquick);  
}
