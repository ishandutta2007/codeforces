#include<bits/stdc++.h>
using namespace std;
int n,id[2005],x;
struct P{
	double x,y;
	P operator +(P a){
		return (P){x+a.x,y+a.y};
	}
	P operator -(P a){
		return (P){x-a.x,y-a.y};
	}
	P operator /(double a){
		return (P){x/a,y/a};
	}
	double operator *(P a){
		return x*a.x+y*a.y;
	}
	bool operator ==(P a){
		return fabs(x-a.x)<1e-9&&fabs(y-a.y)<1e-9;
	}
}p[2005],rt,mid,vec;
pair<double,int> a[2005];
bool check(int pos){
	mid=(p[x]+p[pos])/2;
	vec=rt-mid;
	vec=(P){vec.y,-vec.x};
	for (int i=1;i<=n;i++)
		a[i]=make_pair(vec*p[i],i);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
		id[a[i].second]=i;
	if (id[x]+id[pos]!=n+1) return 0;
	double flag=a[1].first+a[n].first;
	for (int i=1;i<=n;i++)
		if (abs(a[i].first+a[n-i+1].first-flag)>1e-9) return 0;
	return 1;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%lf%lf",&p[i].x,&p[i].y);
		rt=rt+p[i];
	}
	rt=rt/n;
	bool inf=1;
	for (int i=1;i<=n;i++){
		bool is=0;
		for (int j=1;j<=n;j++)
			if (p[i]+p[j]==rt+rt) is=1;
		if (!is) inf=0,x=i;
	}
	if (inf)
		return puts("-1"),0;
	int ans=0;
	for (int i=1;i<=n;i++)
		if (check(i)) ans++;
	printf("%d",ans);
}