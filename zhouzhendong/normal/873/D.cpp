#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n,k,a[N];
void solve(int L,int R,int vL,int vR){
//	printf("%d %d %d %d\n",L,R,vL,vR);
	if (R-L==1){
		a[L]=vL;
		return;
	}
	int mid=(L+R)>>1;
	if (k>=2){
		k-=2;
		solve(L,mid,vR-(mid-L)+1,vR);
		solve(mid,R,vL,vL+(R-mid)-1);
	}
	else {
		for (int i=L;i<R;i++)
			a[i]=vL+i-L;
	}
}
int main(){
	scanf("%d%d",&n,&k);
	k--;
	solve(0,n,1,n);
	if (k>0)
		puts("-1");
	else
		for (int i=0;i<n;i++)
			printf("%d ",a[i]);
	return 0;
}