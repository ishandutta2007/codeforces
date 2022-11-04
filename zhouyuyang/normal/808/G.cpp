#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 100005
using namespace std;
char s1[N],s2[N];
int nxt[N],f[N],g[N],fl;
int main(){
	scanf("%s%s",s1+1,s2+1);
	int l1=strlen(s1+1),l2=strlen(s2+1);
	for (int i=2,j=0;i<=l2;++i){
		while (j&&s2[i]!=s2[j+1]) j=nxt[j];
		if (s2[i]==s2[j+1]) ++j;
		nxt[i]=j;
	}
	for (int i=l2;i<=l1;++i){
		fl=1; g[i]=g[i-1];
		for (int j=0;j<l2&&fl;++j)
			if (s1[i-j]!='?'&&s1[i-j]!=s2[l2-j])
				fl=0;
		if (!fl) continue;
		f[i]=g[i-l2];
		for (int j=nxt[l2];j;j=nxt[j])
			f[i]=max(f[i],f[i-(l2-j)]);
		g[i]=max(g[i],++f[i]);
	}
	printf("%d\n",g[l1]);
}