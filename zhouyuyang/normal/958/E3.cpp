#include<bits/stdc++.h>
#define N 10005
using namespace std;

struct P{
	int x,y,tp,id;
}a[N*2],c;
bool cmp1(P a,P b){
	return a.y!=b.y?a.y<b.y:a.x<b.x;
}
bool cmp2(P a,P b){
	return ((a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x))<0;
}
int n,ans[N];
void work(int l,int r){
	if (l>r) return;
	int p=min_element(a+l,a+r+1,cmp1)-a;
	swap(a[l],a[p]); c=a[l];
	sort(a+l+1,a+r+1,cmp2);
	int cnt1=0,cnt2=0,k=r;
	for (;!(c.tp!=a[k].tp&&cnt1==cnt2);){
		if (c.tp==a[k].tp) cnt1++;
		else cnt2++;
		k--;
	}
	if (c.tp) ans[a[k].id]=c.id;
	else ans[c.id]=a[k].id;
	work(l+1,k-1); work(k+1,r);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=2*n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].tp=(i>n); a[i].id=(i>n?i-n:i);
	}
	work(1,2*n);
	for (int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
}