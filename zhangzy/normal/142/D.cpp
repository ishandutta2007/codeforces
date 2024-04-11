#include<bits/stdc++.h>
#define fi return 0*puts("First")
#define se return 0*puts("Second")
using namespace std;

int n,m,k,c[10],r,g,rr,gg,fl;
char s[233];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		r=g=fl=0;
		for (int j=1;j<=m;j++)
			if (s[j]=='G') g=j;
			else if (s[j]=='R') r=j;
			else fl=1;
		if (!g&&!r) continue;
		if (!g) rr=fl;
		else if (!r) gg=fl;
		else for (int t=abs(r-g)-1,w=0;t;t>>=1,w++) c[w]+=t&1;
	}
	if (rr&&gg) return 0*puts("Draw");
	if (gg) fi;
	if (rr) se;
	for (int i=0;i<10;i++) if (c[i]%(k+1)) fi;
	se;
}