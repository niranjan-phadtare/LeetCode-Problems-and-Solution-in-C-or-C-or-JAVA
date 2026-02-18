class Solution {
public:
    bool hasAlternatingBits(int n) {
   int i = 0;
   int arr[32];
   while(n>0){
    arr[i] = n%2;
    n = n/2;
    i++;
   }
   
   int size = i;
   int j = 0;
   i--;
   while(j < i){
    swap(arr[i],arr[j]);
    i--;
    j++;
   }
   int k = 0;
   while(k < size-1){
    if(arr[k]==arr[k+1]){
        
        return false;
    }
    else{
        k++;
    }
    
   }
    return true;

    }
};
