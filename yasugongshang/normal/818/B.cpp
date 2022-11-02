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
inline void writeln(long long a){
	write(a); puts("");
}
inline long long read()// 
{
	long long x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
const int N=105;
int n,m,a[N],b[N],tong[N],vis[N];
int main(){
	n=read(); m=read();
	for(int i=1;i<=m;i++)a[i]=read();
	for(int i=1;i<m;i++){
		int zs=(a[i+1]-a[i]+n)%n;
		if(!vis[a[i]]){b[a[i]]=zs;vis[a[i]]=true;} else if(zs!=b[a[i]]){
			puts("-1"); return 0;
		}
	}
	for(int i=1;i<=n;i++)if(vis[i]){if(tong[b[i]]){
		puts("-1"); return 0;
	}else tong[b[i]]=true;}
	for(int i=1;i<=n;i++)if(!vis[i]){
		for(int j=0;j<n;j++)if(!tong[j]){
			b[i]=j; tong[j]=true; break;
		}
	}
	for(int i=1;i<=n;i++){
		if(!b[i])b[i]=n; write(b[i]); putchar(' ');
	}
}