#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N],k[N],b[N];
bool check(){
	for (int i=1;i<=m;i++)
		if (b[i]!=k[i])
			return 0;
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=m;i++)
		scanf("%d",&k[i]);
	for (int L=1;L<=n;L++)
		for (int R=L;R<=n;R++){
			memset(b,0,sizeof b);
			for (int i=L;i<=R;i++)
				b[a[i]]++;
			if (check()){
				puts("YES");
				return 0;
			}
		}
	puts("NO");
	return 0;
}