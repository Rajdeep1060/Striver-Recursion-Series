#include<bits/stdc++.h>
using namespace std;

void Subsequence(int index,int arr[],vector<int> &ans,int n){
    if(index==n){

        for(auto it:ans){
            cout << it << " ";
        }
        
        if(ans.size()==0){
            cout << "{} ";
        }

        cout << endl;
        return;
    }
     Subsequence(index+1,arr,ans,n);
    ans.push_back(arr[index]);
    Subsequence(index+1,arr,ans,n);
    ans.pop_back();
}
int main(){
    int arr[3];
    for(int i=0;i<3;i++){
        cin >> arr[i];
    }
    vector<int> ans;
    Subsequence(0,arr,ans,3);
    return 0;
}
//TC:-O(2^n);