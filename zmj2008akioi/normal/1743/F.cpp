#include <cstdio>
#include <cstring>
#include <vector>
typedef long long LL;
const int w=3e5,N=3e5+10,P=998244353;
int n,l1,r1;LL ans;std::vector<int> L[N],R[N];
template<typename T>T md(T x,T y){return (x+y)/2;}
struct mat{
	int a[2][2];mat(){};
	mat(int x){
		memset(a,0,sizeof(a));
		if(x==0)a[0][0]=3,a[1][0]=1,a[1][1]=2;
		if(x==1)a[0][0]=1,a[0][1]=2,a[1][0]=1,a[1][1]=2;
	}
	int* operator[](int x){return a[x];}
	mat operator*(mat nxt){
		mat res;
		for(int i=0;i<2;++i){
			for(int j=0;j<2;++j){
				int ns=0;
				for(int k=0;k<2;++k)ns+=(LL)a[i][k]*nxt[k][j]%P;
				res[i][j]=ns%P;
			}
		}
		return res;
	}
};
namespace SGT{
	mat s[N<<2];
	int lc(int x){return x<<1;}
	int rc(int x){return (x<<1)|1;}
	void pushup(int x){s[x]=s[lc(x)]*s[rc(x)];}
	void build(int l,int r,int u){
		if(l==r)s[u]=mat(0);
		else build(l,md(l,r),lc(u)),build(md(l,r)+1,r,rc(u)),pushup(u);
	}
	void modify(int l,int r,int u,int g,int d){
		if(l==r){s[u]=mat(d);return;}
		if(md(l,r)>=g)modify(l,md(l,r),lc(u),g,d);
		else modify(md(l,r)+1,r,rc(u),g,d);
		pushup(u);
	}
	void fb(){build(2,n,1);}
	void fm(int g,int d){modify(2,n,1,g,d);}
	int fq(int x){return s[1][x][1];}
}
int main(){
	scanf("%d %d %d",&n,&l1,&r1);
	for(int l,r,i=2;i<=n;++i){
		scanf("%d %d",&l,&r);
		L[l].push_back(i),R[r+1].push_back(i);
	}
	SGT::fb();
	for(int i=0;i<=w;++i){
		for(int j:L[i])SGT::fm(j,1);
		for(int j:R[i])SGT::fm(j,0);
		ans+=SGT::fq(l1<=i&&i<=r1);
	}
	printf("%lld",ans%P);return 0;
}