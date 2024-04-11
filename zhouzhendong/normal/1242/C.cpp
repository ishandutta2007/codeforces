#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define kill _z_kill
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
#define User_Time ((double)clock()/CLOCKS_PER_SEC)
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned uint;
typedef long double LD;
typedef vector <int> vi;
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
template <class T> void ckmax(T &x,const T &y){
	if (x<y)
		x=y;
}
template <class T> void ckmin(T &x,const T &y){
	if (x>y)
		x=y;
}
LL absl(LL x){
	return x<0?-x:x;
}
//int Pow(int x,int y){
//	int ans=1;
//	for (;y;y>>=1,x=(LL)x*x%mod)
//		if (y&1)
//			ans=(LL)ans*x%mod;
//	return ans;
//}
//void Add(int &x,int y){
//	if ((x+=y)>=mod)
//		x-=mod;
//}
//void Del(int &x,int y){
//	if ((x-=y)<0)
//		x+=mod;
//}
//int Add(int x){
//	return x>=mod?x-mod:x;
//}
//int Del(int x){
//	return x<0?x+mod:x;
//}
const int N=15,M=5005;
int n;
vi a[N];
vector <pii> pre[N];
LL s[N];
LL sum[1<<N];
int f[1<<N],lg[1<<N];
pii way[1<<N][N];
map <LL,pii> Map;
int vis[N][M];
pii st[M];
int top=0,Time=0;
void dfs(int i,int j){
	if (i==-1)
		return;
//	printf("dfs(%d,%d)\n",i,j);
	if (vis[i][j]&&vis[i][j]!=Time)
		return;
	if (vis[i][j]==Time){
		int p=top;
		int w=1<<st[p].fi;
		while (st[p].fi!=i)
			p--,w|=1<<st[p].fi;
		if (st[p].se!=j)
			return;
		if (f[w])
			return;
		f[w]=1;
		For(i,p+1,top)
			way[w][st[i].fi]=mp(st[i].se,st[i-1].fi);
		way[w][st[p].fi]=mp(st[p].se,st[top].fi);
//		outval(w);
//		For(i,p,top)
//			printf("-- %d %d\n",st[i].fi,st[i].se);
//		For(i,0,n-1)
//			printf("%d %d\n",a[i][way[w][i].fi],way[w][i].se);
//		outtag();
		return;
	}
	st[++top]=mp(i,j);
	vis[i][j]=Time;
	dfs(pre[i][j].fi,pre[i][j].se);
	top--;
}
int main(){
	n=read();
	For(i,0,n-1){
		int cnt=read();
		while (cnt--)
			a[i].pb(read());
		sort(a[i].begin(),a[i].end());
		for (auto v : a[i])
			s[i]+=v;
	}
	For(i,2,(1<<n)-1)
		lg[i]=lg[i>>1]+1;
	For(i,1,(1<<n)-1)
		sum[i]=sum[i-(i&-i)]+s[lg[i&-i]];
	LL all=sum[(1<<n)-1];
	if (all%n!=0)
		return puts("No"),0;
	all/=n;
	For(i,0,n-1)
		For(j,0,(int)a[i].size()-1)
			Map[a[i][j]]=mp(i,j);
	For(i,0,n-1){
		pre[i].resize(a[i].size());
		For(j,0,(int)a[i].size()-1)
			if (Map.count((LL)a[i][j]+(all-s[i]))){
				pre[i][j]=Map[(LL)a[i][j]+(all-s[i])];
				if (all!=s[i]&&pre[i][j].fi==i)
					pre[i][j]=mp(-1,-1);
			}
			else
				pre[i][j]=mp(-1,-1);
	}
	For(i,0,n-1)
		For(j,0,(int)a[i].size()-1)
			++Time,dfs(i,j);
	f[0]=1;
	For(i,1,(1<<n)-1){
		if (f[i])
			continue;
		for (int j=(i-1)&i;j;j=(j-1)&i)
			if (f[j]&&f[i^j]){
				f[i]=1;
				For(k,0,n-1)
					if (j>>k&1)
						way[i][k]=way[j][k];
					else if (i>>k&1)
						way[i][k]=way[i^j][k];
				break;
			}
	}
	int t=(1<<n)-1;
	if (!f[t])
		return puts("No"),0;
	puts("Yes");
	For(i,0,n-1)
		printf("%d %d\n",a[i][way[t][i].fi],way[t][i].se+1);
	return 0;
}