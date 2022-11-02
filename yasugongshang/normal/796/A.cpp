#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
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
const int N=10005;
int n,m,k,a[N],jl=1000000000;
int main(){
	n=read(); m=read(); k=read();
	for(int i=1;i<=n;i++)a[i]=read(); 
	for(int i=1;i<=n;i++){
		if(a[i]&&a[i]<=k){
			jl=min(jl,abs(i-m));
		}
	}
	writeln(jl*10);
}