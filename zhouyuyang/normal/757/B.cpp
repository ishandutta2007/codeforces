#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#define N 1000005
using namespace std;
int n,x,ans,a[100005];
inline int read(){
	int x=0;
	char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-48;
	return x;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++){
		x=read();
		for (int j=1;j*j<=x;j++)
			if (x%j==0){
				a[j]++;
				if (j*j!=x) a[x/j]++;
			}
	}
	ans=0;
	for (int i=2;i<=100000;i++) ans=max(ans,a[i]);
	if (ans==0) ans=1;
	printf("%d",ans);
}