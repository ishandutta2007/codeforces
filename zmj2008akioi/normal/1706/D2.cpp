#include <cstdio>
#include <vector>
const int inf=1e9,N=1e5+10;
int T,n,k,mx,ans,a[N],buf[N];
template<typename T>void cmin(T &x,T y){if(x>y)x=y;}
template<typename T>void cmax(T &x,T y){if(x<y)x=y;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&k),ans=inf;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			if(a[i]<a[1])a[1]^=a[i]^=a[1]^=a[i];
		}
		for(int p=1;p<=a[1];p=(a[1]/(a[1]/p))+1){
			if(p>k)break;int det=a[1]/p;mx=det;
			for(int j=2;j<=n;++j){
				int c=a[j]/det;
				if(c>=k){
					if(a[j]/k>det)cmax(mx,a[j]/k);
					else buf[a[j]/k]=inf;
					continue;
				}
				int d=c+1;
				cmax(buf[a[j]/d],a[j]/c);
			}
			for(int j=1;j<=det;++j){
				cmin(ans,mx-j);
				if(buf[j]==inf)break;
				else cmax(mx,buf[j]);
			}
			for(int j=1;j<=det;++j)buf[j]=0;
		}
		printf("%d\n",ans);
	}
	return 0;
}