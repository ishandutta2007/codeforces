#include <cstdio>
const int N=2e5+10;
int T,n,a[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);int type=0;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			type+=a[i]%5==0;
		}
		if(type==0){
			bool tag=true;
			for(int i=1;i<=n;++i){
				while(a[i]%10!=2)a[i]+=a[i]%10;
				a[i]%=20;
			}
			for(int i=2;i<=n;++i)tag&=a[i]==a[1];
			puts(tag?"Yes":"No");
		}
		else if(type==n){
			bool tag=true;
			for(int i=1;i<=n;++i)a[i]+=a[i]%10;
			for(int i=2;i<=n;++i)tag&=a[i]==a[1];
			puts(tag?"Yes":"No");
		}
		else puts("No");
	}
	return 0;
}