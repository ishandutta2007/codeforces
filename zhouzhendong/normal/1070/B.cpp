#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=-1,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
const int N=200005;
int n;
int Next[N*34][2],c[N*34],tot=1;
LL res[N];
int kr[N],cnt=0;
void Add(int t,LL v,int k){
	int x=1;
	for (int i=31;i>=k;i--){
		int y=v>>i&1;
		if (!Next[x][y])
			Next[x][y]=++tot;
		x=Next[x][y];
	}
	c[x]|=1<<t;
}
int dfs(int x){
	if (!x)
		return 1;
	int ls=Next[x][0],rs=Next[x][1];
	if (!dfs(ls)||!dfs(rs))
		return 0;
	int cc=c[ls]|c[rs];
	if (c[x]==3||(c[x]==1&&(cc&2))||(c[x]==2&&(cc&1)))
		return 0;
	c[x]|=c[ls]|c[rs];
}
void Out(LL v,int k,int f){
	printf("%d.%d.%d.%d/%d",
	(int)((v>>24)&255),
	(int)((v>>16)&255),
	(int)((v>>8)&255),
	(int)((v>>0)&255),k);
	if (f)
		puts("");
}
void solve(int x,LL v,int d){
	if (!x||!c[x])
		return;
	if (c[x]==3){
		solve(Next[x][0],v,d-1);
		solve(Next[x][1],v|(1<<(d-1)),d-1);
		return;
	}
	if (c[x]==1){
		cnt++;
		res[cnt]=v;
		kr[cnt]=32-d;
	}
}
int main(){
	n=read();
	while (n--){
		char s[1000];
		scanf("%s",&s);
		char *p=s;
		int t=(*p)!='-';
		s[strlen(s)]='#';
		LL v=0,k=32;
		for (int i=0;i<4;i++){
			p++;
			int x=0;
			while (isdigit(*p))
				x=(x<<1)+(x<<3)+((*p)^48),p++;
			v=(v<<8)|x;
		}
		if ((*p)=='/'){
			p++;
			int x=0;
			while (isdigit(*p))
				x=(x<<1)+(x<<3)+((*p)^48),p++;
			k=x;
		}
		Add(t,v,32-k);
	}
	if (!dfs(1))
		return puts("-1"),0;
	solve(1,0,32);
	cout << cnt << endl;
	for (int i=1;i<=cnt;i++)
		Out(res[i],kr[i],i<cnt);
	return 0;
}