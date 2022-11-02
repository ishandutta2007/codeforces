#include <bits/stdc++.h>
using namespace std;

long long n, q;
long long t[1000009];
long long maxip;
long long a1[1000009];
long long a2[1000009];
vector<long long> v;
long long mmm;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>q;

    maxip=1;

    for(int i=1; i<=n; i++)
    {
       cin>>t[i];
       if(t[i]>t[maxip]) maxip=i;
    }
    mmm=t[maxip];

    int sk=1;
    int sv=n;

    for(int i=1; i<=n; i++)
    {
        a1[i]=t[sk];
        a2[i]=t[sk+1];
        long long AA=min(t[sk], t[sk+1]);
        long long AB=max(t[sk], t[sk+1]);
        sk++;
        t[sk]=AB;
        sv++;
        t[sv]=AA;
    }
    for(long long i=sk+1; i<=sv; i++)
    {
        v.push_back(t[i]);
    }
    for(int i=1; i<=q; i++)
    {
        long long que;
        cin>>que;
        if(que<=n)
        {
            cout<<a1[que]<<" "<<a2[que]<<endl;
        }
        else
        {
            cout<<mmm<<" "<<v[(que-n-1)%(n-1)]<<endl;
        }
    }

    return 0;
}