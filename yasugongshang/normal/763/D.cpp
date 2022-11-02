#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long LL;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
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
#define ull unsigned long long
const int N=100005;
int n,pos,ans,tot;
ull hash[N],val[N<<1];
map<ull,int> M,vis;
map<ull,ull> hh;
vector<int> v[N];
inline ull find(ull a){
	if(hh.find(a)==hh.end())return hh[a]=val[++tot];
	else return hh[a];
}
inline void dfs(int p,int fa){
	for(int i=0;i<v[p].size();i++)if(v[p][i]!=fa){
		dfs(v[p][i],p);
	}
	for(int i=0;i<v[p].size();i++)if(v[p][i]!=fa)hash[p]+=find(hash[v[p][i]]);
	M[hash[p]]++; //cout<<p<<" "<<hash[p]<<endl;
}
inline void change(ull a,ull b){
	if(--M[a]==0)M.erase(a);
	M[b]++;
}
inline void ddd(int p,int fa){
	if(fa){
		change(hash[fa],hash[fa]-find(hash[p]));
		hash[fa]-=find(hash[p]);
		change(hash[p],hash[p]+find(hash[fa]));
		hash[p]+=find(hash[fa]);
	}
	if(M.size()>ans){
		pos=p; ans=M.size();
	}
	for(int i=0;i<v[p].size();i++)if(v[p][i]!=fa){
		ddd(v[p][i],p); 
	}
	if(fa){
		hash[p]-=find(hash[fa]);
		change(hash[p]+find(hash[fa]),hash[p]);
		hash[fa]+=find(hash[p]);
		change(hash[fa]-find(hash[p]),hash[fa]);
	}
}
int main(){
	n=read();
	for(int i=1;i<=2*n;i++){val[i]=val[i-1]*(rand()%30000+1)+rand()%30000;}
	for(int i=1;i<n;i++){
		int s=read(),t=read();
		v[s].push_back(t); v[t].push_back(s);
	}
	dfs(1,0);
	ddd(1,0);
	writeln(pos);
}