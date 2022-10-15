#include <cstdio>
const int N=2e3+10;
int T,n,f[N],a[N][N];
void swp(int &x,int &y){x^=y^=x^=y;}
int find(int x){return f[x]==x?f[x]:f[x]=find(f[x]);}
void merge(int x,int y){f[find(x)]=find(y);}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=(n<<1);++i)f[i]=i;
		for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)scanf("%d",&a[i][j]);
		for(int i=1;i<n;++i){
			for(int j=i+1;j<=n;++j){
				if(a[i][j]==a[j][i])continue;
				if(a[i][j]<a[j][i]){
					if(find(i)==find(j+n))swp(a[i][j],a[j][i]);
					else merge(i,j),merge(i+n,j+n);
				}
				else if(a[i][j]>a[j][i]&&find(i)!=find(j))swp(a[i][j],a[j][i]),merge(i,j+n),merge(i+n,j);
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j)printf("%d ",a[i][j]);
			putchar('\n');
		}
	}
	return 0;
}