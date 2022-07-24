#include<bits/stdc++.h>
using namespace std;
void Subset(int ind,vector<int> nums,vector<vector<int>> &ans,vector<int> &ds){
    ans.push_back(ds);
    for(int i=ind;i<nums.size();i++){
        if(i!=ind && nums[i]==nums[i-1]){
            continue;
        }
        ds.push_back(nums[i]);
        Subset(i+1,nums,ans,ds);
        ds.pop_back();
    }
}
vector<vector<int>> subsetWithoutDup(vector<int> &nums){
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(),nums.end());
    Subset(0,nums,ans,ds);
    return ans;
}
int main(){
    vector<int> nums={1,2,3};
    vector<vector<int>> ans=subsetWithoutDup(nums);
    for(int i=0;i<ans.size();i++){
           cout << " { ";
        for(int j=0;j<ans[i].size();j++){
            cout <<  ans[i][j] << " " ;
        }
        cout << "}" << endl;
    }
}