#include <bits/stdc++.h>
using namespace std;

// To execute C++, please define "int main()"
int main() {
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
  int k=100;
  while(k>1){
    if(v[k]==1){
      cout<<k<<" ";
      k=k/k;
    }
    else{
    cout<<v[k]<<" ";
    k=k/v[k];
    }
  }
  return 0;
}
