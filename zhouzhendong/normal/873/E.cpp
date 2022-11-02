#include <bits/stdc++.h>
using namespace std;
const int N=3005;
int n,ST[N][14];
struct pb{
	int a,id,res;
}a[N];
bool cmpa(pb a,pb b){
	return a.a>b.a;
}
bool cmpid(pb a,pb b){
	return a.id<b.id;
}
int calc(int i){
	return a[i].a-a[i+1].a;
}
int Query(int L,int R){
	if (L>R)
		return -1;
	int d=log(R-L+1)/log(2.0);
	int a=ST[L+(1<<d)-1][d],b=ST[R][d];
	return calc(a)>calc(b)?a:b;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),a[i].id=i;
	sort(a+1,a+n+1,cmpa);
	a[n+1].a=0;
	for (int i=1;i<=n;i++){
		ST[i][0]=i;
		for (int j=1;j<=12;j++){
			ST[i][j]=ST[i][j-1];
			if (i-(1<<(j-1))>0&&calc(ST[i-(1<<(j-1))][j-1])>calc(ST[i][j]))
				ST[i][j]=ST[i-(1<<(j-1))][j-1];
		}
	}
	int d1=-1,d2=-1,d3=-1;
	for (int i=1;i<=n;i++)
		for (int j=1;i+j<=n;j++){
			if (i>2*j||j>2*i)
				continue;
			int dd1=i,dd2=i+j,dd3=Query(dd2+max((i+1)/2,(j+1)/2),min(dd2+min(i*2,j*2),n));
			int k=dd3-dd2;
			if (dd3==-1||k<1)
				continue;
			if (d1==-1||calc(dd1)>calc(d1)||(calc(dd1)==calc(d1)&&(calc(dd2)>calc(d2)||(calc(dd2)==calc(d2)&&calc(dd3)>calc(d3)))))
				d1=dd1,d2=dd2,d3=dd3;
		}
	for (int i=1;i<=d1;i++)
		a[i].res=1;
	for (int i=d1+1;i<=d2;i++)
		a[i].res=2;
	for (int i=d2+1;i<=d3;i++)
		a[i].res=3;
	for (int i=d3+1;i<=n;i++)
		a[i].res=-1;
	sort(a+1,a+n+1,cmpid);
	for (int i=1;i<=n;i++)
		printf("%d ",a[i].res);
	return 0;
}