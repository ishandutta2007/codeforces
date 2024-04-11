#include <bits/stdc++.h>
using namespace std;
int test;
vector<long long> v;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n;
        v.assign(n, 0);
        for(int i=0; i<n; i++)
        {
            int szam;
            cin>>szam;
            v[szam-1]++;
        }
        sort(v.begin(), v.end());
        long long c=v.back();
        long long ans=0;
        for(int i=n-1; i>=0; i--)
        {
            c=min(c, v[i]);
            ans+=c;
            c--;
            if(c<=0) break;
        }
        cout<<ans<<endl;
    }

    return 0;
}