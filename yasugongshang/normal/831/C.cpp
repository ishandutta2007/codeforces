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
inline void write(int a){
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
const int N=2005;
bool tong[20000000],vis[20000000];
int n,k,sum[N],a[N],ans;
inline bool check(int x){int zs=x,flag=1;
    if(vis[x+8000000])return 0; else vis[x+8000000]=1;
	for(int i=1;i<=n;i++){
		tong[sum[i]+x+8000000]=1;
	}
	for(int i=1;i<=k;i++)if(!tong[a[i]+8000000])flag=0;
	for(int i=1;i<=n;i++){
		tong[sum[i]+x+8000000]=0;
	}
	return flag;
}
int main(){
	n=read(); k=read();
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+read();
	for(int i=1;i<=k;i++)a[i]=read();
	for(int i=1;i<=n;i++)if(check(a[1]-sum[i]))ans++; 
	writeln(ans);
}