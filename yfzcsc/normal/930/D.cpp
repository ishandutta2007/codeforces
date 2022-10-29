#include<bits/stdc++.h>
#define maxn 201000
using namespace std;
typedef pair<int,int> par;
const int inf=1000000007;
const int N=201000;
int n;
long long ans=0;
par pre[maxn<<2],suf[maxn<<2];
void upd(par& p,int z){p.first=min(p.first,z),p.second=max(p.second,z);}
void upd(par& p,par q){p.first=min(p.first,q.first),p.second=max(p.second,q.second);}
int main(){
	scanf("%d",&n);
	for(int i=0;i<=N*2;++i)pre[i]=suf[i]=par(inf,-inf);
	for(int i=1,x,y;i<=n;++i){
		scanf("%d%d",&x,&y);
		upd(pre[x+y+N],x-y);
		upd(suf[x+y+N],x-y);
	}
	for(int i=2;i<=N*2;++i)
		upd(pre[i],pre[i-2]);
	for(int i=N*2-2;i>=0;--i)
		upd(suf[i],suf[i+2]);
	for(int i=1;i<=N*2;++i)
		ans+=max(0,min(pre[i-1].second,suf[i+1].second)-max(pre[i-1].first,suf[i+1].first))>>1;
//		printf("{%d,%d}",pre[i-1].second,suf[i+1].second);
	printf("%lld",ans);
}