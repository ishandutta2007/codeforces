#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Mt=100000;
inline char getc(){
	static char buf[Mt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mt,stdin),p1==p2)?EOF:*p1++;
}
inline ll read(){
	ll r=0,f=1;char c=getc();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getc();}
	while(c<='9'&&c>='0') r=(r<<1)+(r<<3)+c-'0',c=getc();
	return r*f;
}
const int N=4e5+7;
struct node{
	ll l,r;
	int id;
	bool operator <(const node &q) const {return l^q.l?l<q.l:r>q.r;}
}b[N<<1];
int cnt,m;
bool vis[N];
ll n,k,K,L,R,a[N];
inline ll check(ll x,bool op){
	ll res=0;
	for(int i=1;i<=m;i++)res+=(a[i]+op*(x-1))/x;
	return res;
}
inline void work(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)a[i]=read();
	a[++m]=n,K=m+k;
	for(int i=m;i;i--)a[i]-=a[i-1],vis[i]=0;
	ll l=1,r=*min_element(a+1,a+m+1);
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid,0)>=K)l=mid+1;
		else r=mid-1;
	}
	L=r,l=1,r=*max_element(a+1,a+m+1);
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid,1)<=K)r=mid-1;
		else l=mid+1;
	}
	R=l,cnt=0;
	for(int i=1;i<=m;i++){
		ll dl=a[i]/L,dr=(a[i]+R-1)/R;
		if(dl<dr){
			b[++cnt]={min(L,a[i]/(dl+1)),R,i};
			if(dr>1)b[++cnt]={L,max(R,(a[i]+dr-2)/(dr-1)),i};
			else vis[i]=1;
		}
	}
	sort(b+1,b+cnt+1);
	if(!cnt)return (void)printf("%lld\n",R-L);
	ll ans=-1e18,Max=R;
	int p=cnt;
	for(int i=1;i<=cnt;i++){
		ans=max(ans,b[i].l-Max);
		while(p && !vis[b[i].id])
			vis[b[p].id]=1,Max=max(Max,b[p--].r);
	}
	printf("%lld\n",-ans);
}
int main(){
    int test=read();
    while(test--)work();
	return 0;
}