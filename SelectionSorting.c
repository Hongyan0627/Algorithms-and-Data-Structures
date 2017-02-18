#include<stdio.h>
#include<stdlib.h>

#define N 6

void selectionSort(int a[], int n){
		
	for (int i = 0; i < n-1; i++){
		
		int minIndex = i;
		
		for (int j = i+1; j < n; j++){
			
			if (a[j] < a[minIndex]){
				minIndex = j;
			}
			
		}
		
		
		if (i != minIndex){
			
			int temp = a[minIndex];
			a[minIndex] = a[i];
			a[i] = temp;
		}
		
	}

}

int main(){
	
	int num[N] = {34,45,12,19,10,88};
	selectionSort(num,N);
	
	for(int i = 0; i < N; i++){
		printf("%d ",num[i]);
	}
	
	printf("\n");
	system("pause");
	return 0;
}