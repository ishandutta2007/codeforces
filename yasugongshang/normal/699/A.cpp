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
const int N=500005;
char ch[N];
int n,sum,a[N],ans,oo=1000000000,vis[N];
int main(){
	n=read(); ans=oo;
	scanf("%s",&ch); int len=strlen(ch);
	for(int i=0;i<len;i++){
		if(ch[i]=='R')vis[i+1]=true;
	}
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<n;i++)if(vis[i]&&!vis[i+1]){
		ans=min(ans,(a[i+1]-a[i])/2);
	}
	if(ans==oo)puts("-1");else
	writeln(ans);
}