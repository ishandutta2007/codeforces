#include<cstdio>
#include<vector>
using std::vector;
const int N=20,M=100;
int f[N],g[N];
char c[M];
int i,n,m,j;
inline int min(int a,int b){
	return a>b?b:a;
}
vector<int> v[N];
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i){
		scanf("%s",c+1);
		for(j=0;j<=m+1;++j)
			if(c[j+1]=='1')
				v[n-i+1].push_back(j);
	}
	while(v[n].size()==0 && n)--n;
	if(!n){
		puts("0");
		return 0;
	}
	if(n==1){
		printf("%d\n",v[1].back());
		return 0;
	}
	g[1]=m+1;
	if(v[1].size())f[1]=v[1].back()*2;
	for(i=2;i<n;++i)
		if(v[i].size()){
			f[i]=min(f[i-1]+1+v[i].back()*2,g[i-1]+1+m+1);
			g[i]=min(g[i-1]+1+(m+1-v[i][0])*2,f[i-1]+1+m+1);
		}else{
			f[i]=f[i-1]+1;
			g[i]=g[i-1]+1;
		}
	printf("%d\n",min(f[n-1]+v[n].back()+1,g[n-1]+1+(m+1-v[n][0])));
	return 0;
}