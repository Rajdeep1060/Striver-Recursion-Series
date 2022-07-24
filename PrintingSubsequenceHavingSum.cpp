#include<bits/stdc++.h>
using namespace std;
//if the ques demands only 1 sub sequence in the answer
bool printOnlyOne(int ind,int arr[],int s,int n,int sum,vector<int> &ds){
         if(ind ==n){
            if(s==sum){
          for(auto it:ds){
            cout << it << " ";
          }
          cout << endl;
          return true;
            }
            return false;
         }
         ds.push_back(arr[ind]);
         s+=arr[ind];
         if(printOnlyOne(ind+1,arr,s,n,sum,ds)==true){
          return true;
         }

         s-=arr[ind];
         ds.pop_back();
        if(printOnlyOne(ind+1,arr,s,n,sum,ds)==true){
          return true;
        }
        return false;
}
//if the ques demands all answers
void printAll(int ind,int arr[],int s,int n,int sum,vector<int> &ds){
      if(ind==n){
        if(s==sum){
          for(auto it:ds){
            cout << it << " ";
          }
          cout << endl;
        }
        return;
      }
      ds.push_back(arr[ind]);
      s+=arr[ind];
      printAll(ind+1,arr,s,n,sum,ds);
      
      s-=arr[ind];
      ds.pop_back();
      printAll(ind+1,arr,s,n,sum,ds);
}
//if ques demands only count of subsequences
int printNumber(int ind,int arr[],int s,int sum,int n){
       if(ind==n){
        if(s==sum){
          return 1;
        }
        return 0;
       }
       s+=arr[ind];
       int l=printNumber(ind+1,arr,s,sum,n);
       s-=arr[ind];
       int r=printNumber(ind+1,arr,s,sum,n);
       return l+r;
}
int main(){
    int arr[]={1,2,1};
    int n=3;
    int sum=2;
    vector<int> ds;
    printAll(0,arr,0,n,sum,ds);
}
//time complexity:-O(2^n);