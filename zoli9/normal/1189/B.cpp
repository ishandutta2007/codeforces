#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    sort(v.begin(), v.end());
    if(v[n-3]+v[n-2]<=v[n-1])
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(int i=0; i<=n-3; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<v[n-1]<<" "<<v[n-2]<<endl;
    return 0;
}