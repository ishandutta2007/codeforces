#include <iostream>
#include <cstdio>
#include <algorithm>
#define abs(x) ((x)>=0?(x):(-(x)))
using namespace std;
typedef long long ll;
const int M=1005;
const ll INF=1e18;
ll curx,cury,xx0,yy0,ax,ay,bx,by,t;
ll x[M],y[M],cnt=1,ans;
ll dist(ll x1,ll y1,ll x2,ll y2){
	return abs(x1-x2)+abs(y1-y2);
}

namespace BF{
int p[M];
void solve(){
	for(int i=0;i<=cnt;i++) p[i]=i;
	do{
		ll sum=0,res=0;sum+=dist(curx,cury,x[p[0]],y[p[0]]);
		if(sum>t) continue;
		res=1;
		for(int i=1;i<=cnt;i++){
			sum+=dist(x[p[i]],y[p[i]],x[p[i-1]],y[p[i-1]]);
			if(sum>t) break;
			res++;
		}
		ans=max(ans,res);
	}while(next_permutation(p,p+cnt+1));
	cout<<ans<<endl;
}
}

int main(){
	scanf("%lld%lld%lld%lld%lld%lld",&xx0,&yy0,&ax,&ay,&bx,&by);
	scanf("%lld%lld%lld",&curx,&cury,&t);
	x[0]=xx0,y[0]=yy0;
	for(int i=1;;i++,cnt++){
		x[i]=x[i-1]*ax+bx,y[i]=y[i-1]*ay+by;
		if(x[i]-curx+y[i]-cury>t+10&&x[i]>=curx&&y[i]>=cury) break;
	}
	if(cnt<=6){
		BF::solve();
		return 0;
	}
	for(int i=0;i<=cnt;i++){
		ll sum=dist(x[i],y[i],curx,cury),res=1;
		if(sum>t) continue;
		int j;
		for(j=i;j>=1;j--,res++){
			sum+=dist(x[j],y[j],x[j-1],y[j-1]);
			if(sum>t){
				sum-=dist(x[j],y[j],x[j-1],y[j-1]);
				break;
			}
		}
		if(sum<=t){
			sum+=dist(x[j],y[j],x[i+1],y[i+1]);
			if(sum>t) goto ed;
			res++;
			for(j=i+1;j<=cnt;j++,res++){
				sum+=dist(x[j],y[j],x[j+1],y[j+1]);
				if(sum>t) break;
			}
		}
		ed:ans=max(ans,res);
	}
	cout<<ans<<endl;
	return 0;
}