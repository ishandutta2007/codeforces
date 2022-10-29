#include<bits/stdc++.h>
#define maxn 300100
using namespace std;
char S[maxn<<1];
int n,f[maxn<<1];
int main(){
	scanf("%s",S+1);
	n=strlen(S+1);
	for(int i=n+1;i<=2*n;++i)
		S[i]=S[i-n];
	int mx=0;
	for(int i=1;i<=n*2;++i){
		if(i>1&&S[i]!=S[i-1])f[i]=f[i-1]+1;
		else f[i]=1;
		mx=max(mx,f[i]);
	}
	mx=min(mx,n);
	printf("%d\n",mx);
}