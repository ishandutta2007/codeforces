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
inline void write(long long a){
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
const int N=100005;
int zs,z,n,a[N],b[N],color[N],quea[N],queb[N];
int main(){
	n=read();
	for(int i=1;i<n;i++){a[i]=read(); b[i]=read();}
	for(int i=1;i<=n;i++)color[i]=read();
	for(int i=1;i<n;i++){
		if(color[a[i]]!=color[b[i]]){
			quea[++zs]=a[i]; queb[zs]=b[i];
		}
	}
	if(!zs){puts("YES");write(1);} else if(zs==1){
		 puts("YES"); write(quea[1]);
	}else{
		if(quea[1]==quea[2]||quea[1]==queb[2])z=quea[1]; else if(queb[1]==quea[2]||queb[1]==queb[2])z=queb[1]; else {
			puts("NO"); return 0;
		}
		for(int i=3;i<=zs;i++)if(quea[i]!=z&&queb[i]!=z){
			puts("NO"); return 0;
		}
		puts("YES"); write(z);
	}
}