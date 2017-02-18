#include<stdio.h>
#include<stdlib.h>

#define N 6

void bubbleSort(int a[], int n){
	
	for (int i = 0; i < n-1; i++){
		
		for(int j = 0; j < n - 1 - i; j++){
			
			if(a[j] > a[j+1]){
				
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				
			}
			
		}
	}
	
}

int main(){
	
	int num[N] = {34,45,12,19,10,88};
	bubbleSort(num,N);
	
	for(int i = 0; i < N; i++){
		printf("%d ",num[i]);
	}
	
	printf("\n");
	system("pause");
	return 0;
}