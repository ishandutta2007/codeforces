#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=50005;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x;
}
int n,m,q;
int w[N];
int Next[N][2],cnt[N],tot=1;
int ans[1<<12][105];
char now[20];
void build(char s[]){
	int rt=1,t,len=strlen(s);
	for (int i=0;i<len;i++){
		int t=s[i]-'0';
		if (!Next[rt][t])
			Next[rt][t]=++tot;
		rt=Next[rt][t];
	}
	cnt[rt]++;
}
void solve(int x,int W,int d,int id){
	if (!x||W>100)
		return;
	if (d>n){
		ans[id][W]+=cnt[x];
		return;
	}
	for (int i=0;i<2;i++)
		solve(Next[x][i],W+(i==(now[d]-'0')?w[d]:0),d+1,id);
}
int main(){
	n=read(),m=read(),q=read();
	for (int i=1;i<=n;i++)
		w[i]=read();
	for (int i=1;i<=m;i++){
		char s[20];
		scanf("%s",s);
		build(s);
	}
	memset(ans,0,sizeof ans);
	for (int i=0;i<(1<<n);i++){
		memset(now,0,sizeof now);
		int v=i;
		for (int j=n;j>=1;j--)
			now[j]='0'+(v&1),v>>=1;
		solve(1,0,1,i);
		for (int j=1;j<=100;j++)
			ans[i][j]+=ans[i][j-1];
	}
	while (q--){
		scanf("%s",now+1);
		int v=0;
		for (int i=1;i<=n;i++)
			v=v*2+(now[i]-'0');
		int k=read();
		printf("%d\n",ans[v][k]);
	}
	return 0;
}