#include<bits/stdc++.h>
using namespace std;

int f[10],deg[10],a[10][10],lev[10];
char s[20][20][20];

int gf(int x) {
	return x==f[x]?x:f[x]=gf(f[x]);
}

int main() {
	int tot;
	scanf("%d",&tot);
	//n=17,m=3,k=18;
	printf("3 17 18\n");
	for (int k=1;k<=18;k++) if (k&1) {
		for (int i=1;i<=17;i++) for (int j=2;j<=3;j++) s[k][i][j]='#';
		for (int i=1;i<=17;i++) s[k][i][1]=(i&1?'.':'#');
		s[k][k][1]='#';
	}
	else {
		for (int i=1;i<=17;i++) for (int j=1;j<=3;j++) s[k][i][j]='.';
		for (int i=1;i<=17;i++) if (i&1) s[k][i][2]='#';
		else s[k][i][1]='#';
		s[k][k-1][2]='.';
	}
	for (int i=1;i<=tot;i++) for (int j=1;j<=tot;j++) scanf("%d",&a[i][j]);
	for (int k=1;k<=tot;k++) for (int i=1;i<=tot;i++) for (int j=1;j<=tot;j++) if (a[i][k] && a[k][j]) a[i][j]=1;
	for (int i=1;i<=tot;i++) f[i]=i;
	for (int i=1;i<=tot;i++) for (int j=i+1;j<=tot;j++) if (a[i][j] && a[j][i]) f[gf(i)]=gf(j);
	for (int i=1;i<=tot;i++) for (int j=1;j<=tot;j++) if (a[i][j] && gf(i)!=gf(j)) deg[f[j]]++;
	queue<int> Q;
	for (int i=1;i<=tot;i++) if (!deg[i]) Q.push(i);
	for (int k=17;!Q.empty();k-=2) {
		int h=Q.front();Q.pop();
		int ed=0;
		for (int i=1;i<=tot;i++) if (gf(i)==h) {
			s[k+1][++ed][3]='0'+i;
			for (int j=1;j<=tot;j++) if (a[i][j] && gf(i)!=gf(j) && --deg[f[j]]==0) Q.push(f[j]);
		}
		lev[h]=k;
	}
	for (int i=1;i<=tot;i++) for (int j=1;j<=tot;j++) if (a[i][j] && gf(i)!=gf(j)) s[lev[f[i]]+1][lev[f[j]]][2]='.';
	for (int k=18;k;k--,puts("")) for (int i=1;i<=17;i++) printf("%s\n",s[k][i]+1);
}