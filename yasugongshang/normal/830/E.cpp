#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ld long double
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
const int N=100005;
int n,m,T,vis[N],fa[N],zs[N],ans[N],dp[N],quan,sum;
vector<int> v[N],dq;
void dfs(int p){
	vis[p]=1;
	for(auto i:v[p])if(!vis[i]){fa[i]=p; dfs(i);}
	dq.push_back(p); sum+=v[p].size();
}
int lca(int x,int y){
	T++;
	for(int i=x;i;i=fa[i])zs[i]=T;
	for(int i=y;i;i=fa[i])if(zs[i]==T)return i;
}
void alb(int x,int y){
	for(int i=x;;i=fa[i]){
		ans[i]=2; if(i==y)return;
	}
}
void print(){
	puts("YES");
	for(int i=1;i<=n;i++)wri(ans[i]); puts("");
}
void solve(int p,int fa){
	for(auto i:v[p])if(i!=fa){solve(i,p); dp[p]=dp[i]+1;}
	if(!dp[p])dp[p]=1;
}
void bao(int p,int fa){
	ans[p]=quan*dp[p];
	for(auto i:v[p])if(i!=fa)bao(i,p);
}
inline ll Lcm(ll a,ll b){
	return a/__gcd(a,b)*b;
}
int main(){
	int T=read();
	while(T--){
		n=read(); m=read();
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<=m;i++){
			int s=read(),t=read();
			v[s].push_back(t); v[t].push_back(s);
		}
		for(int i=1;i<=n;i++)vis[i]=ans[i]=dp[i]=fa[i]=0;
		int flag=0;
		for(int i=1;i<=n;i++)if(v[i].size()>=4){
			ans[i]=2; for(auto j:v[i])ans[j]=1; flag=1; break;
		}
		if(flag){print(); continue;}
		for(int i=1;i<=n;i++)if(!vis[i]){
			sum=0;
			dq.clear(); dfs(i);
			if(sum>=dq.size()*2){
				for(auto j:dq)ans[j]=1; flag=1;break;
			}
			int t=0;
			for(auto j:dq)if(v[j].size()==3){
				if(t){
					int jjj=lca(t,j);
					alb(t,jjj); alb(j,jjj);
					flag=1; break;
				}else t=j;
			}
			if(flag){
				for(auto j:dq)if(!ans[j])ans[j]=1; break;
			}
			if(!t)continue;
			solve(t,0);
			ld sum=0;
			for(auto i:v[t])sum+=(ld)dp[i]/2/(dp[i]+1); 
			if(sum+1e-12>1){
				ll lcm=1; for(auto i:v[t])lcm=Lcm(lcm,dp[i]+1);
				lcm=min(lcm,(ll)1000000);
				ans[t]=lcm;
				for(auto i:v[t]){quan=lcm/(dp[i]+1); bao(i,t);}
				flag=1; break;
			}
		}
		if(flag){
			print(); continue;
		}
		puts("NO");
	}
}
/*
x
(x-1)/2/x
*/