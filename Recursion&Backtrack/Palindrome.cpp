#include<bits/stdc++.h>
using namespace std;


bool IsPal(string s,string comp){
    return s==comp;

}

void reverseStr(string &s,int left,int right){
    if(left>right) return;
    swap(s[left],s[right]);
    // left++;
    reverseStr(s,left+1,right-1);

}

int main(){
    string s = "aba";
    string newCopy = s;
    reverseStr(newCopy,0,newCopy.length()-1);
    bool ans = IsPal(s,newCopy);
    cout<<ans;
    // cout<<newCopy;
    return 0;


}