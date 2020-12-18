for(int k = 1; k < n; k++){
  int temp = a[k]; 
  int j = k - 1;
  while(j >= 0 && temp <= a[j]){
    a[j+1] = a[j];
    j -= 1;
  }
  a[j+1] = temp;
}
