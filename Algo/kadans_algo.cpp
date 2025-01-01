#include<bits/stdc++.h>
using namespace std;

int kadans(vector<int>&nums){
    int sum = 0;
    int mx = INT_MIN;
    int l = -1, r = -1;  // to get subarray element for given array 
    int st = -1;
    for(int i=0;i<nums.size();i++){
        if(sum==0) st=i;
        sum += nums[i];

        if(sum>mx){
            mx=sum;
            l=st;
            r=i;
        }

        if(sum<0) sum = 0;
    }

    return mx;
}
