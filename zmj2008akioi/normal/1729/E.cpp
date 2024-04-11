#include <cstdio>
#include <cstdlib>
const int T=25;
typedef long long LL;
LL query(int i,int j){
	printf("? %d %d\n",i,j),fflush(stdout);
	LL res;scanf("%lld",&res);return res;
}
void answer(LL x){
	printf("! %lld\n",x);
	fflush(stdout),exit(0);
}
int main(){
	for(int i=1;i<=T;++i){
		LL a=query(1,i+1),b=query(i+1,1);
		if(a==-1&&b==-1)answer(i);
		if(a!=b)answer(a+b);
	}
	answer(0);return 0;
}