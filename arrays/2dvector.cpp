#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<vector<int>>v = {
        {1,2},
        {3,2},
        {5,2},
        {16,22},
        {13,24},
        {17,5},

    };
sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];  // sort by second element
});

    // sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            cout<<v[i][j]<<" "<<endl;
        }
    }
    return 0;
}