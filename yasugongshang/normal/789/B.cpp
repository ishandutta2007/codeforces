#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
inline long long	read()// 
{
	long long x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(long long a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(long long a){
	write(a); puts("");
}
long long b1,q,l,m;
map<long long,long long>M;
int main(){
	b1=read(); q=read(); l=read(); m=read(); long long zs=0; long long ans=0;
	for(long long i=1;i<=m;i++)M[read()]=1;
	for(long long i=b1;abs(i)<=l;i*=q){
		if(M[i]==0){
			ans++;
		}
		zs++;
		if(zs==1000000){
			if(!ans)puts("0");else if(ans==1)cout<<ans<<endl; else puts("inf"); return 0;
		}
	}
	cout<<ans<<endl;
}