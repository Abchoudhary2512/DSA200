#include<bits/stdc++.h>
using namespace std;

int LinearSearch(vector<int>&arr,int x){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==x){
            return i;
        }
    }
    return -1;
}


int BinarySearch(vector<int>&arr,int x){
    int start = 0;
    int end = arr.size()-1;
    while(start<=end){
        int mid = start +(end-start)/2;
        if(arr[mid]==x){
            return mid;
        }
        else if(arr[mid]>x){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return -1;
}

int main(){
    vector<int>arr = {1,3,4,6,7};
    int x = 3;
    int index = LinearSearch(arr,x);
    
    sort(begin(arr),end(arr));
    int index2 = BinarySearch(arr,x);
    cout<<index<< " "<<index2;
    return 0;

}