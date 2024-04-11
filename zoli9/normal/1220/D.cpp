#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;
int v2[200009];
ll t[200009];
int db[68];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        ll s;
        cin>>s;
        t[i]=s;
        ll j=1;
        int cnt=0;
        while(s%j==0)
        {
            j*=2;
            cnt++;
        }
        cnt--;
        db[cnt]++;
        v2[i]=cnt;
    }
    int mh=0;
    for(int i=0; i<65; i++)
    {
        if(db[i]>db[mh]) mh=i;
    }
    cout<<n-db[mh]<<'\n';
    for(int i=1; i<=n; i++)
    {
        if(v2[i]!=mh) cout<<t[i]<<" ";
    }
    cout<<'\n';


    return 0;
}