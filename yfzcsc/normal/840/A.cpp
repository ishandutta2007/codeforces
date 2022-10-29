#include<bits/stdc++.h>
#define maxn 200100
using namespace std;
int A[maxn],C[maxn],n;
pair<int,int> B[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&A[i]);
	for(int i=1;i<=n;++i)
		scanf("%d",&B[i].first),B[i].second=i;
	sort(A+1,A+n+1),sort(B+1,B+n+1);
	for(int i=n,j=1;i>=1;i--,j++)
		C[B[j].second]=A[i];
	for(int i=1;i<=n;++i)printf("%d ",C[i]);
}