#include <cstdio>
const int N=1e6+10;
int T,n,H,M,nh,nm,h[N],m[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&n,&H,&M);
		nh=nm=50;
		for(int i=1;i<=n;++i){
			scanf("%d %d",&h[i],&m[i]);
			h[i+n]=h[i]+24,m[i+n]=m[i];
		}
		for(int i=1;i<=(n<<1);++i){
			if(h[i]>H||(h[i]==H&&m[i]>=M)){
				if(h[i]<nh||(h[i]==nh&&m[i]<nm)){
					nh=h[i],nm=m[i];
				}
			}
		}
		nh-=H,nm-=M;
		if(nm<0)nm+=60,--nh;
		printf("%d %d\n",nh,nm);
	}
	return 0;
}