#include <cstdio>
int t,k,p,r,cnt,unprimes[1010];
char str[10010];
inline bool prime(int x){
	for(register int i=2;i<x;++i)if(x%i==0)return false;
	return true;
}
int main(){
	scanf("%d",&t);
	unprimes[++cnt]=1;
	for(register int i=2;i<=1000;++i)if(!prime(i))unprimes[++cnt]=i;
	for(register int i=0;i<t;++i){
		scanf("%d",&k);
		scanf("%s",str);
		for(register int j=1;j<=cnt;++j){
			r=0,p=unprimes[j];
			for(register int q=k-1;~q;--q)if(str[q]-'0'==p%10)p/=10,++r;
			if(!p){
				printf("%d\n%d\n",r,unprimes[j]);
				break;
			}
		}
	}
	return 0;
}