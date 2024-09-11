#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v(101,1);
    for(int i=2;i*i<=100;i++){
        if(v[i]==1){
            for(int j=i*i;j<=100;j+=i){
                if(v[j]==1){
                v[j]=i;
                }
            }
        }
    }
    map<int,int>mp;
    int k=100;
    while(k>1){
        if(v[k]==1){
            mp[k]++;
            k=k/k;
        }
        else{
            mp[v[k]]++;
            k=k/v[k];
        }
    }
    for(auto it:mp){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}