#include<bits/stdc++.h>
#define mo 1000000007
#define N 100005
using namespace std;
int head[N],hsh[N];
int tot,n,ans,cnt,mx;
struct edge{int to,next;}e[N*2];
map<int,int> mp;
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
int calc(int x){
	return 1ll*x*x%mo*x%mo;
}
void dfs(int x,int fa){
	hsh[x]=19260817;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			dfs(e[i].to,x);
			hsh[x]=(hsh[x]+calc(hsh[e[i].to]))%mo;
		}
	if (x!=1){
		if (!mp[hsh[x]]) cnt++;
		mp[hsh[x]]++;
	}
}
void work(int x,int fa,int Hsh){
	if (!(--mp[hsh[x]])) cnt--;
	if (!(mp[Hsh]++)) cnt++;
	int tmp=(hsh[x]+calc(Hsh))%mo;
	if (cnt>mx) mx=cnt,ans=x;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa)
			work(e[i].to,x,(tmp+mo-calc(hsh[e[i].to]))%mo);
	if (!(mp[hsh[x]]++)) cnt++;
	if (!(--mp[Hsh])) cnt--;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	ans=1;
	mx=cnt;
	for (int i=head[1];i;i=e[i].next)
		work(e[i].to,1,(hsh[1]+mo-calc(hsh[e[i].to]))%mo);
	printf("%d\n",ans);
}