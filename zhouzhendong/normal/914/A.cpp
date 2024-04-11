#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
int n,a,ans;
bool check(int x){
	if (x<0)
		return 0;
	int y=(int)sqrt(x);
	return y*y==x;
}
int main(){
	scanf("%d",&n);
	int ans=-10000000;
	while (n--){
		scanf("%d",&a);
		if (!check(a))
			ans=max(ans,a);
	}
	printf("%d",ans);
	return 0;
}