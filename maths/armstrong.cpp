#include<iostream>
using namespace std;


bool isArmstrongNum(int n){
    int copynum =n;
    int cubeSum = 0;
    
    while(n != 0){
        int x = n%10;
        cubeSum += (x*x*x);
        n = n/10;
    }
    return copynum == cubeSum;
}

int main(){
    int n =153;
    if(isArmstrongNum(n)){
        cout<<"yes";
    }else{
        cout<<"no";
    }
    return 0;
}