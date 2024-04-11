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
int n,a[10005];
int main(){
	n=read(); 
	for(int i=1;i<=n;i++)a[i]=read(); int i=2;
	for(;i<=n;i++)if(a[i]<=a[i-1]){
		break;
	}
    for(;i<=n;i++)if(a[i]>a[i-1]){
    	puts("NO"); return 0;
	}else if(a[i]<a[i-1]){
		break;
	}
	for(;i<=n;i++)if(a[i]<=a[i+1]){
		puts("NO"); return 0;
	}
	puts("YES");
}