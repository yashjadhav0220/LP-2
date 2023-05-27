#include<bits/stdc++.h>
using namespace std;
int miniDist(int distance[], bool Tset[]){
	int index,minimum=INT_MAX;
	for(int i=0; i<5; i++){
		if(Tset[i]!=true && distance[i]<=minimum){
			minimum=distance[i];
			index=i;
		}
	}
	return index;
}
void DjistraAlgo(int graph[][5], int src)
{	int distance[5];
	bool Tset[5];
	
	for(int i=0; i<5; i++){
		distance[i]=INT_MAX;
		Tset[i]=false;
	}
	
	distance[src]=0;
	
	for(int i=0; i<5; i++){
		int m=miniDist(distance,Tset);
		Tset[m]=true;
		for(int i=0; i<5; i++){
			if(!Tset[i] && graph[m][i] && distance[m]!=INT_MAX && distance[m]+graph[m][i]<=distance[i]){
					distance[i]=distance[m]+graph[m][i];
			}
		}
	}
		
		 cout<<"Vertex\t\tDistance from source vertex"<<endl;
    		for(int k = 0; k<5; k++)                      
    		{ 
        		char str=65+k; 
        		cout<<str<<"\t\t\t"<<distance[k]<<endl;
    		}
	
	
}
int main(){
	int graph[5][5]={0,0};
	cout<<"Enter the Adjacency Matrix "<<endl;
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			cout<<"Enter the cost of edges between the vertices ";
			cin>>graph[i][j];
		}
	}
	cout<<endl;
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
        
        DjistraAlgo(graph,0);

	return 0;
}
