#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
#define mk make_pair
#define se second
const int N=1e5+7;
inline ll sqr(ll x){return x*x;}
int n,m,a[N],c[N];
inline ll cal(int i,int c){
	int d=(a[i]+c-1)/c,r=(a[i]-1)%c+1;
	return sqr(d)*r+sqr(d-1)*(c-r);
}
priority_queue<pair<ll,int> >q;
int main(){
	n=read(),m=read()-n;
	for(int i=1;i<=n;i++){
		a[i]=read(),c[i]=1;
		q.push(mk(cal(i,1)-cal(i,2),i));
	}
	while(m--){
		int x=q.top().se;q.pop();
		c[x]++,q.push(mk(cal(x,c[x])-cal(x,c[x]+1),x));	
	}
	ll ans=0;
	for(int i=1;i<=n;i++)ans+=cal(i,c[i]);
	printf("%lld\n",ans);
	return 0;
}