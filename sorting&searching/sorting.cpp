#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void BubbleSort(vector<int> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = i + 1; j < v.size() - i - 1; j++)
        {
            if (v[i] > v[j])
            {
                swap(v[i], v[j]);
            }
            else
            {
                continue;
            }
        }
    }
}

void selectionSort(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        int min_index_value = i;
        for (int j = i; j < v.size() - 1; j++)
        {
            if (v[min_index_value] > v[j])
            {
                min_index_value = j;
            }
        }
        swap(v[min_index_value], v[i]);
    }
}



void insertionSort(vector<int>&v){
    for(int i=1;i<v.size();i++){
        int curr = v[i];
        int prev = i-1;
        while(prev>=0 && v[prev]>curr){
            v[prev+1] = v[prev];
            prev--;
        }
        v[prev+1] = curr;

    }
}

int main()
{
    vector<int> v = {1, -1, 0, 4, 5};
    int n = v.size();
    // BubbleSort(v);
    // selectionSort(v);
    insertionSort(v);
    for (auto it : v)
    {
        cout << it << ' ';
    }
    return 0;
}