#include<bits/stdc++.h>
using namespace std;
int n,cnt,a[2333],g,mn=1e8;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i], cnt+=a[i]==1;
	if (cnt) return 0*printf("%d",n-cnt);
	for (int i=1,j;i<=n;i++){
		g=a[i]; for (j=i+1;j<=n&&g>1;j++) g=__gcd(g,a[j]);
		if (g==1) mn=min(mn,j-i);
	}
	printf("%d",mn==(1e8)? -1: mn+n-2);
}