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
int n,l,r,sum;
int main(){
	n=read();
	for(int i=1;i<=n;i++)sum+=read();
	n=read();
	for(int i=1;i<=n;i++){
		l=read(); r=read();
		if(l<=sum&&r>=sum){
			writeln(sum); return 0;
		}if(sum<l){
			writeln(l);return 0;
		}
	}
	puts("-1");
	return 0;
}