#include<bits/stdc++.h>
using namespace std;
const int N=305;
int n,k,y[N][N],i,j;
double ans[N];
int st1[N],st2[N],w;
inline void pushy(int y1,int y2){
	while(w>1 && (st1[w]-y1)*(st2[w]-st2[w-1])<=(st1[w-1]-st1[w])*(y2-st2[w]))
		--w;
	st1[++w]=y1;st2[w]=y2;
}
inline void add(int y1,int y2){
	if(!w){w=1;st1[1]=y1,st2[1]=y2;return;}
	int i;
	for(i=1;i<=w;++i)if(st1[i]>=y1 && st2[i]>=y2)return;
	static int s1[N],s2[N];int ow=w;
	memcpy(s1+1,st1+1,w<<2);memcpy(s2+1,st2+1,w<<2);
	bool fl=0;w=0;
	for(i=1;i<=ow;++i){
		if(s1[i]<=y1 && s2[i]<=y2)continue;
		if(s1[i]>y1)pushy(s1[i],s2[i]);
			else if(!fl)pushy(y1,y2),fl=1,--i;else pushy(s1[i],s2[i]);
	}
	if(!fl)pushy(y1,y2);
}
inline double getarea(){
	double ans=(st1[1]+st2[1])/2.0;
	for(int i=2;i<=w;++i){
		int d1=st1[i-1]-st1[i],d2=st2[i]-st2[i-1];
		ans+=d2*1.0/(d1+d2)*d2/2.0;
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;++i)for(j=0;j<=k;++j)scanf("%d",y[i]+j);
	for(i=0;i<k;++i){
		w=0;
		for(j=1;j<=n;++j){
			add(y[j][i],y[j][i+1]);
			ans[j]+=getarea();
		}
	}
	for(i=n;i;--i)ans[i]-=ans[i-1];
	for(i=1;i<=n;++i)printf("%.6f\n",ans[i]);
	return 0;
}