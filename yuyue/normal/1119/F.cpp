#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
#pragma GCC optimize(2)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
#define pii pair<int,int>
#define mp make_pair
const int M=5e5+10;
const LL inf=1e18;
int n;
int to[M],nxt[M],head[M],w[M],cnt;
int de[M];
vector<pii> v[M];
void add(int x,int y,int z){
	to[++cnt]=y; nxt[cnt]=head[x]; head[x]=cnt; w[cnt]=z;
}
struct pq_bg{// maintain first k th
	priority_queue<LL > q,dq;
	int sz=0;
	LL sum=0;
	void del(LL x){
		sum-=x;
		dq.push(x);
		sz--;
	}
	void push(LL x){
		sum+=x;
		q.push(x);
		sz++;
	}
	void pop(){
		while (dq.size() && q.top()==dq.top()) q.pop(),dq.pop();
		sum-=q.top();
		q.pop();
		sz--;
	}
	LL top(){
		while (dq.size() && q.top()==dq.top()) q.pop(),dq.pop();
		return q.top();
	}
}H[M];
bool del[M];
void qu(int x){
	del[x]=1;
	for (int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if (!del[y]){
//			cerr<<y<<" "<<w[i]<<"  add\n";
			H[y].push(w[i]);
		}
	}
}
bool vis[M];
vector<int> dv[M];
LL dp[M][2];
int lim;
void dfs(int x,int fa){
	vis[x]=1; dp[x][0]=dp[x][1]=0;
	int D=de[x]-lim;
	vector<LL> nw;
	while (H[x].sz>D) H[x].pop();
	F(i,0,SZ(v[x])){
		int y=v[x][i].first,wei=v[x][i].second;
		if (y==fa) continue;
		if (de[y]<=lim) break;
		dfs(y,x);
		if (dp[y][1]+wei-dp[y][0]>=0) nw.pb(dp[y][1]+wei-dp[y][0]),
		H[x].push(dp[y][1]+wei-dp[y][0]),dp[x][0]+=dp[y][0];
		else D--,dp[x][0]+=dp[y][1]+wei;
	}
	dp[x][1]=dp[x][0];
	vector<LL> tmp;
	while (H[x].sz && H[x].sz>D){
		LL o=H[x].top();
		tmp.pb(o);
		H[x].pop();
	}
	dp[x][0]+=H[x].sum;
	while (H[x].sz && H[x].sz>D-1){
		LL o=H[x].top();
		tmp.pb(o);
		H[x].pop();
	}
	dp[x][1]+=H[x].sum;
	for (LL z:tmp) H[x].push(z);
	for (LL z:nw) H[x].del(z);
//	cout<<dp[x][0]<<" "<<dp[x][1]<<"   dp dp\n";
}
int p[M],rk[M];

bool cmp(int x,int y){
	return de[x]<de[y];
}
bool cmpb(pii x,pii y){
	return de[x.first]>de[y.first];
}
int main(){
	n=read();
	LL sum=0;
	F(i,1,n-1){
		int x=read(),y=read(),z=read();
		add(x,y,z);
		add(y,x,z);
		v[x].pb(mp(y,z));
		v[y].pb(mp(x,z));
		de[x]++; de[y]++;
		sum+=z;
	}
	F(x,1,n){
		sort(v[x].begin(),v[x].end(),cmpb);
	}
	F(i,1,n){
		p[i]=i;
		dv[de[i]].pb(i);
	}
	sort(p+1,p+n+1,cmp);
	F(i,1,n) rk[i]=1e9;
	F(i,1,n) rk[de[p[i]]]=min(rk[de[p[i]]],i);
	DF(i,n-1,1) rk[i]=min(rk[i+1],rk[i]); 

//	F(i,1,n) cout<<rk[i]<<"   hh\n";
	cout<<sum<<" ";
	F(i,1,n-1){
		for (int x:dv[i]){
			qu(x);
		}
		lim=i;
		LL ans=0;
		F(j,rk[i+1],n){
			int x=p[j];
			if (!vis[x]){
//				cerr<<x<<" cao\n";
				dfs(x,0);
				ans+=dp[x][0];
			}
		}
		F(j,rk[i+1],n){
			int x=p[j];
			vis[x]=0;
		}
		cout<<ans<<" ";
	}
	return 0; 
}