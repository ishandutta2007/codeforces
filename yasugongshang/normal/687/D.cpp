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
const int N=1005;
int n,m,q,father[N],dist[N];
pair<pair<int,int>,pair<int,int> > a[1000005];
inline int getfather(int x){
	if(x==father[x])return x;
	int f=getfather(father[x]);
	dist[x]^=dist[father[x]];
	return father[x]=f;
}
inline int query(int l,int r){
	for(int i=1;i<=n;i++){
		father[i]=i; dist[i]=0;
	}
	for(int i=m;i;i--){
		if(a[i].first.second<l||a[i].first.second>r)continue;
		int t1=getfather(a[i].second.first),t2=getfather(a[i].second.second);
		//cout<<a[i].second.first<<" "<<a[i].second.second<<" "<<dist[a[i].second.first]<<" "<<dist[a[i].second.second]<<" "<<t1<<" "<<t2<<endl;
		if(t1==t2){
			if((dist[a[i].second.first]^dist[a[i].second.second])==0)return a[i].first.first;
			else continue;
		}
		father[t1]=t2;
		dist[t1]=dist[a[i].second.first]^dist[a[i].second.second]^1;
	}
	return -1;
}
int main(){
	n=read(); m=read(); q=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		a[i]=mp(mp(w,i),mp(u,v));
	}
	sort(&a[1],&a[m+1]);
	while(q--){
		int l=read(),r=read();
		writeln(query(l,r));
	}
}