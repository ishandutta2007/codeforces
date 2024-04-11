#include<stdio.h>
#include<memory.h>
int p[200002],c[200002],n,a[200002],m,t,mk[200002];
bool check(int p){
	for(int i=1;i<=p;i++){
		bool f=1;
		for(int j=i+p;j<=m;j+=p)if(a[j]!=a[j-p])f=0;
		if(f)return 1;
	}return 0;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);int ans=1e9;
		memset(mk,0,sizeof(mk));
		for(int i=1;i<=n;i++)scanf("%d",&p[i]);
		for(int i=1;i<=n;i++)scanf("%d",&c[i]);
		for(int i=1;i<=n;i++)if(!mk[i]){
			m=0;
			for(int j=i;!mk[j];j=p[j])mk[j]=1,a[++m]=c[j];
			for(int i=1;i*i<=m;i++)if(m%i==0){
				if(check(i)&&i<ans)ans=i;
				if(i*i!=m&&m/i<ans&&check(m/i))ans=m/i;
			}
		}printf("%d\n",ans);
	}
}