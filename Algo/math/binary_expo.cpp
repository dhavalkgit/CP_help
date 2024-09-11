#include<bits/stdc++.h>
using namespace std;
int main()
{
    int base, n;
    int res=1;
    cin>>base>>n;
    while(n){
        if(n%2){
            res*=base;
            n--;
        }
        else{
            base*=base;
            n/=2;
        }
    }
    cout<<res<<endl;
    return 0;
}