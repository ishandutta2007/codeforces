#include <bits/stdc++.h>
#define y1 ___y1
using namespace std;
const int N=100005;
int n,m,q,cl,ce,v,l[N],e[N];
int main(){
	scanf("%d%d%d%d%d",&n,&m,&cl,&ce,&v);
	for (int i=1;i<=cl;i++)
		scanf("%d",&l[i]);
	for (int i=1;i<=ce;i++)
		scanf("%d",&e[i]);
	sort(l+1,l+cl+1),sort(e+1,e+ce+1);
	scanf("%d",&q);
	while (q--){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if (y1<y2)
			swap(y1,y2);
		if (x1<x2)
			swap(x1,x2);
		int ans=n+m+n+m;
		int ps=lower_bound(l+1,l+cl+1,y1)-l;
		while (ps>0&&(ps>cl||l[ps]>y1))
			ps--;
		if (l[ps]>=y2)
			ans=min(ans,x1-x2+y1-y2);
		else {
			if (ps>0)
				ans=min(ans,x1-x2+y1-y2+2*(y2-l[ps]));
			ps++;
			if (ps<=cl)
				ans=min(ans,x1-x2+y1-y2+2*(l[ps]-y1));
		}
		ps=lower_bound(e+1,e+ce+1,y1)-e;
		while (ps>0&&(ps>ce||e[ps]>y1))
			ps--;
		if (e[ps]>=y2)
			ans=min(ans,y1-y2+(x1-x2-1)/v+1);
		else {
			if (ps>0)
				ans=min(ans,y1-y2+(x1-x2-1)/v+1+2*(y2-e[ps]));
			ps++;
			if (ps<=ce)
				ans=min(ans,y1-y2+(x1-x2-1)/v+1+2*(e[ps]-y1));
		}
		if (x1==x2)
			ans=min(ans,y1-y2);
		printf("%d\n",ans);
	}
	return 0;
}