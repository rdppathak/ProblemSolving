#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>

using namespace std;
int max(int a, int b){
	if (a>b){
		return a;
	}else{
		return b;
	}
}


/*Program to find out subarray with size k, which has maximum product*/
int largest_product_subarray(int arr[], int size, int k){
	int max_product = 1;
	int prev_product;
	
	for (int i=0;i<k;i++){
		max_product *= arr[i];
	}
	
	prev_product = max_product;
	int product_so_far;
	for (int i=1;i<(size-k);i++){
		product_so_far = (prev_product/arr[i-1])*arr[i+k-1];
		max_product = max(prev_product, product_so_far);
		prev_product = product_so_far;		
	}
	
	return max_product;
}

/*Program to find out whether array can be divided into 2 subarrays with same sum*/
int divide_subarray_into_equal(int arr[], int size){
	int total_sum = 0;
	
	for (int i=0;i<size;i++){
		total_sum += arr[i];
	}
	
	int sum_so_far = 0;
	for (int i=0;i<size-1;i++){
		if ((2*sum_so_far)+arr[i] == total_sum){
			printf ("Array can be divided into 2 subarray of eqal sum as [%d-%d] & [%d-%d]\n",
					0, (i-1), (i+1), size);
			return 1;
		}
		sum_so_far += arr[i];
	}
	printf ("Array cannot be divided into subarray of equal sum\n");
	return 0;
}

/*Program to find all subarrays which sum zero*/
std::vector<pair<int, int>> subarray_with_sum_zero(int arr[], int size){
	unordered_map <int, vector<int>> map;
	
	vector<pair<int, int>> out;
	
	int sum =0;
	
	for (int i=0;i<size;i++){
		sum += arr[i];
		
		if (sum == 0){
			out.push_back(make_pair(0, i));
		}
		
		if (map.find(sum) != map.end()){
			vector<int> vc = map[sum];
			
			for(auto it=vc.begin(); it!=vc.end(); it++){
				out.push_back(make_pair(*it+1, i));
			}
		}
		map[sum].push_back(i);
	}
	
	return out;
}


int main(){
	return 0;
}