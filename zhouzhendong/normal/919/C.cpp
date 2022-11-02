#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int N=2005;
int n,m,k;
char g[N][N];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++)
		scanf("%s",g[i]+1);
	int ans=0;
	for (int i=1;i<=n;i++){
		int cnt=0;
		for (int j=1;j<=m;j++){
			if (g[i][j]=='.')
				cnt++;
			else
				cnt=0;
			if (cnt>=k)
				ans++;
		}
	}
	for (int i=1;i<=m;i++){
		int cnt=0;
		for (int j=1;j<=n;j++){
			if (g[j][i]=='.')
				cnt++;
			else
				cnt=0;
			if (cnt>=k)
				ans++;
		}
	}
	if (k==1)
		ans/=2;
	printf("%d",ans);
	return 0;
}