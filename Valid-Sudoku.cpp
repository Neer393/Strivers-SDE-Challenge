bool isSafe(int i,int j,int matrix[9][9],int k){
    for(int idx=0;idx<9;idx++){
        if(matrix[i][idx]==k)   return false;
        if(matrix[idx][j]==k)   return false;
        if(matrix[3*(i/3)+(idx/3)][3*(j/3)+(idx%3)]==k) return false;
    }
    return true;
}

bool solve(int matrix[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(matrix[i][j]==0){
                for(int k=1;k<=9;k++){
                    if(isSafe(i,j,matrix,k)){
                        matrix[i][j]=k;
                        if(solve(matrix)){
                            return true;
                        }
                        else{
                            matrix[i][j]=0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool isItSudoku(int matrix[9][9]) {
    return solve(matrix);
}
