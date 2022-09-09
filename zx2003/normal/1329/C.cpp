#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>P;
priority_queue<P>q;
const int N=11e5;
int T,h,g,i,a[N],b[N],xb,n,mxc[N],bot[N],dep[N];
long long ans;
void upd(int i){
	mxc[i]=i<<1|(a[i<<1]<=a[i<<1|1]);
	bot[i]=a[mxc[i]]?bot[mxc[i]]:dep[i];
}
void f(int i){
	if(i>n/2 || !a[i]){a[i]=0;return;}
	a[i]=a[mxc[i]];f(mxc[i]);upd(i);
}
void f2(int i){
	if(i>n/2 || !a[i])return;
	f2(mxc[i]);
	if(a[mxc[i]^1])q.push({a[mxc[i]^1],mxc[i]^1});
}
int main(){
	for(i=1;i<N;++i)dep[i]=dep[i>>1]+1;
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&h,&g);
		n=(1<<h)-1;
		for(i=1;i<=n;++i)scanf("%d",a+i);
		for(i=n;i>n/2;--i)bot[i]=dep[i];
		for(;i;--i)upd(i);
		q.push({a[1],1});
		xb=0;
		for(;!q.empty();){
			int x,y;tie(x,y)=q.top();q.pop();
			if(bot[y]==g){f2(y);continue;}
			b[++xb]=y;
			f(y);if(bot[y]==g)f2(y);else q.push({a[y],y});
		}
		ans=0;for(i=1;i<=(1<<g)-1;++i)ans+=a[i];
		printf("%lld\n",ans);
		for(i=1;i<=xb;++i)printf("%d%c",b[i],i==xb?'\n':' ');
	}
}