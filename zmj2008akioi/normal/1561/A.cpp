#include <cstdio>
int t,n,p,arr[1010];
inline void swap(int &x,int &y){
	x^=y^=x^=y;
}
inline bool check(){
	for(register int i=1;i<n;++i)if(arr[i+1]<arr[i])return false;
	return true;
}
int main(){
	scanf("%d",&t);
	for(register int i=0;i<t;++i){
		scanf("%d",&n);
		p=0;
		for(register int i=1;i<=n;++i)scanf("%d",&arr[i]);
		while(!check()){
			++p;
			if(p%2==1){
				for(register int i=1;i<=n-2;i+=2)if(arr[i+1]<arr[i])swap(arr[i+1],arr[i]);
			}
			else{
				for(register int i=2;i<=n-1;i+=2)if(arr[i+1]<arr[i])swap(arr[i+1],arr[i]);
			}
		}
		printf("%d\n",p);
	}
	return 0;
}