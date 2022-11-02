#include <bits/stdc++.h>
using namespace std;
int n;
int k;
int a[100009];
int b[100009];
int t[100009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1; i<=k; i++)
    {
        cin>>t[i];
        if(a[t[i]]==0) a[t[i]]=i;
        b[t[i]]=i;
    }
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        if(b[i]==0) ans++;
        if(i>1)
        {
            if(b[i]==0 || b[i-1]==0)
            {
                ans++;
            }
            else if(b[i]<a[i-1]) ans++;
        }
        if(i<n)
        {
            if(b[i]==0 || b[i+1]==0)
            {
                ans++;
            }
            else if(b[i]<a[i+1]) ans++;
        }
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}