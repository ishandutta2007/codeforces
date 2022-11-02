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
const int N=200005;
int n,rt,jj,dep[N],fat[N],dp[N];
vector<int> v[N];
void dfs(int p,int fa){
	dep[p]=dep[fa]+1; if(rt==0||dep[p]>dep[rt])rt=p; fat[p]=fa;
	vector<int> V; int flag=1;
	for(auto i:v[p])if(i!=fa){
		dfs(i,p); V.push_back(dp[i]); if(dp[i]==-1)flag=0;
	}
	if(!flag){
		dp[p]=-1; return;
	}
	if(!V.size()){
		dp[p]=1; return;
	}
	if(p==jj){
		set<int> s;
		for(auto i:V)s.insert(i);
		if(s.size()>2){
			dp[p]=-1;
		}else{
			dp[p]=0; 
			for(auto i:s)dp[p]+=i;
		} 
		return;
	}
	for(unsigned i=1;i<V.size();i++)if(V[i]!=V[0]){
		dp[p]=-1; return;
	}
	dp[p]=V[0]+1;
	//if(jj)cout<<p<<" wzp "<<dp[p]<<endl;
}
int main(){
	n=read();
	for(int i=1;i<n;i++){
		int s=read(),t=read();
		v[s].push_back(t); v[t].push_back(s);
	}
	dfs(1,0); int t=rt; rt=0;
	dfs(t,0);
	int T=dep[rt]-dep[t];
	jj=rt;
	for(int o=1;o<=T/2;o++)jj=fat[jj]; 
	dfs(jj,0); 
	while(dp[jj]%2==0)dp[jj]/=2;
	cout<<dp[jj]<<endl;
}