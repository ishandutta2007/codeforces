//
//  main.cpp
//  CoPr
//
//  Created by Ahmad Shallouf on 22/12/15.
//  Copyright  2015 Ahmad Shallouf. All rights reserved.
//
#include<iostream>
#include<map>
#include<cmath>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<stack>
#include<bitset>
#include<math.h>
#include<set>
#include<string>
#include<cstring>
#include<queue>
#include<complex>
#include<math.h>
#include<memory.h>
#include<sstream>
#include<cstdio>
#include <iterator>
using namespace std;
#define All(a) a.begin(), a.end()
#define _2d(a,row,col,type) type**a=new type*[row]; for (int i=0;i<row;i++) a[i]=new type[col];
#define rep(i,n) for(int i=0;i<int(n);i++)
#define repd(i,n) for(int i=n-1;i>=0;i--)
#define repi(i,a,n) for(int i=int(a);i<int(n);i++)
#define clr(a, n) memset(a, n, sizeof(a));
#define scn(a,n) rep(i,n) cin>>a[i];
#define scn2(a,row,col) rep(i,row) rep(j,col) cin>>a[i][j];
#define prn(a,n) rep(i,n-1) cout<<a[i]<<" "; cout<<a[n-1]<<endl;
#define prn2(a,row,col) rep(i,row){rep(j,col-1) cout<<a[i][j]<<" "; cout<<a[i][col-1]<<endl;}
#define mp make_pair
#define Odd(x) (x&1)
#define Even(x) (!Odd(x))
#define Pi M_PI
#define MOD 1000000007
#define F first
#define S second
#define INF INT_MAX // 2 billion
#define read freopen("in.in","r",stdin)
#define write freopen("out.out","w",stdout)
#define geti(a) scanf("%d",&a);
#define getll(a) scanf("%lld",&a);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long double ld;
ld dist (pair<ld, ld> a,pair<ld, ld>b){
    return sqrt((a.F-b.F)*(a.F-b.F)+(a.S-b.S)*(a.S-b.S));
}
bool cmp (pair<ll, ll> a,pair<ll, ll>b){
    return false;
}
ll GCD(ll a,ll b){
    if(b==0)return a;
    return GCD(b,a%b);
}
ll bigMod (ll x,ll p){
    if (p == 0) return 1;
    if (p == 1) return x;
    
    if (Even(p)){
        ll temp = bigMod(x, p/2);
        return (temp*temp)%MOD;
    }
    return (x*bigMod(x, p-1))%MOD;
}

ld moddist (pair<ll, ll> st,pair<ll, ll>end,pair<ll, ll> p){
    ld ans = 0;
    ld f =(ld)(end.first-st.first)*(st.second-p.second);
    ld s =(ld)(st.first-p.first)*(end.second-st.second);
    ans = abs((f-s)/dist(st, end));
    return (ans <= 1e-9 ? INF : ans);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<pair<pair<ll, ll>,int> > p (n);
    rep(i, n) cin >> p[i].first.first >> p[i].first.second,p[i].second = i+1;
    sort(p.begin(), p.end());
    repi(i, 2, n)
        if (moddist(p[0].first, p[1].first, p[i].first) < INF-1)
            return cout << p[0].second << " " << p[1].second << " " << p[i].second << endl,0;
    return 0;
}