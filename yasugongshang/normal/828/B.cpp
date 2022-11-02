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
int n,m,oo=10000000,xmin=oo,ymin=oo,xmax,ymax,sum[105][105];
char ch[105][105];
int main(){
	n=read(); m=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){scanf("\n%c",&ch[i][j]); sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]; if(ch[i][j]=='B'){
			xmax=max(xmax,i); ymax=max(ymax,j); xmin=min(xmin,i); ymin=min(ymin,j); sum[i][j]++;
		}}
	}
	if(xmin==oo){
		puts("1"); return 0;
	}int bc=max(ymax-ymin+1,xmax-xmin+1);
	if(bc>n||bc>m){
		puts("-1"); return 0;
	}else{
		writeln(bc*bc-sum[n][m]);
	}
}