#include<bits/stdc++.h>
#define N 5005
using namespace std;
int a[N],x[N][12],y[N][12];
int n,b,sa;
int min(int x,int y){
	return x<y?x:y;
}
int fldiv(int x,int y){
	return (x<0?x-y+1:x)/y;
}
int getp(int X,int Y){
	if (Y<x[X][11]||Y<0)
		return y[X][0];
	int d=1;
	for (;x[X][d]>Y;d++);
	return y[X][d]+fldiv(Y-x[X][d],d);
}
int DP(int x,int y){
	int ans=1e9;
	for (int i=0;i<=y&&i*2<=a[x];i++)
		ans=min(ans,getp(x+1,y-i+(a[x]-i)/10)-(a[x]-i)/10);
	return ans;
}
int main(){
	scanf("%d%d",&n,&b);
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]),sa+=a[i];
	for (int i=n-1;i>=0;i--){
		y[i][0]=DP(i,0);
		int l=0,r=100000000;
		while (l<r){
			int mid=(l+r)/2;
			if (DP(i,mid)>y[i][0])
				r=mid;
			else l=mid+1;
		}
		x[i][11]=l-11;
		y[i][11]=y[i][0];
		for (int j=10;j;j--){
			int stx=x[i][j+1],sty=y[i][j+1];
			int l=0,r=(1e9-stx)/(j+1);
			while (l<r){
				int mid=(l+r+1)/2;
				if (DP(i,stx+mid*(j+1)-1)==sty+mid-1)
					l=mid;
				else r=mid-1; 
			}
			x[i][j]=stx+l*(j+1);
			y[i][j]=y[i][j+1]+l;
		}
	}
	printf("%d\n",sa+getp(0,b)-b);
	for (int i=0,j=b,r;i<n;j=j-r+(a[i++]-r)/10){
		r=0; int now=getp(i,j);
		for (;now!=getp(i+1,j-r+(a[i]-r)/10)-(a[i]-r)/10;) r++;
		printf("%d ",r);
	}
}