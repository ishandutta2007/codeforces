#include <bits/stdc++.h>
using namespace std;
#define F first
#define S first
long long n;
long long v[100009];
long long t[100009];
set<pair<long long, int> > w;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>v[i];
    }
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
    }
    long long mag=0;
    for(int i=1; i<=n; i++)
    {
        long long ans=0;
        w.insert({v[i]+mag, i});
        while(w.size()>0 && (w.begin()->F)<=mag+t[i])
        {
            ans+=((w.begin()->F)-mag);
            //cout<<ans<<" *"<<endl;
            w.erase(w.begin());
        }
        ans+=t[i]*(w.size());
        cout<<ans<<" ";
        mag+=t[i];
    }
    cout<<endl;
    return 0;
}