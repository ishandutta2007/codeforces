#include <cstdio>
#include <cstring>
const int inf=1e9,N=510,P=1e9+7;
int T,n,m,c,l[N],r[N],L[N],R[N],f[N][N];
char s[N],t[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s %s",s+1,t+1);
		c=0,n=strlen(s+1),m=strlen(t+1);
		for(int i=1;i<=n-m+1;++i){
			bool tag=true;
			for(int j=0;j<m;++j)tag&=s[i+j]==t[j+1];
			if(tag)l[++c]=i,r[c]=i+m-1;
		}
		r[c+1]=l[c+1]=inf;
		for(int i=1;i<=c;++i){
			R[i]=R[i-1];
			while(r[i]>=l[R[i]+1])++R[i];
		}
		L[c+1]=c+1;
		for(int i=c;i;--i){
			L[i]=L[i+1];
			while(l[i]<=r[L[i]-1])--L[i];
		}
		int ans=0,p=1;
		while(p<=c)++ans,p=R[R[p]]+1;
		printf("%d ",ans),f[0][0]=1;
		for(int i=1;i<=c;++i){
			memset(f[i],0,sizeof(f[i]));
			for(int j=0;j<i;++j){
				if(L[i]-R[j]>1||l[i]<=r[j])continue;
				for(int k=1;k<=i;++k)f[i][k]=(f[i][k]+f[j][k-1])%P;
			}
		}
		int fans=0;
		for(int i=0;i<=c;++i)if(R[i]==c)fans=(fans+f[i][ans])%P;
		printf("%d\n",fans);
	}
	return 0;
}