#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
vector<pii> v;
ll MOD=998244353;
int n;
ll darab1[300009];
ll darab2[300009];
ll fact[300009];
ll ans1=0, ans2=0, ans12=0;
map<pii, int> d12;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    v.resize(n);
    fact[0]=1;
    for(int i=0; i<n; i++)
    {
        cin>>v[i].F>>v[i].S;
        darab1[v[i].F]++;
        darab2[v[i].S]++;
        d12[v[i]]+=1;
        fact[i+1]=(fact[i]*(ll)(i+1))%MOD;
        //cout<<fact[i+1]<<endl;
    }
    ans1=1;
    ans2=1;
    for(int i=1; i<=n; i++)
    {
        ans1=(ans1*fact[darab1[i]])%MOD;
        ans2=(ans2*fact[darab2[i]])%MOD;
    }
    sort(v.begin(), v.end());
    bool jo=true;
    for(int i=1; i<v.size(); i++)
    {
        if(v[i].F<v[i-1].F || v[i].S<v[i-1].S)
        {
            jo=false;
            break;
        }
    }
    if(jo)
    {
        ans12=1;
        for(auto it: d12)
        {
            ans12=(ans12*fact[it.S])%MOD;
        }
    }
    ll bad=(ans1+ans2-ans12+MOD)%MOD;
    ll good=(fact[n]-bad+MOD)%MOD;
    cout<<good<<endl;
    return 0;
}