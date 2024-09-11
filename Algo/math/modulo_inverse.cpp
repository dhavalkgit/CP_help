#include<bits/stdc++.h>
using namespace std;

int power(int a, int n, int m){
    int res =1;
    while(n){
        if(n%2){
            res = (res*a)%m;
            n--;
        }
        else{
            a = (a*a)%m;
            n/=2;
        }
    }
    return res;
}

int main()
{
    int t,a,m;
    cin>>t;
    while(t--){
        cin>>a>>m;
        cout<<"a^-1 = "<<power(a,m-2,m)<<endl;
    }
    return 0;
}