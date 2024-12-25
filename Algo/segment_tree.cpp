#include<bits/stdc++.h>
using namespace std;

int a[100000], seg[4*100000];
/*
    here segment tree is finding max element from given range
*/
void build(int ind, int low, int high){
    if(low==high) seg[ind]=a[low];

    int mid = (low+high)/2;

    build(2*ind+1, low, mid);
    build(2*ind+2, mid, high);
    seg[ind]= max(seg[2*ind+1], seg[2*ind+2]);
}

int query(int ind, int low, int high, int l, int h){
    if(low>=l && high<=h){
        return seg[ind];
    }
    if(high<l || low>h) return INT_MIN;
    int mid = (low+high)/2;

    int left = query(2*ind+1, low, mid, l, h);
    int right = query(2*ind+2, mid+1, high, l, h);

    return max(left, right);
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    build(0,0,n-1);
    int m;
    cin>>m;
    while(m--){
        int l, r;
        cin>>l>>r;
        cout<<query(0,0,n-1,l,r)<<endl;
    }
    return 0;
}