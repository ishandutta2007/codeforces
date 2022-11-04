#include<bits/stdc++.h>
#define N 3005
using namespace std;
int mx[N][N],at[N][N],ans[N];
int n,m1=0,m2=0,m3=0,mi,mj,mk;
struct P{int x,id;}a[N];
bool cmp(P a,P b){return a.x>b.x;}
void check(int d1,int d2,int d3,int i,int j,int k){
	if (d1<m1||(d1==m1&&d2<m2)) return;
	if (d1==m1&&d2==m2&&d3<m3) return;
	m1=d1; m2=d2; m3=d3; mi=i; mj=j; mk=k;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i].x),a[i].id=i;
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
			if (mx[i][j-1]<=a[j].x-a[j+1].x)
				mx[i][j]=a[j].x-a[j+1].x,at[i][j]=j;
			else mx[i][j]=mx[i][j-1],at[i][j]=at[i][j-1];
	for (int i=1;i<n;i++)
		for (int j=(i+1)/2;j+i<n&&2*i>=j;j++){
			int L=max((i+1)/2,(j+1)/2);
			int R=min(i*2,j*2);
			if (i+j+L>n) continue;
			if (i+j+R>n) R-=i+j+R-n;
			check(a[i].x-a[i+1].x,a[i+j].x-a[i+j+1].x,mx[i+j+L][i+j+R],i,j,at[i+j+L][i+j+R]);
		}
	for (int i=1;i<=mi;i++) ans[a[i].id]=1;
	for (int i=mi+1;i<=mi+mj;i++) ans[a[i].id]=2;
	for (int i=mi+mj+1;i<=mk;i++) ans[a[i].id]=3;
	for (int i=mk+1;i<=n;i++) ans[a[i].id]=-1;
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
}