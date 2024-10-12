#include <stdio.h>
#include <string.h>

void BubbleSort(int arr[], int n);
void Selection(int arr[], int n);


int main(){

	char metd[10];
	int n;

	scanf("%s", metd);
	scanf("%d", &n);

	int vect[n];

	for(int ind = 0; ind < n; ind++){
    	scanf("%d", &vect[ind]);
	}

	if(strcmp(metd, "bolha") == 0){
    		BubbleSort(vect,n);
	}
	else if (strcmp(metd, "selecao") == 0) {
        	Selection(vect,n);
    	}
	for( int elem = 0; elem < n; elem++){
    		printf("%d ", vect[elem]);
	}
	return 0;
}


void BubbleSort(int arr[], int n){
    for(int j = n; j>0; j--){
        int a = 0;
        for(int i = 0; i < j-1; i++){
            printf("C %d %d \n",i,(i+1));
            if(arr[i] > arr[i+1]){
                a = i + 2;
                printf("T %d %d \n",i, (i+1));
                int t = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = t;
            }
        }
        j = a;
    }
}

void Selection(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        int m = i;

        for(int j = i+1; j < n; j++){
            printf("C %d %d \n",m, j);
            if(arr[j] < arr[m]){

                m = j;
            }
        }
        printf("T %d %d \n",i, m);
        int t = arr[i];
        arr[i] = arr[m];
        arr[m] = t;
    }
}
