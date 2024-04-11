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
int n,k,a[105][105];
int main(){
	n=read(); k=read(); if(k>n*n){
		puts("-1"); return 0;
	}
	for(int i=1;i<=n;i++){if(!k)break;
		if(k)a[i][i]=1; k--; if(!k)break;
		for(int j=i+1;j<=n;j++){
			if(k>1){
				a[i][j]=a[j][i]=1; k-=2; 
			}
		}
	}
	if(k){
		puts("-1");
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			write(a[i][j]); putchar(' ');
		}
		puts("");
	}
}