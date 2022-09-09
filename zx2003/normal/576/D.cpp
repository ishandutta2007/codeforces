#include<bits/stdc++.h>
using namespace std;
const int N=185;
typedef bitset<N>B;
struct edge{
	int u,v,w;
	inline bool operator<(const edge&rhs)const{return w<rhs.w;}
	inline void in(){scanf("%d%d%d",&u,&v,&w);}
}e[40005];
int n,m,c,i,j,w[N],p,ans=-1,d[N];
vector<int>ee[N];
struct mat{
	B b[N];
	inline mat operator*(const mat&rhs)const{
		static mat ans;int i,j,k;
		for(i=1;i<=n;++i)ans.b[i].reset();
		for(i=1;i<=n;++i)for(j=1;j<=n;++j)if(b[i][j])ans.b[i]|=rhs.b[j];
		return ans;
	}
	inline void trs(const B&a,B&c){
		c.reset();
		for(int i=1;i<=n;++i)if(a[i])c|=b[i];
	}
}A,C,D,I;
B a,b;
inline void bfs(int dd){
	static int q[N];int t=0,w=0,i,v;
	memset(d+1,0,n<<2);
	for(i=1;i<=n;++i)if(a[i])q[++w]=i,d[i]=1;
	for(;t<w;)for(int u:ee[v=q[++t]])if(!d[u])d[u]=d[v]+1,q[++w]=u;
	if(d[n] && (ans==-1 || dd+d[n]-1<ans))ans=dd+d[n]-1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)e[i].in(),w[++c]=e[i].w;
	sort(w+1,w+c+1);c=unique(w+1,w+c+1)-w-1;for(i=1;i<=m;++i)e[i].w=lower_bound(w+1,w+c+1,e[i].w)-w;
	if(w[1]>0)return puts("Impossible"),0;
	sort(e+1,e+m+1);
	for(i=1;i<=n;++i)I.b[i][i]=1;a[1]=1;
	for(i=p=1;i<=c;++i){
		for(;p<=m && e[p].w<=i;++p)ee[e[p].u].push_back(e[p].v),A.b[e[p].u][e[p].v]=1;
		bfs(w[i]);if(i==c)break;
		C=I;D=A;
		for(int j=w[i+1]-w[i];j;j>>=1,D=D*D)if(j&1)C=C*D;
		C.trs(a,b);a=b;
	}
	if(ans==-1)puts("Impossible");else printf("%d\n",ans);
	return 0;
}