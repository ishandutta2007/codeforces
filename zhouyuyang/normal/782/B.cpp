#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm> 
#define M 5005
using namespace std;
struct data{int x,y;}a[100005];
int n;
double l,r,mid,le,ri;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i].x);
	for (int i=1;i<=n;i++) scanf("%d",&a[i].y);
	l=0; r=1e9;
	while (r-l>1e-10){
		mid=(l+r)/2;
		le=-1e20,ri=1e20;
		for (int i=1;i<=n;i++){
			le=max(le,a[i].x-a[i].y*mid);
			ri=min(ri,a[i].x+a[i].y*mid);
		}
		if (ri-le>-1e-7) r=mid; else l=mid;
	}
	printf("%.10lf",l);
}