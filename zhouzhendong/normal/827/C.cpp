#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x;
}
int n,m;
int c[4][11][10][N];
void add(int *c,int x,int v){
	for (;x<=n;x+=x&-x)
		c[x]+=v;
}
int sum(int *c,int x){
	int ans=0;
	for (;x;x-=x&-x)
		ans+=c[x];
	return ans;
}
char s[N];
int Turn[300];
int main(){
	Turn['A']=0,Turn['C']=1,Turn['G']=2,Turn['T']=3;
	memset(c,0,sizeof c);
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=10;i++)
		for (int j=1;j<=n;j++)
			add(c[Turn[s[j]]][i][j%i],j,1);
	m=read();
	while (m--){
		int opt=read(),L=read(),R;
		char t[15];
		if (opt==1){
			scanf("%s",t);
			for (int i=1;i<=10;i++)
				add(c[Turn[s[L]]][i][L%i],L,-1);
			s[L]=t[0];
			for (int i=1;i<=10;i++)
				add(c[Turn[s[L]]][i][L%i],L,1);
		}
		else {
			R=read();
			scanf("%s",t+1);
			int r=strlen(t+1),ans=0;
			for (int i=1;i<=r;i++){
				int *now=c[Turn[t[i]]][r][(L+i-1)%r];
				ans+=sum(now,R)-sum(now,L-1);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}