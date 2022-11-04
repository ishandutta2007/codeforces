#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
typedef long long LL;
int n,L,R,f[2][N],p,q,ans,s;
struct Data{
	int a,b;
}A[N];
bool operator < (Data a,Data b){
	return a.b<b.b || a.b==b.b && a.a>b.a;
}
int main(){
	scanf("%d%d%d",&n,&L,&R);
	for (int i=0;i<n;i++) scanf("%d",&A[i].a);
	for (int i=0;i<n;i++) scanf("%d",&A[i].b);
	sort(A,A+n);
	for (int i=0;i<n;i++) s+=A[i].a;
	memset(f,255,sizeof(f));
	p=0; q=1; f[0][0]=0;
	for (int i=0,j=0;i<n;p^=1,q^=1,j+=A[i++].a){
		for (int l=0;l<=j;l++) if (f[p][l]>=0){
			int r=s-j+l;
			f[q][l]=max(f[q][l],f[p][l]+A[i].b*(L<=r-A[i].a && r-A[i].a<=R));
			f[q][l+A[i].a]=max(f[q][l+A[i].a],f[p][l]+A[i].b*(L<=l && l<=R));
		}
	}
	for (int i=0;i<=s;i++) ans=max(ans,f[p][i]);
	printf("%d\n",ans);
	return 0;
}