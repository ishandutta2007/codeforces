#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#define ll long long
using namespace std;
char a[100005],b[100005];
int la,lb,ppp,ans,f[100005],g[100005],fa[100005],ga[100005];
int main(){
	scanf("%s%s",b+1,a+1);
	la=strlen(a+1);
	lb=strlen(b+1);
	ppp=la;
	for (int i=lb;i>=1;i--){
		if (b[i]==a[ppp]&&ppp) ppp--;
		f[i]=la-ppp;
		if (f[i]>f[i+1]) fa[i]=i; else fa[i]=fa[i+1];
	}
	ppp=1;
	for (int i=1;i<=lb;i++){
		if (b[i]==a[ppp]&&ppp<=la) ppp++;
		g[i]=ppp-1;
		if (g[i]>g[i-1]) ga[i]=i; else ga[i]=ga[i-1];
	}
	ans=0;
	for (int i=1;i<=lb;i++)
		if (f[i+1]+g[i]>f[ans+1]+g[ans]&&f[i+1]+g[i]<=la) ans=i;
	if (f[ans+1]+g[ans]==0){
		printf("-");
		return 0;
	}
	for (int i=1;i<=g[ans];i++) printf("%c",a[i]);
	for (int i=la-f[ans+1]+1;i<=la;i++) printf("%c",a[i]);
}