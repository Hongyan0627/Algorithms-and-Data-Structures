#include <stdio.h>
#include <stdlib.h>

#define N 6

int partition(int a[], int low, int high){
	
	int key = a[high];
	
	int i = low - 1;
	
	for(int j = low; j < high; j++){
		
		if(a[j] <= key){
			i = i+1;
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		
	}
	
	int temp = a[i+1];
	a[i+1] = a[high];
	a[high] = temp;
	return (i+1);
}

void quickSort(int a[],int low, int high){
	
	if(low < high){
		
		int p = partition(a,low,high);
		quickSort(a,low,p - 1);
		quickSort(a,p+1,high);
		
	}
	
}

int main(){
	
	int num[N] = {34,45,12,19,10,88};
	quickSort(num,0,N-1);
	
	for(int i = 0; i < N; i++){
		printf("%d ",num[i]);
	}
	
	printf("\n");
	system("pause");
	return 0;
}