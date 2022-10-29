#include<cstdio>
#define maxn 1011
using namespace std;
int n,m,a[maxn][maxn],left[maxn],right[maxn],up[maxn],down[maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;++i){
		left[i]=m,right[i]=1;
		for(int j=1;j<=m;++j)if(a[i][j]){
			left[i]=j-1;
			break;
		}
		for(int j=m;j>=1;--j)if(a[i][j]){
			right[i]=j+1;
			break;
		}
	}
	
	for(int j=1;j<=m;++j){
		up[j]=n,down[j]=1;
		for(int i=1;i<=n;++i)if(a[i][j]){
			up[j]=i-1;
			break;
		}
		for(int i=n;i>=1;--i)if(a[i][j]){
			down[j]=i+1;
			break;
		}
	}	
	int ans=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)if(!a[i][j]){
			if(j>left[i])ans++;
			if(j<right[i])ans++;
			if(i>up[j])ans++;
			if(i<down[j])ans++;
		}
	printf("%d",ans);
}