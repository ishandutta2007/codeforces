#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,x1,y1,x2,y2,i,j;double ans,z;
	vector<pair<double,double>>ve;
	scanf("%d%d%d%d%d%d%d",&a,&b,&c,&x1,&y1,&x2,&y2);
	ans=1ll*abs(x1-x2)+abs(y1-y2);
	if(a!=0 && b!=0){
		z=(-c-1ll*a*x1)*1.0/b;
		if(min(y1,y2)<=z && z<=max(y1,y2))ve.push_back({x1,z});
		z=(-c-1ll*a*x2)*1.0/b;
		if(min(y1,y2)<=z && z<=max(y1,y2))ve.push_back({x2,z});
		z=(-c-1ll*b*y1)*1.0/a;
		if(min(x1,x2)<=z && z<=max(x1,x2))ve.push_back({z,y1});
		z=(-c-1ll*b*y2)*1.0/a;
		if(min(x1,x2)<=z && z<=max(x1,x2))ve.push_back({z,y2});
	}
	for(i=0;i<ve.size();++i)for(j=0;j<ve.size();++j)if(i!=j){
		double x3,y3,x4,y4;
		tie(x3,y3)=ve[i];tie(x4,y4)=ve[j];
		ans=min(ans,fabs(x1-x3)+fabs(y1-y3)+fabs(x4-x2)+fabs(y4-y2)+sqrt((x3-x4)*(x3-x4)+(y3-y4)*(y3-y4)));
	}
	printf("%.12f\n",ans);
	return 0;
}