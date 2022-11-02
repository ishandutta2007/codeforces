#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
const int N=5005;
int n;
double m,ans=1e100;
int main(){
	scanf("%d%lf",&n,&m);
	for (int i=1;i<=n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		ans=min(ans,m*a/b);
	}
	printf("%.10lf",ans);
	return 0;
}