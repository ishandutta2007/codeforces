#include <bits/stdc++.h>
using namespace std;
const int N=2005;
int n,m,tot[N];
char ch[N][N];
bool check(){
	for (int i=1;i<=n;i++){
		bool flag=1;
		for (int j=1;j<=m&&flag;j++)
			if (tot[j]-(ch[i][j]-'0')<1)
				flag=0;
		if (flag)
			return 1;
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%s",ch[i]+1);
	memset(tot,0,sizeof tot);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			tot[j]+=ch[i][j]-'0';
	puts(check()?"YES":"NO");
	return 0;
}