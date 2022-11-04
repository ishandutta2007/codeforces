#include<bits/stdc++.h>
#define mo 1000000007
#define ll long long
#define N 1005
using namespace std;
int n,m,b[N][N],ans,c[N];
ll a[N];
char s[N];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%s",s+1);
		for (int j=1;j<=n;j++)
			a[j]=a[j]*2|(s[j]=='1');
	}
	sort(a+1,a+n+1);
	b[0][0]=1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=i;j++){
			b[i][j]=(b[i-1][j-1]+1ll*b[i-1][j]*j)%mo;
			c[i]=(c[i]+b[i][j])%mo;
		}
	}
	int now=0,ans=1;
	for (int i=1;i<=n;i++){
		now++;
		if (i==n||a[i]!=a[i+1]){
			ans=1ll*ans*c[now]%mo;
			now=0;
		}
	}
	printf("%d\n",ans);
}