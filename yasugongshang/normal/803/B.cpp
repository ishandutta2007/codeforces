#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
inline int	read()// 
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
const int N=200005;
int n,a[N],f[N],g[N];
int main(){
	n=read(); 
	for(int i=1;i<=n;i++)a[i]=read();f[0]=1000000;
	for(int i=1;i<=n;i++)if(!a[i]){
		f[i]=0;
	}else f[i]=f[i-1]+1; g[n+1]=1000000;
	for(int i=n;i;i--)if(!a[i]){
		g[i]=0;
	}else g[i]=g[i+1]+1;
	for(int i=1;i<=n;i++){
		write(min(f[i],g[i])); putchar(' ');
	}puts("");
}