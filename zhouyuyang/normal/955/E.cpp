#include<bits/stdc++.h>
#define N 100005
using namespace std;
int pre[N][20],suf[N][20],mn[N][20];
int a[N],lg[N],n,ans;
int getmn(int x,int y){
	if (x>y) return 1e9;
	int k=lg[y-x+1];
	return min(mn[x][k],mn[y-(1<<k)+1][k]); 
}
int getmn1(int x,int y){
	if (x>y) return 1e9;
	int k=lg[y-x+1];
	return min(pre[x][k],pre[y-(1<<k)+1][k]); 
}
int getmn2(int x,int y){
	if (x>y) return 1e9;
	int k=lg[y-x+1];
	return min(suf[x][k],suf[y-(1<<k)+1][k]); 
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mn[i][0]=a[i];
		pre[i][0]=a[i]-i;
		suf[i][0]=a[i]+i;
	}
	for (int i=2;i<=n;i++)
		lg[i]=lg[i>>1]+1;
	for (int j=1;j<17;j++){
		int bit=1<<(j-1);
		for (int i=1;i+(1<<j)-1<=n;i++){
			mn[i][j]=min(mn[i][j-1],mn[i+bit][j-1]);
			pre[i][j]=min(pre[i][j-1],pre[i+bit][j-1]);
			suf[i][j]=min(suf[i][j-1],suf[i+bit][j-1]);
		}
	}
	int L=1; ans=1e9;
	for (int T=1;T<=n;T++){
		for (;L<=T&&T>=2*L-a[L];L++);
		int j=-1;
		if (L<=T) j=L;
		else{
			int l=T,r=n;
			while (l<=r){
				int mid=(l+r)/2;
				if (getmn(T,mid)<T)
					j=mid,r=mid-1;
				else l=mid+1;
			}
			if (j==-1) continue;
		}
		int x,y;
		if (j<=T){
			x=getmn1(1,j-1)+T;
			y=min(getmn1(j,T)+T,getmn2(T+1,n)-T);
		}
		else{
			x=min(getmn1(1,T)+T,getmn2(T+1,j-1)-T);
			y=getmn2(j,n)-T;
		}
		ans=min(ans,max(x,y));
	}
	if (ans>1e8) puts("-1");
	else printf("%d",ans);
}