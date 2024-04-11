#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
typedef bitset<N>B;
B a[N],t;
bool gg[N][N],b[N];
int n,i,j,k,x,y,d[N],dd[N],e1[N],e2[N],xb;
inline bool cmp(const B&a,const B&b){return a.count()<b.count();}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)for(scanf("%d",&k);k--;)scanf("%d",&x),a[i][x]=1;
	for(i=2;i<=n;++i)if(a[i]!=a[1])break;if(i>n){for(i=2;i<=n;++i)printf("1 %d\n",i);return 0;}
	for(i=1;i<n;++i)for(j=i+1;j<=n;++j)if((t=a[i]&a[j]).count()==2){
		x=0;for(k=1;k<=n;++k)if(t[k])(x?y:x)=k;
		if(!gg[x][y])gg[x][y]=1,e1[++xb]=x,e2[xb]=y,++dd[x],++dd[y],printf("%d %d\n",x,y);
	}
	if(xb==1){
		for(j=1;j<=n;++j)if(a[j].count()<n)break;
		for(i=1;i<=n;++i)if(a[j][i] && i!=e1[1] && i!=e2[1])x=i,printf("%d %d\n",i,e1[1]);
		for(i=1;i<=n;++i)if(!a[i][x]){for(j=1;j<=n;++j)if(a[i][j] && j!=e1[1] && j!=e2[1])printf("%d %d\n",j,e2[1]);return 0;}
	}
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;++i)if(!b[i]){
		memset(d+1,0,n<<2);
		for(j=1;j<=xb;++j)if(a[i][e1[j]] && a[i][e2[j]])++d[e1[j]],++d[e2[j]];
		x=0;for(j=1;j<=n;++j)if(d[j]>1)++x,y=j;if(x>1)continue;
		if(!x)for(j=1;j<=n;++j)if(d[j] && dd[j]==1)y=j;
		for(j=1;j<=n;++j)if(a[i][j]){if(!dd[j])printf("%d %d\n",j,y);else a[i][j]=0;}
		for(j=i+1;j<=n;++j)if(!b[j] && (a[i]&a[j]).any())b[j]=1;
	}
	return 0;
}