int removeDuplicates(vector<int> &arr, int n) {
	int i=0;
	for(int j=i+1;j<n;j++){
		if(arr[i]==arr[j]){
			continue;
		}
		else{
			i++;
			arr[i]=arr[j];
		}
	}
	return i+1;
}
