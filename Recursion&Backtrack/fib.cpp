#include<bits/stdc++.h>
using namespace std;

int Fib(int n){
    if(n==0) return 0;
    if(n==1 || n==2) return 1;
    return Fib(n-1)+Fib(n-2);
}

int main(){
    int n = 6
    ;
    int ans = Fib(n);
    cout<<ans;
    return 0;
}