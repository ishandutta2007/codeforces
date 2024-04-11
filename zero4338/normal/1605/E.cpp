#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=2e5+5;
int n,q,a[maxn],b[maxn];
struct line
{
	ll k,b;
	line operator -(const line &x)const{return {k-x.k,b-x.b};}
	ll val(int x){return k*x+b;}
}p[maxn],p1[maxn],p2[maxn];int cnt1,cnt2;
ll prek1[maxn],preb1[maxn],prek2[maxn],preb2[maxn];
pair<int,int>ask[maxn];
ll ans[maxn],bas;
int main()
{
	n=read();generate_n(a+1,n,read);generate_n(b+1,n,read);
	p[1].k=1;for(int i=2;i<=n;i++)p[i].b=a[i]-b[i];
	for(int i=1;i<=n;i++)for(int j=2*i;j<=n;j+=i)p[j]=p[j]-p[i];
	for(int i=1;i<=n;i++)
	{
		if(p[i].k>0)p1[++cnt1]=p[i];
		else if(p[i].k<0)p2[++cnt2]=p[i];
		else bas+=abs(p[i].b);
	}
	sort(p1+1,p1+cnt1+1,[](line &i,line &j){return 1.0*i.b*j.k>1.0*j.b*i.k;});
	sort(p2+1,p2+cnt2+1,[](line &i,line &j){return 1.0*i.b*j.k>1.0*j.b*i.k;});
	for(int i=1;i<=cnt1;i++)prek1[i]=prek1[i-1]+p1[i].k,preb1[i]=preb1[i-1]+p1[i].b;
	for(int i=1;i<=cnt2;i++)prek2[i]=prek2[i-1]+p2[i].k,preb2[i]=preb2[i-1]+p2[i].b;
	q=read();
	for(int i=1;i<=q;i++)ask[i]={a[1]-read(),i};
	sort(ask+1,ask+q+1);
	int np1=0,np2=0;
	for(int i=1;i<=q;i++)
	{
		while(np1<cnt1&&p1[np1+1].val(ask[i].first)>=0)np1++;
		while(np2<cnt2&&p2[np2+1].val(ask[i].first)<=0)np2++;
		ans[ask[i].second]=
		+preb1[np1]+prek1[np1]*ask[i].first
		-preb1[cnt1]+preb1[np1]-(prek1[cnt1]-prek1[np1])*ask[i].first
		-preb2[np2]-prek2[np2]*ask[i].first
		+preb2[cnt2]-preb2[np2]+(prek2[cnt2]-prek2[np2])*ask[i].first
		+bas;
	}
	for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
	return 0;
}//