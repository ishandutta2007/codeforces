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
const int N=1005;
int f[N][4],a[N],b[N],n,m,oo=100005;
int main(){
	n=read(); 
	for(int i=1;i<=n;i++){
		int zs=read();
		if(zs&1)a[i]=1; 
		if(zs&2)b[i]=1;
	}
	//f[0][0]=0; 
	for(int i=1;i<=n;i++){
		f[i][0]=min(f[i-1][0],min(f[i-1][1],f[i-1][2]))+1;
		if(a[i])f[i][1]=min(f[i-1][0],f[i-1][2]); else f[i][1]=oo;
		if(b[i])f[i][2]=min(f[i-1][0],f[i-1][1]); else f[i][2]=oo;
	}
	writeln(min(f[n][2],min(f[n][0],f[n][1])));
}