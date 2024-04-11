#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200005;
int a[N],b[N],x,n,i;
pair<int,int> c[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<=n;++i){
		scanf("%d",&x);
		c[i]=make_pair(x,i);
	}
	sort(c+1,c+n+1);
	sort(a+1,a+n+1);
	for(i=1;i<=n;++i)b[c[i].second]=a[n-i+1];
	for(i=1;i<=n;++i)printf("%d ",b[i]);
	return 0;
}