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
	long long x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
int n,a[55][55];
int main(){
	n=read(); for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)if(a[i][j]!=1){int flag=false;
			for(int k=1;k<=n;k++){
				for(int l=1;l<=n;l++)if(k!=i&&l!=j&&a[i][l]+a[k][j]==a[i][j]){
					flag=true; break;
				}
			}
				if(!flag){
					puts("NO"); return 0;
				}
		}
	}
	puts("YES");
}