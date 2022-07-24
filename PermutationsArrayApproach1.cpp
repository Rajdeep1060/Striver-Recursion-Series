#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> ans){
    for(int i=0;i<ans.size();i++){
        cout << "{";
        for(int j=0;j<ans[i].size();j++){
          cout << ans[i][j] << " ";
        }
        cout << "}" << endl;
    }
}
void findPermu(vector<int> nums,vector<vector<int>> &ans,vector<int> &ds,int freq[]){
       if(ds.size()==nums.size()){
        ans.push_back(ds);
        return;
       }
       for(int i=0;i<nums.size();i++){
        if(!freq[i]){
            freq[i]=1;
            ds.push_back(nums[i]);
            findPermu(nums,ans,ds,freq);
            ds.pop_back();
            freq[i]=0;
        }
       }
}
vector<vector<int>> Permutation(vector<int> nums){
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[nums.size()]={0};
    findPermu(nums,ans,ds,freq);
    return ans;
}
int main(){
    vector<int> nums={1,2,3};
    vector<vector<int>> ans=Permutation(nums);
    print(ans);
}