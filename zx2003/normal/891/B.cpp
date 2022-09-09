#include<cstdio>
#include<algorithm>
using namespace std;
const int N=24;
int n,i,b[N];
pair<int,int>a[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i].first),a[i].second=i;std::sort(a+1,a+n+1);
	for(i=2;i<=n;++i)b[a[i].second]=a[i-1].first;
	b[a[1].second]=a[n].first;
	for(i=1;i<=n;++i)printf("%d ",b[i]);
	return 0;
}