 



#include<iostream>
#include<vector>
using namespace std;

void MergeSort(vector<int>&,int,int);
void Merge(vector<int>&, int,int,int);

int main(){
    vector<int> arr = {3,1,5};
    int start = 0; 
    int end = arr.size()-1;

    MergeSort(arr,start,end);

   
    int i = 0;
    unsigned int  sum1 = 0;
    unsigned int sum2 = 0;
   // sort(arr.begin(),arr.end());
    for(i = 0; i < arr.size(); i++){
        sum1 = arr[i] - arr[i+1];
        sum2 = arr[i+1] - arr[i+2];
        if(sum1 == sum2){
            i++;
        }
        else{
            cout<<"false";
            return -1;
        }
    }
    cout<<"true";
    return 0;
}

void MergeSort(vector<int> &arr,int start, int end){
    if(start < end){
        int mid = start + (end - start)/ 2;
        MergeSort(arr,start,mid); // Left
        MergeSort(arr,mid+1,end); // Right
       
        Merge(arr,start,mid,end);
    }
}

void Merge(vector<int> &arr, int start, int mid, int end){
    vector<int>temp;
    int i = start, j = mid + 1 ;
    while(i <= mid && j <=end){ 
      if(arr[i] <= arr[j]){
        temp.push_back(arr[i]);
        i++;
     }
      else{
         temp.push_back(arr[j]);
         j++;
     }
    }
    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }
     while(j <= end){
        temp.push_back(arr[j]);
        j++;
    }

    for(int idx = 0; idx<temp.size(); idx++){
      arr[idx+start] = temp[idx];
    }
}
