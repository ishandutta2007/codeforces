#include <bits/stdc++.h>
using namespace std;
const int N=2005,M=205;
typedef long long LL;
LL p=1000000007,add=998244353,add2=973586311;
int n,m;
LL hha[N],hhb[N],ha[N],hb[N];
char a[N][N],b[N][N];
map <LL,int> mp;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%s",a[i]+1);
	for (int i=1;i<=m;i++)
		scanf("%s",b[i]+1);
	for (int i=1;i<=n;i++){
		hha[i]=hhb[i]=0;
		for (int j=1;j<=m;j++){
			hha[i]=(hha[i]*add+a[i][j])%p;
			hhb[i]=(hhb[i]*add2+b[j][i])%p;
		}
	}
	mp.clear();
	for (int k=1;k<=n-m+1;k++){
		ha[k]=hb[k]=0;
		for (int i=1;i<=m;i++){
			ha[k]=(ha[k]*add2+hha[k+i-1])%p;
			hb[k]=(hb[k]*add+hhb[k+i-1])%p;
			mp[ha[k]]=k;
		}
	}
	for (int i=1;i<=n-m+1;i++)
		if (mp[hb[i]]!=0){
			printf("%d %d\n",mp[hb[i]],i);
			return 0;
		}
	return 0;
}