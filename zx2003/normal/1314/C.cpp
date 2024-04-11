#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1005;
int n,m,i,j,k,lcp[N][N],rb[N];
char c[N];
struct subs{
	int l,r;
	inline bool operator<(const subs&rhs)const{
		int z=min(lcp[l][rhs.l],min(r-l+1,rhs.r-rhs.l+1));
		return l+z<=r && rhs.l+z<=rhs.r?c[l+z]<c[rhs.l+z]:rhs.l+z-1<rhs.r;
	}
	void out(){for(int i=l;i<=r;++i)putchar(c[i]);putchar('\n');}
}ss[N*N/2];int sxb;
ll K,f[2][N][N];unsigned long long s1[2][N];double s2[2][N];
inline void add(int o,int l,int r,ll x){
	s1[o][l]+=x;s1[o][r]-=x;
	s2[o][l]+=x;s2[o][r]-=x;
}
int main(){
	scanf("%d%d%lld%s",&n,&m,&K,c+1);
	for(i=n;i;--i)for(j=i+1;j<=n;++j)lcp[j][i]=lcp[i][j]=c[i]==c[j]?lcp[i+1][j+1]+1:0;
	for(i=1;i<=n;++i)lcp[i][i]=n-i+1;
	for(i=1;i<=n;++i)for(j=i;j<=n;++j)ss[++sxb]=(subs){i,j};
	sort(ss+1,ss+sxb+1);reverse(ss+1,ss+sxb+1);
	int le=1,ri=sxb,mid;
	for(;le<ri;){
		mid=le+ri>>1;
		for(i=1;i<=n;++i)for(rb[i]=i;rb[i]<=n && (subs){i,rb[i]}<ss[mid];++rb[i]);
		f[0][0][0]=1;
		for(i=1;i<=m;++i){
			for(k=1;k<=n;++k)s1[0][k]=s1[1][k]=0,s2[0][k]=s2[1][k]=0;
			for(j=0;j<2;++j)for(k=0;k<n;++k){
				add(1,k+1,rb[k+1],f[j][i-1][k]);
				add(j,rb[k+1],n+1,f[j][i-1][k]);
			}
			for(j=0;j<2;++j)for(k=1;k<=n;++k){
				s1[j][k]+=s1[j][k-1],s2[j][k]+=s2[j][k-1];
				f[j][i][k]=s2[j][k]>1ll<<60?K:s1[j][k];
			}
		}
		if(f[0][m][n]>=K)ri=mid;else le=mid+1;
	}
	ss[le].out();
}