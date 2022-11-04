#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define uint unsigned
#define db double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define vi vector<int>
#define vpi vector<pii >
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define y1 wzpakking
#define fi first
#define se second
#define BG begin
#define ED end
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)%s
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define sqr(x) (1ll*x*x)
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
#define INF (1ll<<60)
using namespace std;

namespace FastInput{
	/*const int LBC=2333333;
	char LZH[LBC],*SSS=LZH,*TTT=LZH;
	inline char gc(){
		if (SSS==TTT){
			TTT=(SSS=LZH)+fread(LZH,1,LBC,stdin);
			if (SSS==TTT) return EOF;
		}
		return *SSS++;
	}*/
	#define gc getchar
	inline int read(){
		int x=0;
		char ch=gc();
		for (;ch<'0'||ch>'9';ch=gc());
		for (;ch>='0'&&ch<='9';ch=gc())
			x=x*10-48+ch;
		return x;
	}
}
using namespace FastInput;
const int N=2005;
int fa[N],vis[N],Vis[N];
int q[N],cnt[N],Cnt[N];
int n,m,tot;
bitset<N> s[N],S[N],SS[N];
char ch[N];
void BF(int id){
	s[id].reset();
	For(i,1,n) if (!vis[i]) s[id][i]=1;
	For(i,1,m) if (S[i][id]&&!Vis[i]) s[id]&=S[i];
	s[id][id]=0; cnt[id]=s[id].count();
}
void solve(){
	n=read(); m=read();
	CLR(vis,0); CLR(fa,0); CLR(Vis,0);
	For(i,1,m){
		scanf("%s",ch+1); S[i].reset();
		For(j,1,n) S[i][j]=(ch[j]!='0');
		SS[i]=S[i]; Cnt[i]=S[i].count();
		if (Cnt[i]==1) Vis[i]=1;
	}
	For(i,1,n) BF(i);
	For(i,1,n-1) For(j,1,n)
		if (!vis[j]&&cnt[j]){
			fa[j]=s[j]._Find_first(); vis[j]=1;
			For(k,1,m) if (S[k][j]) S[k][j]=0,Cnt[k]--;
			For(k,1,m) if (Vis[k]==0&&Cnt[k]==1)
				Vis[k]=1,q[++tot]=S[k]._Find_first();
			for (;tot;BF(q[tot--]));
			For(k,1,n) if (s[k][j]) s[k][j]=0,cnt[k]--;
			break;
		}
	int tmp=2;
	For(i,1,n) if (!vis[i]) tmp--;
	if (tmp^1) puts("NO");
	else{
		puts("YES");
		For(i,1,n) if (fa[i]) printf("%d %d\n",i,fa[i]);
	}
}
int main(){
	int T=read();
	while (T--) solve();
}