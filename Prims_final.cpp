#include<bits/stdc++.h>
using namespace std;
int miniDist(int distance[], bool mstSet[]){
	int index=-1;
	int minimum=INT_MAX;
	for(int i=0; i<4; i++){
		if(!mstSet[i] && distance[i]<minimum){
			minimum=distance[i];
			index=i;
		}
	}
	return index;
}
void primMST(int graph[][4], int n){
	int distance[4]; // Key values used to pick minimum weight edge in cut
	int parent[4];	//array to store the constructed MST
	bool mstSet[4];
	for(int i=0; i<n; i++){
		distance[i]=INT_MAX;
		mstSet[i]=false;
	}
	
	distance[0]=0;
	parent[0]=0;	// First node is always the root of MST
	
	for(int i=0; i<n; i++){
		int sele=miniDist(distance,mstSet);
		mstSet[sele]=true;
		
		for(int i=0; i<n; i++){
			// Update key value and parent index of the adjacent vertices of the picked vertex
			if(graph[sele][i] && !mstSet[i] && graph[sele][i]<distance[i]){
				distance[i]=graph[sele][i];
				parent[i]=sele;
			}
		}
	}
	
	cout<<endl;
	for(int i=1; i<n; i++){
		char str=65+parent[i];
		char str1=65+i;
		cout<<str<<" - "<<str1<<" - "<<graph[i][parent[i]]<<endl;
	}
}
int main(){
	int n;
	int graph[4][4]={0,0};
	cout<<"Enter the number of vertices "; cin>>n;
	cout<<"\nEnter 0 is no edge exists between the pairs else enter positive value "<<endl;
	for(int i=0; i<n;i++){
		for(int j=0; j<n; j++){
			cin>>graph[i][j];
		}
	}
	
	primMST(graph,4);
	return 0;
}
