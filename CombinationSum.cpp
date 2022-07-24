#include<bits/stdc++.h>
using namespace std;
void FindCombination(int ind,set<vector<int>> &ans,vector<int> &ds,int target,vector<int> arr){
               if(ind == arr.size()){    //ind==arr.size() because we have to consider all elements of arr
                if(target==0){
                    ans.insert(ds);
                }
                return;     //return so as to stop recursion when ind = arr.size()
               }
               if(arr[ind]<=target){     //take the element(pick choice)
                ds.push_back(arr[ind]);
                FindCombination(ind,ans,ds,target-arr[ind],arr);
                ds.pop_back();     //delete the element for not pick choice
               }
               FindCombination(ind+1,ans,ds,target,arr);    //next element (not pick choice)
}
vector<vector<int>> CombinationSum(vector<int> &arr,int target,int size){
       set<vector<int>> ans;    //set used for unique ans
       vector<int> ds;
       FindCombination(0,ans,ds,target,arr);
       vector<vector<int>> Ans;
    for(auto it:ans){
     Ans.push_back(it);
    }
       return Ans;
}
int main(){
    vector<int> arr={2,2,7,3,4};
     int target=7;
     vector<vector<int>> ans=CombinationSum(arr,target,arr.size());
     for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout <<  ans[i][j] << " ";
        }
        cout << endl;
     }
}