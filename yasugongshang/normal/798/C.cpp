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
inline bool check(string x){//cout<<x<<endl;
	for(int i=0;i<x.length();i++){
		if(x[i]!=x[x.length()-i-1])return false;
	}
	return true;
}
int n,a[100005],ans,zs;
inline int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(); zs=a[n];
	for(int i=1;i<n;i++){zs=gcd(zs,a[i]);}
	if(zs>1){puts("YES");
		writeln(0);return 0;
	}
	for(int i=1;i<n;i++)if(a[i]&1){
		if(a[i+1]&1){ans++; a[i+1]=0;}
		else{
			a[i+1]=0; ans+=2;
		}
	}
	if(a[n]&1){
		if(n==1){
			puts("NO"); return 0;
		}else ans+=2;
	}
	puts("YES");writeln(ans);
}