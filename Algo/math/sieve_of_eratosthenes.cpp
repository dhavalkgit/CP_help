#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n+1,1);
    v[0]=v[1]=0;
    for(int i=2;i*i<=n;i++){
        if(v[i]){
            for(int j=i*i;j<=n;j+=i){
                v[j]=0;
            }
        }
    }
    for(int i=0;i<=n;i++){
        if(v[i]==1){
            cout<<i<<" ";
        }
    }
    return 0;
}