#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define bas 137
#define N 5000005
#define ull unsigned long long
using namespace std;
char a[N];
ull hsh1[N],hsh2[N],P[N];
int n,ans,dep[N];
ull hash1(int x,int y){
	return hsh1[y]-hsh1[x-1]*P[y-x+1];
}
ull hash2(int x,int y){
	return hsh2[x]-hsh2[y+1]*P[y-x+1];
}
int main(){
	scanf("%s",a+1);
	n=strlen(a+1);
	P[0]=1;
	for (int i=1;i<=n;i++){
		hsh1[i]=hsh1[i-1]*bas+a[i];
		P[i]=P[i-1]*bas;
	}
	for (int i=n;i;i--)
		hsh2[i]=hsh2[i+1]*bas+a[i];
	ans=dep[1]=1;
	for (int i=2;i<=n;i++){
		int len=i/2;
		dep[i]=(hash1(1,len)==hash2(i-len+1,i))?dep[len]+1:0;
		ans+=dep[i];
	}
	printf("%d\n",ans);
}