#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
	if (a>b){
		return a;
	}else{
		return b;
	}
}

int largest_product_subarray(int arr[], int size, int k){
	int max_product;
	int prev_product;
	
	for (int i=0;i<k;i++){
		max_product *= arr[i];
	}
	
	prev_product = max_product;
	int product_so_far;
	for (int i=1;i<(n-k);i++){
		product_so_far = (prev_product/arr[i-1])*arr[i+k-1];
		max_product = max(prev_product, product_so_far);
		prev_product = product_so_far;		
	}
	
	return max_product;
}