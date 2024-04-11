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
const int N=300005;
int n,m,dq,tot,tong[N],vis[N],a[N];
vector<int> v[N],e[N];
map<vector<int>,int> M;
void GG(){
	puts("NO"); exit(0);
}
void dfs(int p,int fa){
	vis[p]=1;
	for(auto i:e[p])if(i!=fa){
		if(vis[i])GG();
		a[i]=++dq; dfs(i,p);
	}
}
int main(){
	n=read(); m=read();
	for(int i=1;i<=m;i++){
		int s=read(),t=read();
		v[s].push_back(t); v[t].push_back(s);
	}
	for(int i=1;i<=n;i++){
		v[i].push_back(i);
		sort(v[i].begin(),v[i].end());
		if(!M.count(v[i])){
			tong[i]=M[v[i]]=++tot;
		}else{
			tong[i]=M[v[i]];
		}
	}
	for(int i=1;i<=n;i++){
		for(auto j:v[i])if(tong[i]!=tong[j])e[tong[i]].push_back(tong[j]);
	}
	for(int i=1;i<=tot;i++){sort(e[i].begin(),e[i].end()); e[i].resize(unique(e[i].begin(),e[i].end())-e[i].begin()); 
	 if(e[i].size()>2)GG();}
	//for(int i=1;i<=tot;i++)for(auto j:e[i])cout<<i<<" wzp "<<j<<endl;
	for(int i=1;i<=tot;i++)if(!vis[i]&&e[i].size()<=1){dq++; a[i]=++dq; dfs(i,0);}
	puts("YES");
	for(int i=1;i<=n;i++)wri(a[tong[i]]);
}