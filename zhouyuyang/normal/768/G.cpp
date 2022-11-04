#include<bits/stdc++.h>
#define N 100005
using namespace std;
vector<int> e[N];
int sz[N],ans[N];
map<int,int> mpo,mpf,mpc;
int n,rt;
void predfs(int x){
	sz[x]=1;
	for (auto y:e[x])
		predfs(y),sz[x]+=sz[y];
	mpo[sz[x]]++;
}
void add(map<int,int> &mp,int a,int b){
	mp[a]+=b;
	if (!mp[a]) mp.erase(a);
}
void change(int x,int d,int fa){
	add(mpc,sz[x],d);
	add(mpo,sz[x],-d);
	for (auto y:e[x])
		if (y!=fa) change(y,d,fa);
}
int ask(map<int,int> &m,int l,int r,int L,int R){
	int ans=n-1;
	for (;l<=r;){
		int mid=(l+r)/2;
		if (L-mid>mid+R){
			l=mid+1;
			continue;
		}
		map<int,int>::iterator it;
		it=m.lower_bound(L-mid);
		if (it!=m.end()&&(*it).first<=mid+R)
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
void dfs(int x,int tg){
	add(mpf,sz[x],1);
	add(mpo,sz[x],-1);
	int mx=0,mn=n,bg=0,smx=0;
	for (auto y:e[x]){
		if (mx<sz[y]) smx=mx,mx=sz[y],bg=y;
		else smx=max(smx,sz[y]);
		mn=min(mn,sz[y]);
	}
	for (auto y:e[x])
		if (y!=bg) dfs(y,0);
	if (bg) dfs(bg,1);
	ans[x]=max(mx,n-sz[x]);
	if (sz[x]!=n) mn=min(mn,n-sz[x]);
	if (n-sz[x]<=mx){
		smx=max(smx,n-sz[x]);
		ans[x]=min(ans[x],ask(mpc,mn,mx,mx,-mn));
	}
	change(x,1,bg);
	add(mpo,sz[x],1);
	if (n-sz[x]>mx){
		smx=mx;
		ans[x]=min(ans[x],ask(mpo,mn,n-sz[x],n-sz[x],-mn));
		ans[x]=min(ans[x],ask(mpf,mn,n-sz[x],n,sz[x]-mn));
	}
	ans[x]=max(ans[x],smx);
	add(mpf,sz[x],-1);
	if (!tg) change(x,-1,0);
} 
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if (!x) rt=y;
		else e[x].push_back(y);
	}
	predfs(rt);
	dfs(rt,0);
	for (int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
}