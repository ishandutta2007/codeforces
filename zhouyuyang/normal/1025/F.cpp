#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
struct P{
	int x,y,id;
	double ang;
	bool operator <(const P &a)const{
		return ang<a.ang;
	}
}p[2005],o;
int n,bl[2005];
int cnt[2],tmp[2];
long long ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&p[i].x,&p[i].y),p[i].id=i;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)
			if (p[j].id==i){
				o=p[j]; break;
			}
		for (int j=1;j<=n;j++)
			if (p[j].id==i) p[j].ang=1e9;
			else{
				p[j].ang=atan2(p[j].y-o.y,p[j].x-o.x);
				if (p[j].ang<=0) p[j].ang+=pi;
			}
		sort(p+1,p+n+1);
		cnt[0]=cnt[1]=0;
		for (int j=1;j<n;j++)
			if (p[j].y<o.y||(p[j].y==o.y&&p[j].x>o.x))
				cnt[bl[j]=0]++;
			else cnt[bl[j]=1]++;
		tmp[0]=cnt[0]*(cnt[0]-1)/2;
		tmp[1]=cnt[1]*(cnt[1]-1)/2;
		for (int j=1;j<n;j++){
			tmp[bl[j]]-=--cnt[bl[j]];
			ans+=1ll*tmp[0]*tmp[1]; bl[j]^=1;
			tmp[bl[j]]+=cnt[bl[j]]++;
		}
	}
	printf("%lld",ans/2);
}