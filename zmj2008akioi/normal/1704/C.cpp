#include <cstdio>
#include <algorithm>
const int N=1e5+10;
int T,n,m,tim,ans,a[N],b[N];
int max(int x,int y){return x>y?x:y;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		for(int i=1;i<=m;++i)scanf("%d",&a[i]);
		std::sort(a+1,a+m+1),a[m+1]=a[1]+n;
		for(int i=1;i<=m;++i)b[i]=a[i+1]-a[i]-1;
		std::sort(b+1,b+m+1),tim=0,ans=m;
		for(int i=m;i>=1;--i){
			if(b[i]-(tim<<1)<3){
				if(b[i]-(tim<<1)>0)ans+=b[i]-1,++tim;
				else ans+=b[i];
			}
			else ans+=(tim<<1)+1,tim+=2;
		}
		printf("%d\n",ans);
	}
	return 0;
}