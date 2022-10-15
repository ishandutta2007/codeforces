#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0; i<n ; i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

#define REP(i,n) for (int i = 1; i <= n; i++)
#define ll long long
#define mod (ll)(1e9+7)

long long int multiply(long long int a,long long int  b,long long int MOD)
{
    ll r = a*b%MOD;
    if(r<0)r+=MOD;
    return r;
}

long long power(ll a,ll b)
{
    long long ret=1;
    while(b>0)
    {
        if(b%2==1)
           ret=(ret*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return ret;
}

long long fact[200001],invfact[200001];

long long ways(int n,int m)
{
    return (((fact[n+m-2]*invfact[n-1])%mod)*invfact[m-1])%mod;
}

long long answers[2001];

int main()
{
    fact[0]=1;
    fact[1]=1;
    invfact[0]=invfact[1]=1;

    for(int i=2; i<=200000; i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
        invfact[i]=(power(fact[i],mod-2));
    }

    int t=1;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;

        long long total=ways(n,m);
        
        memset(answers,0,sizeof(answers));
        int x,y;
        vector < pair < int ,int > > arr;

        for(int i=0; i<k; i++)
        {
            cin>>x>>y;
            arr.pb(mp(x,y));
        }
        sort(arr.begin(),arr.end());

        for(int i=0; i<k; i++)
        {
            long long X=ways(arr[i].first,arr[i].second);
            long long Y=ways(n-arr[i].first+1,m-arr[i].second+1);
            // X is number of ways to reach (x,y) from (1,1)
            // Y is number of ways to reach (n,m) from (x,y)

            for(int j=0; j<i; j++)
            {
                //Find all those which affect me - 
                if(arr[j].first<=arr[i].first && arr[j].second<=arr[i].second)
                {
                    //answer[j] is the answer with the restrictions
                    //ways(arr[i].first-arr[j].first+1,arr[i].second-arr[j].second+1) is number of ways to reach (x,y) from jth point
                    long long val=answers[j];
                    X-=(val*ways(arr[i].first-arr[j].first+1,arr[i].second-arr[j].second+1))%mod;

                    if(X<0)
                        X+=mod;
                }
            }
            
            answers[i]=(X)%mod;
            //answer[j] is number of ways to reach ith point from 1,1 with restrictions
            //update answer
            total=total-(X*Y)%mod;
            if(total<0)
                total+=mod;
        }
        cout<<total<<endl;
    }

    return 0;
}