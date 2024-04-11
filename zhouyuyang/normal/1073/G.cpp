#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
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
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define sqr(x) (1ll*x*x)
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
#define INF (1<<29)
using namespace std;
const int N=200005;
char s[N];
int n,Q;
int rk[N],SA[N];
int x[N],y[N],cnt[N];
vector<int> v1,v2;
bool cmp(int i,int j,int k){
	return y[i]!=y[j]||((i+k>n?-1:y[i+k])!=(j+k>n?-1:y[j+k]));
}
void buildSA(){
	int m=26;
	For(i,1,n) cnt[x[i]=s[i]-'a'+1]++;
	For(i,1,m) cnt[i]+=cnt[i-1];
	Rep(i,n,1) SA[cnt[x[i]]--]=i;
	for (int k=1;k<n;k<<=1){
		int p=0;
		For(i,n-k+1,n) y[++p]=i;
		For(i,1,n) if (SA[i]>k) y[++p]=SA[i]-k;
		For(i,0,m) cnt[i]=0;
		For(i,1,n) cnt[x[y[i]]]++;
		For(i,1,m) cnt[i]+=cnt[i-1];
		Rep(i,n,1) SA[cnt[x[y[i]]]--]=y[i];
		swap(x,y); m=x[SA[1]]=1;
		For(i,2,n) x[SA[i]]=(m+=cmp(SA[i],SA[i-1],k));
	}
}
int H[N];
void buildH(){
	int p=0;
	For(i,1,n) rk[SA[i]]=i;
	For(i,1,n) if (rk[i]!=1){
		int p1=i,p2=SA[rk[i]-1]; p-=(p!=0);
		for (;s[p1+p]==s[p2+p];p++);
		H[rk[i]]=p; 
	}
}
int LG[N],st[20][N];
void RMQinit(){
	For(i,2,n) LG[i]=LG[i/2]+1;
	For(i,1,n) st[0][i]=H[i];
	For(j,1,LG[n]) For(i,1,n-(1<<j)+1)
		st[j][i]=min(st[j-1][i],st[j-1][i+(1<<(j-1))]);
}
int LCP(int x,int y){
	if (x==y) return n-x+1;
	int l=min(rk[x],rk[y])+1,r=max(rk[x],rk[y]);
	int k=LG[r-l+1];
	return min(st[k][l],st[k][r-(1<<k)+1]);
}
void BF1(){
	ll ans=0;
	for (auto i:v1) for (auto j:v2) ans+=LCP(i,j);
	printf("%lld\n",ans);
}
int L[N],R[N],q[N];
void STKinit(){
	H[0]=H[n+1]=-1; q[0]=q[1]=1;
	For(i,1,n){
		for (;*q&&H[i]<H[q[*q]];--*q);
		L[i]=q[*q]; q[++*q]=i;
	}
	q[0]=1; q[1]=n+1;
	Rep(i,n,1){
		for (;*q&&H[i]<=H[q[*q]];--*q);
		R[i]=q[*q]; q[++*q]=i;
	}
}
ll s1[N],s2[N];
void BF2(){
	For(i,1,n+1) s1[i]=s2[i]=0;
	for (auto i:v1) s1[rk[i]]++;
	for (auto i:v2) s2[rk[i]]++;
	ll ans=0;
	For(i,1,n+1){
		ans+=(n+1-SA[i])*s1[i]*s2[i];
		s1[i]+=s1[i-1]; s2[i]+=s2[i-1];
	}
	For(i,1,n)
		ans+=((s1[i-1]-s1[max(L[i]-1,0)])*(s2[R[i]-1]-s2[i-1])+
			  (s2[i-1]-s2[max(L[i]-1,0)])*(s1[R[i]-1]-s1[i-1]))
			  *H[i];
	printf("%lld\n",ans);
}
int main(){
	scanf("%d%d",&n,&Q);
	scanf("%s",s+1);
	buildSA();
	buildH();
	RMQinit();
	STKinit(); 
	while (Q--){
		int l1,l2;
		scanf("%d%d",&l1,&l2);
		v1.resize(l1); v2.resize(l2);
		For(i,0,l1-1) scanf("%d",&v1[i]);
		For(i,0,l2-1) scanf("%d",&v2[i]);
		if (1ll*l1*l2<=n) BF1();
		else BF2();
	}
}