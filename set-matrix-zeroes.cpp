#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	int n=matrix.size(),m=matrix[0].size();
	unordered_map<int,bool>row,column;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(matrix[i][j]==0){
				row[i]=true;
				column[j]=true;
			}
		}
	}
	for(auto it:row){
		int r = it.first;
		for(int i=0;i<m;i++){
			matrix[r][i]=0;
		}
	}
	for(auto it:column){
		int c = it.first;
		for(int i=0;i<n;i++){
			matrix[i][c]=0;
		}
	}
}
