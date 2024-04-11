#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
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
int m,n,ans,s1,s2,amin1=1000000000,amax1,bmin2=1000000000,bmax2,amin2=1000000000,amax2,bmin1=1000000000,bmax1;
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		amin1=min(amin1,s1=read()); amax2=max(amax2,s2=read());
		amax1=max(amax1,s1); amin2=min(amin2,s2);
	}
	m=read();
	for(int i=1;i<=m;i++){
		bmin1=min(bmin1,s1=read()); bmax2=max(bmax2,s2=read());
		bmax1=max(bmax1,s1); bmin2=min(bmin2,s2);
	}
	ans=max(ans,bmax1-amin2);
	ans=max(ans,amax1-bmin2);
	writeln(ans);
}