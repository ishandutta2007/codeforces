#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
#define mo 1000000007
using namespace std;
int n,f[205][205];
struct LZH{
	int x,y;
	ll operator *(const LZH& c)const{
		return 1ll*x*c.y-1ll*y*c.x;
	}
	LZH operator -(const LZH& c)const{
		return (LZH){x-c.x,y-c.y};
	}
}a[205];
int LZHAK(int l,int r){
	if (f[l][r]!=-1) return f[l][r];
	if (r-l==1) return f[l][r]=1;
	f[l][r]=0;
	for (int i=l+1;i<r;i++)
		if ((a[l]-a[r])*(a[i]-a[r])>0)
			f[l][r]=(f[l][r]+1ll*LZHAK(l,i)*LZHAK(i,r))%mo;
	return f[l][r];
}
int main(){
	memset(f,-1,sizeof(f));
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	ll tmp=0;
	a[n]=a[0];
	for (int i=0;i<n;i++)	
		tmp+=a[i]*a[i+1];
	if (tmp<0) reverse(a,a+n);
	printf("%d",LZHAK(0,n-1));
}