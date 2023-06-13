#include <iostream>
using namespace std;

int N, tmp[1000];
int * arr;

void merge(int start, int end){
	int mid = (start+end)/2;
	int i = start;
	int j = mid+1;
	int k = start;

	while(i<=mid && j<=end){
		if(arr[i]<=arr[j]){
			tmp[k]=arr[i];
			i++;
		}
		else{
			tmp[k]=arr[j];
			j++;
		}
		k++;
	}

	if(i>mid){
		for(int t=j; t<=end ;t++){
			tmp[k]=arr[t];
			k++;
		}
	}
	else{
		for(int t=i; t<=mid; t++){
			tmp[k]=arr[t];
			k++;
		}
	}

//Copy
	for(int t=start; t<=end ;t++){
		arr[t] = tmp[t];
	}

}

void partition(int start, int end){
	int mid = 0;
	if(start<end){
		mid = (start+end)/2;
		partition(start, mid);
		partition(mid+1, end);
		merge(start, end);
	}
}

int main(void){
	scanf("%d", &N);
	arr = new int[N];
	for(int i=0; i<N; i++){
		scanf("%d", &arr[i]);
	}

	partition(0,N-1);

	for(int i=0; i<N; i++){
		printf("%d ", arr[i]);
	}

	return 0;
}