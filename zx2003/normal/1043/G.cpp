#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
typedef pair<int,int>pii;
int lo[N],n,i,q,l,r,bl,bl2,l1[N],l2[N],r1[N],ans[N],lstc[26],l3[N],lst[N],nxt[N];
char c[N];
struct SA{
int rk[N],sa[N],h[N],ff[20][N];
inline void build(char*c){
	static int ork[N],a[N],f[N],g[N];int i,j,p;
	memset(f,0,108);for(i=1;i<=n;++i)++f[c[i]-'a'+1];
	for(i=1;i<=26;++i)f[i]=bool(f[i])+f[i-1];p=f[26];
	for(i=1;i<=n;++i)rk[i]=f[c[i]-'a'+1];
	for(i=1;p<n;i<<=1){
		memcpy(ork+1,rk+1,n<<2);memset(f,0,(p+1)<<2);
		for(j=1;j<=n;++j)++f[a[j]=j+i<=n?rk[j+i]:0];
		for(j=1;j<=p;++j)f[j]+=f[j-1];for(j=1;j<=n;++j)g[f[a[j]]--]=j;
		memset(f,0,(p+1)<<2);for(j=1;j<=n;++j)++f[rk[j]];for(j=1;j<=p;++j)f[j]+=f[j-1];
		for(j=n;j;--j)sa[f[rk[g[j]]]--]=g[j];p=0;
		for(j=1;j<=n;++j)
			rk[sa[j]]=p+=ork[sa[j]]>ork[sa[j-1]] || (ork[sa[j]]==ork[sa[j-1]] && a[sa[j]]>a[sa[j-1]]);
	}
	for(j=1;j<=n;++j)sa[rk[j]]=j;
	for(i=1,j=0;i<=n;h[rk[i]]=j,++i)if(rk[i]==n)j=0;else for(j?--j:0;c[i+j]==c[sa[rk[i]+1]+j];++j);
	memcpy(ff[0]+1,h+1,n-1<<2);
	for(i=1;1<<i<n;++i)for(j=1;j+(1<<i)-1<n;++j)ff[i][j]=min(ff[i-1][j],ff[i-1][j+(1<<i-1)]);
}
inline int lcp(int x,int y){
	x=rk[x];y=rk[y];if(x>y)swap(x,y);
	int l=lo[y-x];return min(ff[l][x],ff[l][y-(1<<l)]);
}
inline bool ck(int l,int r){
	int i,bd,mn;
	for(i=1;i<=r-l && i<=bl;++i)if(lcp(l,r-i+1)>=i)return 1;
	for(i=rk[l],bd=min(n,i+bl2),mn=N;i<bd;)if(mn=min(mn,h[i++]),l<sa[i] && sa[i]<=r && sa[i]+mn-1>=r)return 1;
	for(i=rk[l],bd=max(1,i-bl2),mn=N;i>bd;)if(mn=min(mn,h[--i]),l<sa[i] && sa[i]<=r && sa[i]+mn-1>=r)return 1;
	return 0;
}
}S0,S1;
unordered_set<ll>S;
vector<pii>ve[N];
inline void ins(int l,int r){
	int x=S1.lcp(n-r+1,n-l+1),y=S0.lcp(l,r),d=r-l;
	l-=x-1;r+=y-1;if(r-l+1<d*2 || !S.insert(1ll*l*N+r).second)return;
	for(int i=l;i+d*2-1<=r;++i)ve[i].push_back(pii(r,d)),l1[i]=min(l1[i],i+d*2-1);
	for(int i=r;i-d*2+1>=l;--i)r1[i]=max(r1[i],i-d*2+1);
}
inline void work(int tp){
	static int st[N];int w=0,i;
	for(i=n;i;--i){
		for(;w && (S0.rk[i]<S0.rk[st[w]])==tp;--w);
		if(w)ins(i,st[w]);st[++w]=i;
	}
}
inline int solve(int l,int r){
	auto it=lower_bound(ve[l].begin(),ve[l].end(),pii(r,0));
	if(it!=ve[l].end() && (r-l+1)%it->second==0 && r-l+1>=it->second*2)return 1;
	if(l1[l]<r || r1[r]>l || S0.ck(l,r))return 2;
	return nxt[l]<=r || lst[r]>=l || l2[l]<=r?3:(l3[l]<=r?4:-1);
}
int main(){
	for(i=2;i<N;++i)lo[i]=lo[i>>1]+1;
	scanf("%d%s",&n,c+1);bl=sqrt(n);bl2=(n+bl-1)/bl;
	S0.build(c);reverse(c+1,c+n+1);S1.build(c);reverse(c+1,c+n+1);
	for(i=1;i<=n;++i)l1[i]=N;work(0);work(1);
	for(i=1;i<=n;++i)lst[i]=lstc[c[i]-'a'],lstc[c[i]-'a']=i,sort(ve[i].begin(),ve[i].end());memset(lstc,1,104);
	l2[n+1]=l3[n+1]=N;for(i=n;i;--i)nxt[i]=lstc[c[i]-'a'],lstc[c[i]-'a']=i,
		l2[i]=min(l1[i],l2[i+1]),l3[i]=min(nxt[i],l3[i+1]);
	for(scanf("%d",&q);q--;)scanf("%d%d",&l,&r),printf("%d\n",solve(l,r));
	return 0;
}