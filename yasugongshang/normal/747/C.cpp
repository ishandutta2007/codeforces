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
inline int	read()// 
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
const int N=1000005;
int n,q,t,k,d,tt[N],que[N],r,sum;
int main(){
	n=read(); q=read();
	while(q--){
		t=read(); k=read(); d=read(); r=sum=0;
		for(int i=1;i<=n;i++)if(tt[i]<t){
			que[++r]=i; if(r==k)break;
		}
		if(r==k)while(r){
			sum+=que[r];
			tt[que[r--]]=t+d-1; 
		}else {puts("-1"); continue;}
		writeln(sum);
	}
}