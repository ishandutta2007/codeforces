#include<bits/stdc++.h>
#define ll long long
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define base 127
#define N 500100
#define M1 1000000007
#define M2 1000000009
using namespace std;

ll n,m,K,b[N],pos[N];
P qz[N],bas[N],qt[N];
char S[N],T[N];

P operator + (const P &u,const ll &v){return mp((u.fi+v)%M1,(u.se+v)%M2);}
P operator - (const P &u,const P &v){return mp((u.fi-v.fi+M1)%M1,(u.se-v.se+M2)%M2);}
P operator * (const P &u,const ll &v){return mp(u.fi*v%M1,u.se*v%M2);}
P operator * (const P &u,const P &v){return mp(u.fi*v.fi%M1,u.se*v.se%M2);}
inline P get(ll u,ll v){return qz[v]-qz[u-1]*bas[v-u+1];}
inline P gt(ll u,ll v){return qt[v]-qt[u-1]*bas[v-u+1];}

int main()
{
    ll i,j,p,q;
    cin>>n>>m>>K;
    scanf("%s%s",S+1,T+1);
    bas[0]=mp(1,1);
    for(i=1;i<=n;i++)
    {
	bas[i]=bas[i-1]*base;
	qz[i]=qz[i-1]*base+S[i];
    }
    for(i=1;i<=m;i++) qt[i]=qt[i-1]*base+T[i];
    for(i=1;i<=n-m+1;i++) if(get(i,i+m-1)==qt[m]) break;
    if(i<=n-m+1)
    {
	p=max(1ll,i+m-2*K);
	q=p+K;
	puts("Yes");
	cout<<p<<" "<<q;
	return 0;
    }
    p=K,q=0;
    for(i=1;i<=min(K,m);i++) if(get(n-K+1,n-K+i)==gt(m-i+1,m)) p=min(p,i),q=max(q,i);
    for(i=1,j=n-K+1;i<=min(m,K);i++)
    {
//	if(i>p && i<q) continue;
	if(i==p || i==q) j=n-K+1;
	for(;j>=1&&get(j,j+i-1)!=gt(m-i+1,m);j--);
	pos[i]=j;
    }
//    for(i=1;i<=m;i++) cout<<pos[i]<<" ";return 0;
    p=K,q=0;
    for(i=1;i<=min(K,m);i++) if(get(K-i+1,K)==gt(1,i)) p=min(p,i),q=max(q,i);
    for(i=j=1;i<=min(m,K);i++)
    {
//	if(i>p && i<q) continue;
	if(i==p || i==q) j=1;
	for(;j<=n-K*2+1&&get(j+K-i,j+K-1)!=qt[i];j++);
//	cerr<<i<<"  "<<j<<endl;
	if(!pos[m-i] || j+K>pos[m-i]) continue;
	puts("Yes");
	cout<<j<<" "<<pos[m-i];
	return 0;
    }
    puts("No");
}