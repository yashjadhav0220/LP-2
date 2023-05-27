#include<bits/stdc++.h>
using namespace std;
int admj[50][50]={0,0};
int visited[50]={0};
void DFS(int s,int v, char vertices[]){
	visited[s]=true;
	cout<<vertices[s]<<" ";
	for(int i=0; i<v; i++){
		if(admj[s][i] && !visited[i]){
			DFS(i,v,vertices);
		}
	}
}
void BFS(int s, int v, char vertices[]){
	bool visited[v];
	for (int i=0; i<v; i++){
		visited[i]=false;
	}
	int v2;
	queue<int>bfsq;
	if(!visited[s]){
		visited[s]=true;
		cout<<vertices[s]<<" ";
		bfsq.push(s);
		while(!bfsq.empty()){
			v2=bfsq.front();
			for (int i=0; i<v; i++){
				if(admj[v2][i] && !visited[i]){
					visited[i]=true;
					cout<<vertices[i]<<" ";
					bfsq.push(i);
				}
			}
			bfsq.pop();
		}
	}
}
int main(){
	int v,c;
	cout<<"Enter the number of vertices ";
	cin>>v;
	char vertices[v];
	for(int i=0; i<v; i++){
		cout<<"Enter the name of the vertex ";cin>>vertices[i];
	}
	cout<<endl;
	for (int i=0; i<v;i++){
		for (int j=i+1; j<v; j++){
			cout<<"Enter 1 if an edge exists between "<<vertices[i]<<" and "<<vertices[j]<<" ";cin>>c;
			admj[i][j]=admj[j][i]=c;
		}
	}
	cout<<endl;
	
	for(int i=0; i<v; i++){
		cout<<"\t"<<vertices[i];
	}
	cout<<endl;
	for(int i=0; i<v; i++){
		cout<<vertices[i]<<"\t";
		
		for(int j=0; j<v; j++){
			cout<<admj[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	cout<<endl;
	int s;
	cout<<"Enter the starting vertex ";cin>>s;cout<<endl;
	cout<<"DFS "<<endl;
	DFS(s,v,vertices);
	cout<<endl;
	cout<<"BFS "<<endl;
	BFS(s,v,vertices);
	return 0;
}
