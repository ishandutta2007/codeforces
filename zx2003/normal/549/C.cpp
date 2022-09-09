#include<cstdio>
#include<cstdlib>
int n,i,z,x,y,k,j,l,u,v;
inline void out(int x){
	puts(x?"Stannis":"Daenerys");
	exit(0);
}
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;++i){
		scanf("%d",&z);
		z&1?++y:++x;
	}
	if(n==k)out(y&1);   
    if((n-k)&1){
        if(k&1){
			if((n-k)>>1>=y)out(0);
		}else if((n-k)>>1>=x || (n-k)>>1>=y)out(0);
        out(1);
    }else{
    	if(k&1 && (n-k)>>1>=x)out(1);
    	out(0);
    }
}