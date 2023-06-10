int search(int* arr, int n, int key) {
    int s=0,e=n-1;
    while(s<=e){
        int mid = s+((e-s)/2);
        if(arr[mid]==key)   return mid;
        else if(arr[s]<=arr[mid]){
            if(key>=arr[s] && key<=arr[mid]){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        else{
            if(key>=arr[mid] && key<=arr[e]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
    }
    return -1;
}
