#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f|=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=300005;
int n;
int a[N];
int c[1<<20][2];
int main(){
	n=read();
	for (int i=1;i<=n;i++){
		a[i]=a[i-1]^read();
		c[a[i]][i&1]++;
	}
	c[0][0]++;
	LL ans=0;
	for (int i=0;i<(1<<20);i++)
		for (int j=0;j<2;j++){
			int v=c[i][j];
			ans+=(LL)v*(v-1)/2;
		}
	cout<<ans<<endl;
	return 0;
}