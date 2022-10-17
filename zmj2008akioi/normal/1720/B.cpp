#include <cstdio>
const int inf=2e9,N=1e6+10;
int T,n,a[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int fmn=inf,gmn=inf,fmx=0,gmx=0;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			if(a[i]>fmx)gmx=fmx,fmx=a[i];else if(a[i]>gmx)gmx=a[i];
			if(a[i]<fmn)gmn=fmn,fmn=a[i];else if(a[i]<gmn)gmn=a[i];
		}
		printf("%d\n",fmx+gmx-fmn-gmn);
	}
	return 0;
}