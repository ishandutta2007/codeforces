#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
                    For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> pii;
LL read(){
    LL x=0,f=0;
    char ch=getchar();
    while (!isdigit(ch))
        f=ch=='-',ch=getchar();
    while (isdigit(ch))
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
const int N=755,S=1e7+5;
int n;
int pos[N];
int Next[S][2],cnt=1,Fail[S],val[S],e[S];
vector <int> id[S];
char s[S];
void insert(char *s,int ID){
	int len=strlen(s);
	int x=1;
	For(i,0,len-1){
		int t=s[i]-'a';
		if (!Next[x][t])
			Next[x][t]=++cnt;
		x=Next[x][t];
		id[x].pb(ID);
	}
	pos[ID]=x;
	e[x]=ID;
}
bitset <N> g[N];
void build(){
	queue <int> q;
	Next[0][0]=Next[0][1]=1;
	q.push(1);
	while (!q.empty()){
		int x=q.front();
		q.pop();
		val[x]=val[Fail[x]];
		if (val[x])
			for (auto i : id[x])
				g[i][val[x]]=1;
		if (e[x])
			val[x]=e[x];
		if (val[x])
			for (auto i : id[x])
				g[i][val[x]]=1;
		For(i,0,1){
			if (!Next[x][i]){
				Next[x][i]=Next[Fail[x]][i];
				continue;
			}
			int y=Next[x][i];
			Fail[y]=Next[Fail[x]][i];
			q.push(y);
		}
	}
}
int Match[N],vis[N];
int dfs(int x){
	For(y,1,n)
		if (x!=y&&!vis[y]&&g[y][x]){
			vis[y]=1;
			if (!Match[y]||dfs(Match[y])){
				Match[y]=x;
				return 1;
			}
		}
	return 0;
}
int main(){
	n=read();
	For(i,1,n){
		cin>>s;
		insert(s,i);
	}
	build();
	For(k,1,n)
		For(i,1,n)
			if (g[i][k])
				g[i]|=g[k];
//	For(i,1,n){
//		For(j,1,n)
//			printf("%d",(int)g[i][j]);
//		puts("");
//	}
	For(i,1,n){
		clr(vis);
		dfs(i);
	}
	clr(vis);
	For(i,1,n)
		if (Match[i])
			vis[Match[i]]=1;
//	outarr(Match,1,n);
	vector <int> h;
	For(i,1,n)
		if (!vis[i])
			h.pb(i);
	int flag=1;
	while (flag){
		flag=0;
		for (auto &i : h){
			for (auto &j : h)
				if (i!=j){
					while (g[i][j]){
						flag=1;
						i=Match[i];
					}
					if (flag)
						break;
				}
			if (flag)
				break;
		}
	}
	printf("%d\n",(int)h.size());
	for (auto i : h)
		printf("%d ",i);
	puts("");
	return 0;
}