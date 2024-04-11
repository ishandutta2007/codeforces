#include<bits/stdc++.h>
#define maxn 100100
using namespace std;
char a[maxn],b[maxn];
int f[maxn],g[maxn],i,j,nf,ng,ans=0,ansl,ansr;
int main(){
	scanf("%s%s",a,b);
	int la=strlen(a);
	int lb=strlen(b);
	ans=lb,ansl=-1,ansr=lb;
	nf=-1,ng=lb;
	for(i=0,j=0;i<lb;++i){
		while(j<la&&a[j]!=b[i])j++;
		f[i]=j;
		if(j<la)nf=i;
		if(j<la)j++;
	}
	for(i=lb-1,j=la-1;i>=0;--i){
		while(j>=0&&a[j]!=b[i])j--;
		g[i]=j;
		if(j>=0)ng=i;
		if(j>=0)j--;
	}
	if(ans>lb-nf-1)ans=lb-nf-1,ansl=nf,ansr=lb;
	if(ans>ng)ans=ng,ansl=-1,ansr=ng;
//	printf("[%d,%d]",ng,nf);
	for(int i=0,j=ng;i<=nf;++i){
		while(j<lb&&f[i]>=g[j])j++;
//		printf("[%d,%d]",f[i],g[j]);
		if(j==lb)break;
		if(ans>j-i-1)ans=j-i-1,ansl=i,ansr=max(i+1,j);
	}
//	printf("[%d,%d]",ansl,ansr);
	if(ans==lb){
		putchar('-');
	} else {
		for(int i=0;i<=ansl;++i)putchar(b[i]);
		for(int i=ansr;i<lb;++i)putchar(b[i]);
	}
}