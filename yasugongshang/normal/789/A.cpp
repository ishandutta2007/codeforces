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
long long ans,an;
int n,k,a[100005];
int main(){
	n=read(); k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		ans+=(a[i]+k-1)/k;
	}
	if(ans%2)an=ans/2+1; else an=ans/2;
	cout<<an<<endl;
}