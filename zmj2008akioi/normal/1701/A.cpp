#include <cstdio>
int T,n,a,b,c,d;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d %d",&a,&b,&c,&d);
		if(!a&&!b&&!c&&!d)puts("0");
		else if(a&&b&&c&&d)puts("2");
		else puts("1");
	}
	return 0;
}