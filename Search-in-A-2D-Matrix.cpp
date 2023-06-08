bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n=mat.size(),m=mat[0].size();
    for(int i=0;i<n;i++){
        int s=0,e=m-1;
        if(target>=mat[i][s] && target<=mat[i][e]){
            while(s<=e){
                int mid = s+ ((e-s)/2);
                if(mat[i][mid]==target) return true;
                else if(mat[i][mid]<target) s=mid+1;
                else    e=mid-1;
            }
        }
    }
    return false;
}
