#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<ctime>
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
const int N=300005;
int n,mx[N],peo[N],father[N],ans[N],q;
vector<int> v[N];
map<int,int> s;
map<int,int>::iterator it;
void dfs(int p){
	peo[p]=1;
	for(int i=0;i<v[p].size();i++)if(v[p][i]!=father[p]){dfs(v[p][i]); peo[p]+=peo[v[p][i]]; mx[p]=max(mx[p],peo[v[p][i]]);}
}
void solve(int p){
	s[peo[p]]=p;
	for(it=s.lower_bound(mx[p]*2);it!=s.end()&&it->first<=peo[p]*2;it++)ans[it->second]=p;
	for(int i=0;i<v[p].size();i++)if(v[p][i]!=father[p])solve(v[p][i]);
	s.erase(peo[p]);
}
int main(){
	n=read(); q=read();
	for(int i=2;i<=n;i++){
		v[father[i]=read()].push_back(i);
	}
	dfs(1);
	solve(1);
	for(int i=1;i<=q;i++)writeln(ans[read()]);
}