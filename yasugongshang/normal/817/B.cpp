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
inline void write(long long a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(long long a){
	write(a); puts("");
}
inline int	read()// 
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
int n,a[100005];
map<int,int>tong;
int main(){
	n=read();
	for(int i=1;i<=n;i++)tong[a[i]=read()]++;
	sort(&a[1],&a[n+1]);
	if(a[1]==a[2]&&a[2]==a[3]){
		int zs=tong[a[1]];
		writeln((long long) zs*(zs-1)*(zs-2)/6);
	}else if(a[2]!=a[3]){
		writeln(tong[a[3]]);
	}else if(a[1]!=a[2]&&a[2]==a[3]){
		writeln((long long)tong[a[2]]*(tong[a[2]]-1)/2);
	}
}