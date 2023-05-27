#include<bits/stdc++.h>
using namespace std;
void addSolution(vector<vector<int> > &ans ,vector<vector<int> > &board, int n){
	
	for(int i=0; i<n; i++){
		vector<int>temp;
		for(int j=0; j<n; j++){
			temp.push_back(board[i][j]);
		}
		ans.push_back(temp);
	}	
}

bool isSafe(int row,int col, vector<vector<int> > &board, int n){
	// checking for the left side beacause we start filling from the left side and no need to check for the right side
	int x=row; 
	int y=col;
	
	//check for same row
	while(y>=0){
		if(board[x][y]==1)
			return false;
		y--;
	}
	
	//check for diagonal upwards
	x=row; 
	y=col;
	while(x>=0 && y>=0){
		if(board[x][y]==1)
			return false;
		y--;
		x--;
	}
	
	//check for diagonal downwards
	x=row; 
	y=col;
	while(x<n && y>=0){
		if(board[x][y]==1)
			return false;
		y--;
		x++;
	}
	
	return true;
	
}
void solve(int col, vector<vector<int> > &ans ,vector<vector<int> > &board, int n){
	//base case
	if(col==n){
		addSolution(ans,board,n);
		return;
	}
	
	//solve 1 case and rest recurssion will take case
	for(int row=0; row<n; row++){
		if(isSafe(row,col,board,n)){
			// if placing is safe
			board[row][col]=1;
			
			solve(col+1,ans,board,n);
			//backtrack if queen is placed in wrong place
			board[row][col]=0;
		}
	}
}
void nQueen(int n){
	vector<vector<int> > board(n,vector<int>(n,0));
	vector<vector<int> > ans;
	
	//0 because we start filling from left to right
	solve(0,ans, board, n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	
	nQueen(4);
	return 0;
	
	
}
