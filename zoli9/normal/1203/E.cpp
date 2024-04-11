#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    v.resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    int ans=0;
    int utolso=0;
    for(int i=0; i<n; i++)
    {
        if(v[i]-1>utolso)
        {
            ans++;
            utolso=v[i]-1;
            continue;
        }
        if(v[i]>utolso)
        {
            ans++;
            utolso=v[i];
            continue;
        }
        if(v[i]+1>utolso)
        {
            ans++;
            utolso=v[i]+1;
            continue;
        }
    }
    cout<<ans<<endl;
    return 0;
}