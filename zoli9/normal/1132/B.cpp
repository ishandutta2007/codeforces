#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    long long sum=0;
    for(int i=0; i<n; i++)
    {
        long long szam;
        cin>>szam;
        a.push_back(szam);
        sum+=szam;
    }
    sort(a.begin(), a.end());
    int m;
    cin>>m;
    for(int i=0; i<m; i++)
    {
        int ssz;
        cin>>ssz;
        cout<<sum-a[a.size()-ssz]<<endl;
    }
    return 0;
}