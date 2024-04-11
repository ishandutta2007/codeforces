#include<bits/stdc++.h>
using namespace std;
char s[1001000];
long long ans;
int a[1001000],n,b[1001000],m,cc[233],cnt[4][4],l=1,r;

void cg(int x,int v){
	cnt[b[x-1]][b[x]]+=v;
}

int main(){
	cc['B']=1, cc['G']=2, cc['R']=3;
	scanf("%s",s+1); n=strlen(s+1);
	for (int i=1;i<=n;++i) a[i]=cc[s[i]];
	scanf("%s",s+1); m=strlen(s+1);
	for (int i=1;i<=m;++i) b[i]=cc[s[i]];
	for (int i=1;i<=n;++i){
		if (b[l]==a[i-1]&&l<=m) cg(l++,-1);
		if (b[r]==a[i-1]&&r<m) cg(++r,1);
		for (;b[r]!=a[i]&&r<m;) cg(++r,1);
		if (l>r) continue;
		cg(l++,-1);
		ans+=1+r-l+1;
		if (a[i]!=a[i-1]) ans-=cnt[a[i]][a[i-1]];
		cg(--l,1);
	}
	cout<<ans;
}