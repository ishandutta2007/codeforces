#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const long long N=200005;
struct data{
	long long val,pos;
}a[N];
inline bool cmp(data a,data b){
	return a.val<b.val;
}
long long n,T,b[N],vis[N],ans,an;
inline long long	read()// 
{
	long long x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(long long a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
int main(){
	n=read(); T=read()-1;
	for(long long i=1;i<=n;i++){
		b[i]=a[i].val=max((long long)0,read()-i); a[i].pos=i;
	}
	sort(&a[1],&a[n+1],cmp); long long r=n;
	for(long long i=1;i<=n;i++){
		while(a[i].val>T-r&&r>=0){
			if(vis[r--])ans--;
		}
		if(a[i].pos<=r){vis[a[i].pos]=1; ans++;}
		an=max(an,ans);
	}
	write(an);
}