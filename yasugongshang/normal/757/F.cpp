#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#define int long long
using namespace std;
typedef long long  LL;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define F first
#define S second
inline int read(){
    int x = 0; char ch = getchar(); bool positive = 1;
    for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
    for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
    }
    write(a); puts("");
}
const int N=200005,M=600005,K=20,oo=4e18;
int mx,nedge,di[M],nextt[M],ed[M],son[N],pos,deep[N],dp[N][K],n,m,dist[N],ans[N],s,vis[N];
priority_queue<pair<int,int> > q;
vector<int> v[N];
#include<string>
inline void aedge(int a,int b,int c){
    nextt[++nedge]=son[a]; son[a]=nedge; ed[nedge]=b; di[nedge]=c;
}
inline int qiu(int a,int b){
	for(int i=K-1;deep[a]!=deep[b];i--){
		if(deep[a]-(1<<i)>=deep[b]){a=dp[a][i];}
		else if(deep[b]-(1<<i)>=deep[a]){b=dp[b][i];}
	}
	if(a==b)return a;
	for(int i=K-1;i>=0;i--){
		if(dp[a][i]!=dp[b][i]){
			a=dp[a][i]; b=dp[b][i];
		}
	}
	return dp[a][0];
}
void duidi(int s){
	dist[s]=0;
    q.push(mp(0,s));
    while(!q.empty()){
        pair<int,int> zs=q.top(); q.pop();
        zs.first=-zs.first;
        if(vis[zs.second])continue; vis[zs.second]=1; int dq=0;
        for(int i=son[zs.second];i;i=nextt[i])if(vis[ed[i]]&&dist[ed[i]]+di[i]==dist[zs.second]){
        	dq=dq?qiu(dq,ed[i]):ed[i];
		}
		if(dq==zs.second)dq=0;  deep[zs.second]=deep[dq]+1; 
		dp[zs.second][0]=dq; for(int i=1;i<K;i++)dp[zs.second][i]=dp[dp[zs.second][i-1]][i-1]; v[dq].push_back(zs.second);
        for(int i=son[zs.second];i;i=nextt[i])if(dist[zs.second]+di[i]<dist[ed[i]]){
            dist[ed[i]]=dist[zs.second]+di[i]; 
            q.push(mp(-dist[ed[i]],ed[i]));
        }
    }
}
void dfs(int p){
	ans[p]=1; 
	for(int i=0;i<v[p].size();i++){dfs(v[p][i]); ans[p]+=ans[v[p][i]];}
	if(p!=s&&p)mx=max(mx,ans[p]);
}
signed main(){
    n=read(); m=read(); s=read();
    for(int i=1;i<=n;i++)dist[i]=oo;
    while(m--){
        int s1=read(),s2=read(),s3=read();
        aedge(s1,s2,s3); aedge(s2,s1,s3);
    }
    duidi(s);
	dfs(0);
	writeln(mx);
}