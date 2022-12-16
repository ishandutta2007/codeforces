#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=200005,M=(int)1e9+7;
int tot,n,m,f[N];
int find(int x){
	return f[x]==x?f[x]:f[x]=find(f[x]);
}
void Union(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy)	f[fy]=fx,--tot;
}
int main(){
	scanf("%d%d",&n,&m);
	tot=n<<1;
	for(int i=0;i<=2*n+3;++i)	f[i]=i;
	while(m--){
		int i,j,k;
		char s[5];
		scanf("%d%d%s",&i,&j,s);
		k=s[0]=='o',--i,--j;
		int l=abs(i-j),r=min(i+j,2*n-2-i-j)+2;
		Union(l*2,r*2+k),Union(l*2+1,r*2+k^1);
	}
	int t=1;
	for(int i=0;i<=n+1;++i)	if(find(i*2)==find(i*2+1))	{puts("0");t=0;break;}
	if(t){
		int ans=1;
		for(int i=1;i<=tot/2;++i)	ans=ans*2%M;
		printf("%d\n",ans);
	}
	return 0;
}