#include<bits/stdc++.h>
#define N 100005
using namespace std;
char s[N];
int n,m,b[N],c[2][N];
pair<int,int> f[N];
int main(){
	scanf("%d%s%d",&n,s+1,&m);
	for (int i=1;i<=n;i++){
		b[i]=b[i-1]+(s[i]=='?');
		if (s[i]!='a') c[0][i]=c[1][i-1]+1;
		if (s[i]!='b') c[1][i]=c[0][i-1]+1;
		if (c[m&1][i]>=m) f[i]=make_pair(f[i-m].first+1,f[i-m].second-b[i]+b[i-m]);
		f[i]=max(f[i],f[i-1]);
	}
	printf("%d\n",-f[n].second);
}