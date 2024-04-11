#include <cstdio>
int T,n;
template<typename T>T max(T x,T y){return x>y?x:y;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("%d\n",max(n/3-2,0));
	}
	return 0;
}