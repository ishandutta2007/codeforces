#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

ll m;
int n;
vector<pair<ll, pii>> a;
vi sum;
ll osszeg[400009];
int anspair[400009];

ll pos=0;
ll neg=0;
ll ans;
ll anssum;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>m>>n;
    a.resize(2*n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i].F;
        a[i].S.F=1;
        a[i].S.S=i+1;
    }
    for(int i=n; i<2*n; i++)
    {
        cin>>a[i].F;
        a[i].S.F=-1;
        a[i].S.S=i-n+1;
    }
    sort(a.begin(), a.end());
    for(int i=0; i<2*n; i++)
    {
        if(i==0) sum.push_back(a[0].S.F);
        else sum.push_back(sum.back()+a[i].S.F);
        ll lgt;
        if(i==2*n-1) lgt=(m+a[0].F-a[2*n-1].F);
        else lgt=(a[i+1].F-a[i].F);
        int sb=sum.back();
        osszeg[sb+n]+=lgt;
        if(sb>0)
        {
            anssum+=((ll)(sb)*lgt);
            pos+=lgt;
        }
        else if(sb<0)
        {
            anssum-=((ll)(sb)*lgt);
            neg+=lgt;
        }
    }
    ans=anssum;
    int typesum=0;
    int beststart=0;
    for(int i=0; i<2*n-1; i++)
    {
        if(a[i].S.F==1)
        {
            typesum++;
            anssum-=pos;
            neg+=osszeg[typesum-1+n];
            pos-=osszeg[typesum+n];
            anssum+=neg;
        }
        else
        {
            typesum--;
            anssum-=neg;
            neg-=osszeg[typesum+n];
            pos+=osszeg[typesum+1+n];
            anssum+=pos;
        }
        if(anssum<ans)
        {
            ans=anssum;
            beststart=i+1;
        }
    }
    int cnt=beststart;
    for(int pl=0; pl<2*n; pl++)
    {
        int i=(beststart+pl)%(2*n);
        if(a[i].S.F==1)
        {
            while(a[cnt].S.F==1)
            {
                cnt++;
                cnt%=(2*n);
            }
            anspair[a[i].S.S]=a[cnt].S.S;
            cnt++;
            cnt%=(2*n);
        }
    }
    cout<<ans<<endl;
    for(int i=1; i<=n; i++) cout<<anspair[i]<<" ";
    cout<<endl;

    return 0;
}