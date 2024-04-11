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
const int N=1000005;
int n,m,k,tong[N];
int main(){
	n=read(); m=read(); k=read();
	for(int i=1;i<=m;i++)tong[read()]=1; int kk=1;
	for(int i=1;i<=k;i++){
		int s1=read(),s2=read();
		if(tong[kk])break;
		if(s1==kk)kk=s2; else if(s2==kk)kk=s1;
	}
	cout<<kk<<endl;
}