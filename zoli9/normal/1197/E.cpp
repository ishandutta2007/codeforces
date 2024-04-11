#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
int n, k;
vector<pii> pontok;
int ujertek;
int kezdmax;
vector<int> kezd, veg;
ll legjobb[400009];
ll legdb[400009];
ll MOD=1e9+7;
vector<ll> tav;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int kk, vv;
        cin>>vv>>kk;
        pontok.push_back({kk, i});
        pontok.push_back({vv, i+n});
    }
    sort(pontok.begin(), pontok.end());
    kezd.resize(n);
    veg.resize(n);
    tav.push_back(0);
    for(int i=0; i<2*n; i++)
    {
        if(i==0 || pontok[i].F!=pontok[i-1].F)
        {
            tav.push_back(pontok[i].F);
            ujertek++;
        }
        if(pontok[i].S<n)
        {
            kezd[pontok[i].S]=ujertek;
            kezdmax=ujertek;
        }
        else
        {
            veg[pontok[i].S-n]=ujertek;
        }
    }
    for(int i=1; i<=2*n; i++)
    {
        legjobb[i]=1e12;
    }
    int cnt=0;
    legdb[0]=1;


    for(int i=0; i<2*n; i++)
    {
        if(pontok[i].S<n)
        {
            while(cnt<kezd[pontok[i].S])
            {
                ll tavd=tav[cnt+1]-tav[cnt];
                if(legjobb[cnt]+tavd<legjobb[cnt+1])
                {
                    legjobb[cnt+1]=legjobb[cnt]+tavd;
                    legdb[cnt+1]=legdb[cnt];
                }
                else if(legjobb[cnt]+tavd==legjobb[cnt+1])
                {
                    legdb[cnt+1]=(legdb[cnt+1]+legdb[cnt])%MOD;
                }
                cnt++;
            }
            int idx=pontok[i].S;
            int k=kezd[idx];
            int v=veg[idx];
            if(legjobb[k]<legjobb[v])
            {
                legjobb[v]=legjobb[k];
                legdb[v]=legdb[k];
            }
            else if(legjobb[k]==legjobb[v])
            {
                legdb[v]=(legdb[v]+legdb[k])%MOD;
            }
        }
    }
    ll minimum=1e12;
    for(int i=kezdmax+1; i<=ujertek; i++)
    {
        minimum=min(minimum, legjobb[i]);
    }
    ll ans=0;
    for(int i=kezdmax+1; i<=ujertek; i++)
    {
        if(legjobb[i]==minimum)
        {
            ans=(ans+legdb[i])%MOD;
        }
    }
    cout<<ans<<endl;



    return 0;
}