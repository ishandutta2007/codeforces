#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
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
const int N=1005*2;
namespace SAM{
	int Next[N][26],fa[N],len[N];
	int ndcnt=1,lasnd=1;
	void extend(int c){
		int p=lasnd,np=++ndcnt,q,nq;
		len[np]=len[p]+1;
		for (;p&&!Next[p][c];p=fa[p])
			Next[p][c]=np;
		if (!p)
			fa[np]=1;
		else {
			q=Next[p][c];
			if (len[p]+1==len[q])
				fa[np]=q;
			else {
				nq=++ndcnt;
				For(i,0,25)
					Next[nq][i]=Next[q][i];
				fa[nq]=fa[q],len[nq]=len[p]+1;
				fa[q]=fa[np]=nq;
				for (;p&&Next[p][c]==q;p=fa[p])
					Next[p][c]=nq;
			}
		}
		lasnd=np;
	}
}
using namespace SAM;
int n,m;
LL k;
char s[N],t[N];
int tax[N],id[N];
LL val[N];
int getkth(LL k,char *s){
	int cnt=0;
	int x=1;
	while (1){
		k--;
		if (!k)
			break;
		For(i,0,25){
			if (val[Next[x][i]]>=k){
				s[++cnt]='a'+i;
				x=Next[x][i];
				break;
			}
			k-=val[Next[x][i]];
		}
	}
	s[cnt+1]='\0';
	return cnt;
}
const LL LLINF=1.1e18;
LL dp[N][N];
int l[N];
void Add(LL &x,LL y){
	x=min(x+y,k);
}
int check(LL K){
	int len=getkth(K,t);
	For(i,1,n){
		l[i]=0;
		while (i+l[i]<=n&&1+l[i]<=len&&s[i+l[i]]==t[1+l[i]])
			l[i]++;
		if (i+l[i]<=n&&1+l[i]<=len&&s[i+l[i]]>t[1+l[i]])
			l[i]=i+l[i];
		else if (l[i]==len)
			l[i]=min(n+1,i+len-1);
		else
			l[i]=n+1;
	}
	clr(dp);
	dp[0][0]=1,dp[1][0]=-1;
	For(i,1,n){
		For(j,0,m)
			Add(dp[l[i]][j+1],dp[i-1][j]);
		For(j,0,m)
			Add(dp[i][j],dp[i-1][j]);
	}
	return dp[n][m]>=k;
}
int main(){
	n=read(),m=read(),k=read();
	scanf("%s",s+1);
	For(i,1,n)
		extend(s[i]-'a');
	For(i,1,ndcnt)
		tax[len[i]]++;
	For(i,1,n)
		tax[i]+=tax[i-1];
	For(i,1,ndcnt)
		id[tax[len[i]]--]=i;
	Fod(i,ndcnt,1){
		int x=id[i];
		val[x]=1;
		For(c,0,25)
			val[x]+=val[Next[x][c]];
	}
	LL L=2,R=val[1],ans=2;
	while (L<=R){
		LL mid=(L+R)>>1;
		if (check(mid))
			L=mid+1,ans=mid;
		else
			R=mid-1;
	}
	int len=getkth(ans,t);
	cout<<t+1<<endl;
	return 0;
}