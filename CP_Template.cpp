#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define re cin >>
#define op cout <<
#define ll long long int

#define vi vector<int>
#define vll vector<long long int>
#define mii map<int, int>
#define mci map<char, int>
#define mil map<int, long long int>
#define mll map<long long, long long>
#define msll multiset<long long int>
#define pi pair<int, int>
#define _s set<int>
#define mpq priority_queue<int, vector<int>, greater<int>>

#define pb(x) push_back(x)
#define ppb pop_back()
#define be(x) begin(x)
#define en(x) end(x)

#define flp(i, s, e) for (int i = s; i < e; i++)
#define rlp(i, s, e) for (int i = s - 1; i >= e; i--)
#define _test \
    int t;    \
    cin >> t; \
    while (t--)
#define no cout << "NO" << '\n';
#define yes cout << "YES" << '\n';

#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

template <class T>
void _print(T x) { cerr << x; }
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T el : v)
    {
        _print(el);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> st)
{
    cerr << "[ ";
    for (T el : st)
    {
        _print(el);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> st)
{
    cerr << "[";
    for (T el : st)
    {
        _print(el);
        cerr << " ";
    }
    cerr << "]";
}

void solve(vector<bool>&visi, vector<int>&a, string &s, int &count, int node,vector<int>&ans){
    if(visi[node]) return;

    visi[node]=true;
    if(s[node-1]=='0') count++;
    solve(visi,a,s,count,a[node],ans);

    ans[node]=count;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio;
    _test
    {
       // your code goes here 
    }
    return 0;
}

