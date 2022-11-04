#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define fi first
#define se second
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
 
#define inf 1e18
#define sqr(x) ((x)*(x))
using namespace std;
const int N=200005;
char S[N],T[N];
int nxt[N],v[N],cnt[N];
int n,m;
void EXKMP(char *s,int *v,int n){
	v[1]=n;
	int L=1,R=1;
	For(i,2,n){
		v[i]=(i>R?0:min(R-i+1,v[i-L+1]));
		for (;v[i]+1<=n&&s[i+v[i]]==s[v[i]+1];v[i]++);
		if (R<i+v[i]-1) L=i,R=i+v[i]-1;
	}
}
void KMP(char *s,int *nxt,int n){
	int j=0;
	For(i,2,n){
		for (;j&&s[i]!=s[j+1];j=nxt[j]);
		nxt[i]=(j+=(s[i]==s[j+1]));
	}
}
int main(){
	scanf("%s%s",S+1,T+1);
	int n=strlen(S+1),m=strlen(T+1);
	For(i,1,n) T[i+m]=S[i];
	For(i,1,m) S[i]=T[i];
	S[m+1]=0;
	EXKMP(T,v,n+m);
	KMP(S,nxt,m);
	For(i,m+2,n+m) cnt[v[i]]++;
	Rep(i,n,1) cnt[i]+=cnt[i+1];
	ll ans=1ll*n*m;
	For(i,2,m) if (nxt[i])
		ans-=cnt[i-nxt[i]];
	printf("%lld\n",ans);
}