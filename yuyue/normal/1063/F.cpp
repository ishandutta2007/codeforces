#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1e6+10;
char s[M];
int n;
struct node{
	int c[26];
	int fa,len;
}t[M];
int lst=1,tot=1,f[M][21],ed[M];
void extend(int o){
	int np=++tot,p=lst;  t[np]=t[p]; t[np].len=t[p].len+1; lst=np;
	while (p && !t[p].c[o]) t[p].c[o]=np,p=t[p].fa;
	if (!p) t[np].fa=1;
	else{
		int q=t[p].c[o];
		if (t[q].len==t[p].len+1) t[np].fa=q;
		else{
			int nq=++tot; t[nq]=t[q]; t[nq].len=t[p].len+1;
			t[np].fa=t[q].fa=nq;
			while (p && t[p].c[o]==q) t[p].c[o]=nq,p=t[p].fa;
		}
	}
}
int head[M],nxt[M];
void add(int x,int y){
	 nxt[y]=head[x]; head[x]=y;
}
int dfn[M],sz[M],yjy;
void dfs(int x){
//	cerr<<x<<"\n";
	dfn[x]=++yjy; sz[x]=1;
	for (int y=head[x];y;y=nxt[y]){
		dfs(y);
		sz[x]+=sz[y];
	}
}
void init(){
	F(i,1,tot) f[i][0]=t[i].fa,add(t[i].fa,i);
//	cerr<<t[5].fa<<" "<<f[5][0]<<"   gan\n";
	F(i,1,20) F(j,1,tot) f[j][i]=f[f[j][i-1]][i-1];
	dfs(1);
//	cout<<dfn[1]<<"   \n";
}
int dp[M];
struct SGT{
	#define mid (l+r>>1)
	#define lc (x<<1)
	#define rc (x<<1|1)
	int mx[M<<3];
	void upd(int x,int l,int r,int p,int val){
		if (l==r){
//			cerr<<l<<" "<<val<<"   UPD !!!!!!\n";
			mx[x]=val;
			return ;
		}
		if (p<=mid) upd(lc,l,mid,p,val);
		else upd(rc,mid+1,r,p,val);
		mx[x]=max(mx[lc],mx[rc]);
	}
	int qry(int x,int l,int r,int ll,int rr){
		if (l>rr || r<ll) return 0;
		if (ll<=l && r<=rr) return mx[x];
		return max(qry(lc,l,mid,ll,rr),qry(rc,mid+1,r,ll,rr));
	}
}sgt;
int jump(int x,int len){//last len(node)>=len
	DF(i,20,0){
		if (t[f[x][i]].len>=len) x=f[x][i];
	}
//	cerr<<x<<" "<<f[x][0]<<" "<<t[x].fa<<"   omg\n";
//	x=f[x][0];
	return x;
}
bool valid(int x){
	if (dp[x]==1) return 1;
	int ps1=jump(ed[x],dp[x]-1),ps2=jump(ed[x+1],dp[x]-1);
//	cerr<<x<<" "<<dp[x]<<"   check\n";
//	cerr<<ps1<<" "<<ps2<<" "<<dfn[ps1]<<"    o\n";
	if (sgt.qry(1,1,tot,dfn[ps1],dfn[ps1]+sz[ps1]-1)>=dp[x]-1) return 1;
	if (sgt.qry(1,1,tot,dfn[ps2],dfn[ps2]+sz[ps2]-1)>=dp[x]-1) return 1;
	return 0;
}
int main(){
//	freopen("fade3.in","r",stdin);
	n=read();//	cerr<<" ?\n";
	scanf("%s",s+1);
//	cerr<<strlen(s+1)<<"\n";
	DF(i,n,1) extend(s[i]-'a'),ed[i]=lst;
	init();

	dp[n]=1;
	int ans=1;
	DF(i,n-1,1){
		dp[i]=dp[i+1]+1;
		while (!valid(i)){
			dp[i]--;
//			cerr<<"ed "<<i+dp[i]<<" : ="<<ed[i+dp[i]]<<"    hh\n";
			sgt.upd(1,1,tot,dfn[ed[i+dp[i]]],dp[i+dp[i]]);
		}
//		cout<<dp[i]<<" "<<i<<"  dp\n";
		ans=max(ans,dp[i]);
	}
	cout<<ans<<"\n";
	
	return 0;
}
/*
10
abcdabcaba
*/