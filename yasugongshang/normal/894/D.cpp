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
inline long long read(){
	long long x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(long long a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(long long a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const long long N=2000005;
long long val[N],l[N],n,q;
vector<long long> v[N];
vector<long long> vv[N];
long long solve(long long s,long long di){
	if(s==0)return 0; long long ans=0;
	long long t1=lower_bound(&v[s][0],&v[s][v[s].size()],di)-&v[s][0]-1;
	if(t1>=0)ans+=((long long)t1+1)*di-vv[s][t1];
	if(s>1){
		t1=lower_bound(&v[s][0],&v[s][v[s].size()],di-2*val[s])-&v[s][0]-1;
		if(t1>=0)ans-=(long long)(t1+1)*(di-2*val[s])-vv[s][t1];
	}
	return ans+solve(s/2,di-val[s]);
}
void dfs(long long p){
	if(p>n)return;
	dfs(p*2); dfs(p*2+1); v[p].push_back(0);
	for(long long i=0;i<v[p<<1].size();i++)v[p].push_back(v[p<<1][i]+val[p<<1]);
	for(long long i=0;i<v[p<<1|1].size();i++)v[p].push_back(v[p<<1|1][i]+val[p<<1|1]);
	sort(&v[p][0],&v[p][v[p].size()]);
	long long sum=0;
	for(long long i=0;i<v[p].size();i++)vv[p].push_back(sum+=v[p][i]);
}
int main(){
	n=read(); q=read();
	for(long long i=2;i<=n;i++)val[i]=read();
	dfs(1);
	while(q--){
		long long s=read(),l=read();
		writeln(solve(s,l));
	}
}