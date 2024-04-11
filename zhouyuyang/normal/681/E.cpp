#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>
#include <string>
#define mod 1000000009
#define eps 1e-5
#define pi acos(-1)
using namespace std;
typedef __int64 LL;
typedef pair<double,double>pa;
int nn;
pa p[200010];int m;
int n;
int main()
{
    int x0,y0,v,T;
    scanf("%d%d%d%d",&x0,&y0,&v,&T);
    double r0=(LL)v*T;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	int aa,bb,cc;
    	scanf("%d%d%d",&aa,&bb,&cc);
    	LL dd=(LL)(x0-aa)*(x0-aa)+(LL)(y0-bb)*(y0-bb);
    	//if(d<=eps&&d>=-eps)continue;
    	if(dd<=(LL)cc*cc+eps){
    		printf("1.0000000000\n");
    		return 0;
		} 
		double d=sqrt(dd);
    	if(cc+r0<d)continue;
    	else{
    		double s;
    		if(dd<=(LL)r0*r0+(LL)cc*cc)s=asin(cc/d);
    		else s=acos((1.0*r0*r0+d*d-1.0*cc*cc)/(2.0*r0*d));
    		double ab=atan2(bb-y0,aa-x0);
    		if(ab<0)ab+=2.0*pi;
    		double ll=ab-s,rr=ab+s;
    		if(ll<0)ll+=2*pi;
    		else if(ll>2*pi)ll-=2*pi;
    		if(rr>2*pi)rr-=2*pi;
    		else if(rr<0)rr+=2*pi;
    		if(ll>rr){
    			p[++m]=make_pair(ll,2*pi);
    			p[++m]=make_pair(0,rr);
			}
			else p[++m]=make_pair(ll,rr);
		}
	}
	sort(p+1,p+1+m);
	double now=0.0,ans=0.0;
	for(int i=1;i<=m;i++){
		//printf("%lf %lf\n",p[i].first,p[i].second);
		if(p[i].first>=now){
			ans+=p[i].second-p[i].first;
			now=p[i].second;
		}
		else{
			ans+=max(0.0,p[i].second-now);
			now=max(now,p[i].second);
		}
	}
	printf("%.5lf\n",ans/(2.0*pi));
	return 0;
}