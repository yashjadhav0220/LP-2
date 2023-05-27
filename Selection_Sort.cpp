#include<bits/stdc++.h>
using namespace std;
void selectionSort(int arr[], int n){
	for(int i=0; i<n; i++){
		int minIndex=i;
		for(int j=i+1; j<n; j++){
			if(arr[j]<arr[minIndex]){
				minIndex=j;
			}
		}
		swap(arr[i],arr[minIndex]);
	}
}
int main(){
	int e;
	cout<<"Enter the number of elements in the array ";cin>>e;
	int arr[e]={0};
	for(int i=0; i<e; i++){
		cin>>arr[i];
	}
	
	cout<<"\nBefore Sorting"<<endl;
	for(int i=0; i<e; i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\nAfter Sorting"<<endl;
	selectionSort(arr,e);
	for(int i=0; i<e; i++){
		cout<<arr[i]<<" ";
	}
	
}
