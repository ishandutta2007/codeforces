#include <bits/stdc++.h>
using namespace std;
const int N=5005;
int n,q,f[N][N];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&f[1][i]);
	for (int i=2;i<=n;i++)
		for (int j=1;j<=n-i+1;j++)
			f[i][j]=f[i-1][j]^f[i-1][j+1];
	for (int i=2;i<=n;i++)
		for (int j=1;j<=n-i+1;j++)
			f[i][j]=max(f[i][j],f[i-1][j]);
	for (int j=n-1;j>=1;j--)
		for (int i=1;i<=n-j+1;i++)
			f[i][j]=max(f[i][j],f[i-1][j+1]);
	scanf("%d",&q);
	while (q--){
		int L,R;
		scanf("%d%d",&L,&R);
		printf("%d\n",f[R-L+1][L]);
	}
	return 0;
}