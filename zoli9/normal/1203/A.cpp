#include <bits/stdc++.h>
using namespace std;
int q;
int n;
vector<int> v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>q;
    for(int tt=1; tt<=q; tt++)
    {
        cin>>n;
        v.resize(n);
        bool no=true;
        bool csokken=true;
        for(int i=0; i<n; i++)
        {
            cin>>v[i];
            if(i>0)
            {
                if(v[i]%n!=(v[i-1]+1)%n) no=false;
                if(v[i-1]%n!=(v[i]+1)%n) csokken=false;
            }
        }
        if(v[0]%n!=(v[n-1]+1)%n) no=false;
        if(v[n-1]%n!=(v[0]+1)%n) csokken=false;
        if(no || csokken) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}