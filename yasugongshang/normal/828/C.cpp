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
const int N=200005;
string  ch[N];
int first,r,tong[6000005],zs,maxn,len[6000005];
int main(){
	int n=read(); ch[0]="a"; len[0]=1;
	for(int i=1;i<=n;i++){
		cin>>ch[i]; len[i]=ch[i].length();
		int m=read();
		while(m--){if(!tong[zs=read()]||len[tong[zs]]<len[i])tong[zs]=i;maxn=max(maxn,zs+len[i]);}
	}
	for(int i=1;i<maxn;i++){
		if(i+len[tong[i]]-1>r){
			zs=tong[i]; first=i; r=i+len[tong[i]]-1;
		}
		putchar(ch[zs][i-first]);
	}
}