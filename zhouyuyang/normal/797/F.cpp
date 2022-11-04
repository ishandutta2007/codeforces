#include<bits/stdc++.h>
#define ll long long
#define N 5005
using namespace std;
int n,m,sum;
int a[N],q[N];
ll s[N],f[N][N];
struct jdb{int x,y;}b[N];
bool cmp(jdb a,jdb b){
	return a.x<b.x;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&b[i].x,&b[i].y);
		sum+=b[i].y;
	}
	if (sum<n)
		return puts("-1"),0;
	sort(b+1,b+m+1,cmp);
	for (int i=1;i<=n;i++)
		f[0][i]=1e18;
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++)
			s[j]=s[j-1]+abs(b[i].x-a[j]);
		int h=1,t=0;
		for (int j=0;j<=n;j++){
			if (h<=t&&q[h]<j-b[i].y) h++;
			for (;h<=t&&f[i-1][j]-s[j]<=f[i-1][q[t]]-s[q[t]];t--);
			q[++t]=j;
			f[i][j]=f[i-1][q[h]]-s[q[h]]+s[j];
		}
	}
	printf("%lld",f[m][n]);
}