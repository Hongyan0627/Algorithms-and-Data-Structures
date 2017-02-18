#include<stdio.h>
#include<stdlib.h>

#define N 6

void insertSort(int a[], int n){
	
	for(int i = 1; i < n; i++){
		
		int j = i-1;
		int key = a[i];
		
		while((j >= 0) && (a[j] > key)){
			a[j+1] = a[j];
			j = j - 1;
		}
		
		a[j+1] = key;
		
	}
	
}

int main(){
	
	int num[N] = {34,45,12,19,10,88};
	insertSort(num,N);
	
	for(int i = 0; i < N; i++){
		printf("%d ",num[i]);
	}
	
	printf("\n");
	system("pause");
	return 0;
}