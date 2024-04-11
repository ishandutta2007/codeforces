#include <cstdio>
int T,a,b,c,d;
long long v1,v2;
template<typename T>void swp(T &x,T &y){T z=x;x=y;y=z;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d %d",&a,&b,&c,&d);
		v1=1ll*a*d,v2=1ll*b*c;if(v1<v2)swp(v1,v2);
		if(v1==v2)puts("0");else if(v2==0||v1%v2==0)puts("1");else puts("2");
	}
	return 0;
}