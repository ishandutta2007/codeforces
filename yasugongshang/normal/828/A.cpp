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
int ans,n,a,b1,b2;
int main(){
	n=read(); a=read(); b1=read();
	for(int i=1;i<=n;i++){
		int s1=read();
		if(s1==1){
			if(a)a--; else if(b1){b1--; b2++;} else if(b2)b2--; else ans++;
		}else if(b1)b1--; else ans+=2;
	}
	write(ans);
}