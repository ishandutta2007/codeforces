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
#define int long long
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define getchar gc
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
const int N=1000005,p=10000005;
int mi=p,ans,n,m,k,tong[p];
pair<int,int> s[N];
signed main(){
	n=read(); m=read(); k=read();
	for(int i=1;i<=n;i++)tong[read()+1]++;
	for(int i=1;i<=m;i++)s[i]=mp(read()+1,i);
	sort(&s[1],&s[m+1]);
	for(int i=1;i<p;i++)if((tong[i]+=tong[i-1])>(long long)k*i){
		puts("-1"); return 0;
	}
	ans=1; int j=p-1;
	for(int i=m;i;i--){
		while(j>s[i].first){
			j--; mi=min(mi,j*k-tong[j]);
		}
		if(!mi){
			ans=i+1; break;
		}else mi--;
	}
	cout<<m-ans+1<<endl;
	for(int i=ans;i<=m;i++){
		write(s[i].second); putchar(' ');
	}
}