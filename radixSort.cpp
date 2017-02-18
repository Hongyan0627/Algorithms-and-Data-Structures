#include<iostream>

using namespace std;

int getMax(int a[], int n){
	
	int mx = a[0];
	for(int i = 1; i < n; i++){
		
		if(a[i] > mx){
			
			mx = a[i];
			
		}
		
	}
	
	return mx;
	
}

void countSort(int a[], int n, int exp)