#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
typedef pair<int,int>pii;
int n,q,i,j,l,r,k,BL;
ll ans[N];
string s[N];
vector<int>id[N];
struct ACM{
int ch[N][26],fail[N],xb,q[N];
inline void ins(char*c,int l,vector<int>&v){
	int u=0,i=0,x;
	v.resize(l);
	for(;i<l;++i){
		x=c[i]-'a';
		if(!ch[u][x])ch[u][x]=++xb;
		v[i]=u=ch[u][x];
	}
}
vector<int>e[N];
int be[N],en[N],dcnt;
void dfs(int x){be[x]=++dcnt;for(int y:e[x])dfs(y);en[x]=dcnt;}
inline void ini(){
	int t=0,w=1,u,i;
	for(;t<w;)for(i=0,u=q[++t];i<26;++i)if(!ch[u][i])ch[u][i]=ch[fail[u]][i];
		else q[++w]=ch[u][i],fail[q[w]]=u?ch[fail[u]][i]:0;
	for(i=1;i<=xb;++i)e[fail[i]].push_back(i);
	dfs(0);
}
inline void solve(const vector<int>&v1,const vector<pii>&v2){
	static ll su[N];static int v[N];int i;
	memset(v,0,xb+1<<2);
	for(int x:v1)v[x]=1;
	for(i=xb+1;i;--i)v[fail[q[i]]]+=v[q[i]];
	for(i=1;i<=n;++i)su[i]=v[id[i].back()]+su[i-1];
	for(pii u:v2)ans[abs(u.second)]+=(u.second>0?1:-1)*su[u.first];
}
}A;
vector<pii>qu1[N],qu2[N];
struct block{
static const int M=350;
int be[M],en[M],bel[M],bl,tg[N],a[N];
inline void ini(int n){
	int i;bl=sqrt(n);
	for(i=1;i<=n;++i)en[bel[i]=(i-1)/bl+1]=i;
	for(i=n;i;--i)be[bel[i]]=i;
}
inline void add(int l,int r){
	int x=bel[l],y=bel[r],i;
	if(x==y)for(i=l;i<=r;++i)++a[i];else{
		for(i=l;i<=en[x];++i)++a[i];
		for(i=be[y];i<=r;++i)++a[i];
		for(i=x+1;i<y;++i)++tg[i];
	}
}
inline int ask(int x){return tg[bel[x]]+a[x];}
}B;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	int tot=0;
	for(i=1;i<=n;++i)cin>>s[i],A.ins(&s[i][0],s[i].size(),id[i]),tot+=s[i].size();
	A.ini();
	BL=sqrt(tot);
	for(i=1;i<=q;++i){
		cin>>l>>r>>k;
		if(s[k].size()>BL)qu1[k].push_back(pii(r,i)),qu1[k].push_back(pii(l-1,-i));
			else qu2[l-1].push_back(pii(k,-i)),qu2[r].push_back(pii(k,i));
	}
	for(i=1;i<=n;++i)if(s[i].size()>BL)A.solve(id[i],qu1[i]);
	for(i=1;i<=n;++i){
		B.add(A.be[id[i].back()],A.en[id[i].back()]);
		for(pii u:qu2[i]){
			ll w=0;
			for(int z:id[u.first])w+=B.ask(A.be[z]);
			ans[abs(u.second)]+=(u.second>0?1:-1)*w;
		}
	}
	for(i=1;i<=q;++i)cout<<ans[i]<<'\n';
	return 0;
}