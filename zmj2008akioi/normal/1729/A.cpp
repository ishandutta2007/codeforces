#include <cstdio>
int T,a,b,c;
template<typename T>T rv(T x){return x>T()?x:-x;}
template<typename T>T min(T x,T y){return x<y?x:y;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&a,&b,&c);
		int t1=a-1,t2=rv(c-b)+c-1;
		if(t1<t2)puts("1");
		if(t1>t2)puts("2");
		if(t1==t2)puts("3");
	}
	return 0;
}