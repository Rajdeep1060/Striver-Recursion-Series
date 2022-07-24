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
void findPermu(int ind,vector<vector<int>> &ans,vector<int> nums){
       if(ind>=nums.size()){
        ans.push_back(nums);
        return;
       }
       for(int i=ind;i<nums.size();i++){
       swap(nums[i],nums[ind]);
       findPermu(ind+1,ans,nums);
       swap(nums[ind],nums[i]);
       }
}

vector<vector<int>> Permutation(vector<int> &nums){
    vector<vector<int>> ans;
    findPermu(0,ans,nums);
    return ans;
}
int main(){
    vector<int> nums={1,2,3};
    vector<vector<int>> ans=Permutation(nums);
    print(ans);
}