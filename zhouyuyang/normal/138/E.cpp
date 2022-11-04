#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db long double
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
#define fi first
#define se second
#define BG begin
#define ED end

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

#define INF (1ll<<61)
#define sqr(x) ((x)*(x))
using namespace std;

const int N=100005;
const int M=505;
int f[N][26],app[N];
int l[M],r[M],pl[M],pr[M];
char s[N],fl[5],c[M];
int res,m,L,R,n;
long long ans;
void work(int x,int v){
	res-=(app[x]>=L&&app[x]<=R);
	app[x]+=v;
	res+=(app[x]>=L&&app[x]<=R);
}
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	For(i,1,n) For(j,0,25)
		f[i][j]=(f[i-1][j]+(s[i]-97==j));
	scanf("%d%d%d",&m,&L,&R);
	For(i,1,m){
		scanf("%s%d%d",fl,&l[i],&r[i]);
		c[i]=fl[0]-97; pl[i]=0; pr[i]=0;
	}
	For(i,1,n){
		res+=(!L);
		For(j,1,m){
			for (;pr[j]+1<=i&&f[i][c[j]]-f[pr[j]][c[j]]>=l[j];work(++pr[j],1));
			for (;pl[j]+1<=i&&f[i][c[j]]-f[pl[j]][c[j]]>r[j];work(++pl[j],-1));
		}
		ans+=res;
	}
	printf("%lld\n",ans);
}