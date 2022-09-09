#include<cstdio>
#include<cstring>
#include<set>
std::set<char> sc;
const int N=5005,mo=1000000007;
int s[N],i,j,k,n,m,C[N][N],ans,f[N][26],x;
char c[N],b[N];
int main(){
	scanf("%d%s",&n,c+1);
	for(i=1;i<=n;++i){
		sc.insert(c[i]);
		if(c[i]!=c[i-1])b[++m]=c[i];
	}ans=sc.size();
	for(i=**C=1;i<=n;++i)
		for(j=*C[i]=1;j<=i;++j)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
	s[0]=1;
	for(i=1;i<=m;++i){x=b[i]-'a';
		for(j=i;j>1;--j){
			k=(s[j-1]-f[j-1][x]-f[j][x]+1ll*mo+mo)%mo;
			f[j][x]=(f[j][x]+k)%mo;
			s[j]=(s[j]+k)%mo;
			ans=(ans+1ll*k*C[n-1][j-1])%mo;
			//printf("%d\n",ans);
		}
		if(!f[1][x])f[1][x]=1,++s[1];
	}
	printf("%d\n",ans);
	return 0;
}