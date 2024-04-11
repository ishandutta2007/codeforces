#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
inline int read(){
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
const int N=100005;
int n,a[N],b[N],first;
inline void dfs(int p){
	if(b[p]==0){
		for(int j=1;j<=n;j++)if(j!=first&&!a[j]){
			a[j]=p; b[p]=j; dfs(j); break;
		}
		if(b[p]==0)return ;
	}else dfs(b[p]);
}
int main(){
    n=read();
    for(int i=1;i<=n;i++){
    	a[i]=read(); b[i]=read(); if(a[i]==0)first=i;
	}
    dfs(first);
    for(int i=1;i<=n;i++){
    	write(a[i]); putchar(' '); writeln(b[i]);
	}
}