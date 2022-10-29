#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 47;

int a[MAX_N];

int main () {
	int n,k,m;
	scanf("%d %d %d",&n,&k,&m);
	int tot=0;
	for (int i=1;k>=i;i++) {
		scanf("%d",&a[i]);
		tot += a[i];
	}
	sort(a+1,a+k+1);
	int ans=0;
	for (int i=0;n>=i;i++) {
		if (tot*i > m) break;
		int mm=m-tot*i;
		int cnt=(k+1)*i;
		for (int j=1;k>=j;j++) {
			int tmp=min(n-i,mm/a[j]);
			cnt += tmp;
			mm -= tmp*a[j];
		}
		ans = max(ans,cnt);
	}
	printf("%d\n",ans);
}