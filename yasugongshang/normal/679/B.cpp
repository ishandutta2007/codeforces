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
typedef long long ll;
#define sqr(x) ((x)*(x))
#define int long long
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
pair<int,int> dp[10000000],tt[100005];
inline int pow3(ll x){
	int t=pow(x,(double)1/3);
	if((ll)(t+1)*(t+1)*(t+1)<=x)t++;
	return t;
}
pair<int,int> dfs(ll x){
	if(x<10000000&&dp[x]!=mp((ll)0,(ll)0))return dp[x];
	if(!x)return mp(0,0); else if(x==1)return mp(1,1);
	int t=pow3(x); ll zs=(ll)t*t*t;
	if(zs==x){
		if(tt[t]!=mp((ll)0,(ll)0))return tt[t];
		return tt[t]=dfs(x-1);
	}
	if(x%zs==0){
		pair<int,int> z=dfs(zs); z.first+=x/zs-1; z.second+=(x/zs-1)*zs;
		return dp[x]=z;
	}
	pair<int,int> z=dfs(x%zs); z.first+=x/zs; z.second+=x/zs*zs;
	pair<int,int> zzz=dfs(zs); zzz.first+=x/zs-1; zzz.second+=(x/zs-1)*zs;
	if(x<10000000)return dp[x]=max(zzz,z);
	return max(zzz,z);
}
ll n;
signed main(){
	n=read();
	pair<int,int> zs=dfs(n);
	cout<<zs.first<<" "<<zs.second<<endl;
}