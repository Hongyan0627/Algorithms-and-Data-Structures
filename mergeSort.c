#include <stdlib.h>
#include <stdio.h>

#define N 6

void merge(int a[],int l, int m, int r){
	
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	
	int L[n1],R[n2];
	
	for(i = 0; i < n1; i++){
		L[i] = a[l+i];
	}
	
	for(j = 0; j < n2; j++){
		
		R[j] = a[m + j + 1];
		
	}
	
	i = 0;
	j = 0;
	k = l;
	
	while((i < n1) && (j < n2)){
		
		if(L[i] <= R[j]){
			a[k] = L[i];
			i = i + 1;
		}
		else{
			a[k] = R[j];
			j = j + 1;
		}
		k = k  + 1;
	}
	
	while ( i < n1){
		
		a[k] = L[i];
		i = i + 1;
		k = k + 1;		
	}
	
	while ( j < n2){
		
		a[k] = R[j];
		j = j + 1;
		k = k + 1;
		
	}
	
}


void mergeSort(int a[], int l, int r){
	
	if (l < r){
		int m = l + (r - l)/2;
		mergeSort(a,l,m);
		mergeSort(a,m+1,r);
		merge(a,l,m,r);
	}	
}

int main(){
	
	int num[N] = {34,45,12,19,10,88};
	mergeSort(num,0,N-1);
	
	for(int i = 0; i < N; i++){
		printf("%d ",num[i]);
	}
	
	printf("\n");
	system("pause");
	return 0;
}

