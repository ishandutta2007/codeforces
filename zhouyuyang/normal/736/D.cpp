#include<bits/stdc++.h>
#define maxn 2010
#define maxm 500010
using namespace std;
int n,m;
int x[maxm],y[maxm];
bitset<maxn*2> A[maxn];
int main(){
    scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x[i],&y[i]);
		A[x[i]][y[i]]=1;
	}
	for(int i=1;i<=n;i++)A[i][i+n]=1;
	for(int i=1;i<=n;i++){
		int t=i;
		for(int j=i+1;j<=n;j++)if(A[j][i])t=j;
		swap(A[i],A[t]);
		for(int j=1;j<=n;j++)if(A[j][i]&&j!=i)A[j]^=A[i];
	}
	for(int i=1;i<=m;i++)if(A[y[i]][x[i]+n])puts("NO");else puts("YES");
}