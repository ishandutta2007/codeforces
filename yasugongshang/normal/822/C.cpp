#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
inline void write(long long a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
inline int read()// 
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
const int N=200005,oo=2000000005;
struct data{
	int l,r,cost;
}a[N],b[N];
int n,m,ans,tong[N],j;
inline bool cmp1(data a,data b){
	return a.r<b.r;
}
inline bool cmp2(data a,data b){
	return a.l<b.l;
}
int main(){
	n=read(); m=read();
	for(int i=1;i<=n;i++){a[i].l=read(); a[i].r=read(); a[i].cost=read();b[i]=a[i];}
	sort(&a[1],&a[n+1],cmp1); ans=oo;
	sort(&b[1],&b[n+1],cmp2); j=1;
	for(int i=1;i<=n;i++){
		for(;a[j].r<b[i].l;j++)if(!tong[a[j].r-a[j].l+1])tong[a[j].r-a[j].l+1]=a[j].cost; else tong[a[j].r-a[j].l+1]=min(tong[a[j].r-a[j].l+1],a[j].cost);
		if(m>=b[i].r-b[i].l+1&&tong[m-(b[i].r-b[i].l+1)])ans=min(ans,b[i].cost+tong[m-(b[i].r-b[i].l+1)]);
	}
	if(ans<oo)
	writeln(ans); else puts("-1");
}