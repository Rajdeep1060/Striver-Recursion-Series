#include<iostream>
using namespace std;
void print(int n,int k){
    if(n < k){
        return ;
    }
    cout << n << " ";
    print(n-1,k);
}
int main(){
    cout << "enter:- " ;
    int n;
    cin >> n;
    int k;
    cin >> k;
    print(n,k);
    return 0;
}