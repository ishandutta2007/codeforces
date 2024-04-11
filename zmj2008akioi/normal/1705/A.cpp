#include <cstdio>
#include <algorithm>
const int N=1e6+10;
int T,n,x,a[N];
bool tag;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&x),tag=true;
		for(int i=1;i<=(n<<1);++i)scanf("%d",&a[i]);
		std::sort(a+1,a+(n<<1)+1);
		for(int i=1;i<=n;++i)tag&=a[i+n]-a[i]>=x;
		puts(tag?"Yes":"No");
	}
	return 0;
}