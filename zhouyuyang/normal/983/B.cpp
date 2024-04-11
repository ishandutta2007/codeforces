/*#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mo 1000000007
#define fi first
#define se second
using namespace std;
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		ll v1,v2,v3;
		scanf("%lld%lld%lld",&v1,&v2,&v3);
		if (v1==0){
			puts("Finite");
			continue;
		}
		ll tmp=gcd(v1,v2); v2/=tmp;
		tmp=gcd(v3,v2);
		for (;tmp!=1;){
			for (;v2%tmp==0;v2/=tmp);
			tmp=gcd(v2,v3);
		}
		puts(v2==1?"Finite":"Infinite");
	}
}  */
#include<bits/stdc++.h>
using namespace std;
int n,q,v[5005][5005];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&v[i][i]);
	for (int i=n-1;i;i--)
		for (int j=i+1;j<=n;j++)
			v[i][j]=v[i][j-1]^v[i+1][j];
	for (int i=n;i;i--)
		for (int j=i;j<=n;j++)
			v[i][j]=max(v[i][j],max(v[i+1][j],v[i][j-1]));
	scanf("%d",&q);
	while (q--){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",v[x][y]);
	}
}