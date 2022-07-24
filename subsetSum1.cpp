#include<bits/stdc++.h>
using namespace std;
void findsubset(int i,int size,int sum,vector<int> &ans,vector<int> arr){
    if(i==size){
      ans.push_back(sum);
        return;
    }
    //pick the element
    findsubset(i+1,size,sum+arr[i],ans,arr);
    //not pick element
    findsubset(i+1,size,sum,ans,arr);
}
vector<int> subsetSum(vector<int> nums,int n){
    vector<int> ans;
    findsubset(0,n,0,ans,nums);
    sort(ans.begin(),ans.end());
    return ans;
}
int main(){
    vector<int> v={1,2,3};
    vector<int> ans=subsetSum(v,v.size());
    for(auto i:ans){
        cout << i << " ";
    }
}
//time complexity:-O(2^n);
//space complexity:-O(n);