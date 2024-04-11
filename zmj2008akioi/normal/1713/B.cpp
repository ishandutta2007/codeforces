#include <cstdio>
const int N=1e5+10;
int T,n,a[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);int tp=0;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=2;i<=n;++i){
			if(tp==-1)break;
			if(a[i]>a[i-1]){if(tp)tp=-1;}
			else if(a[i]<a[i-1]){if(!tp)tp=1;}
		}
		puts((~tp)?"Yes":"No");
	}
	return 0;
}