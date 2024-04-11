#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,S=N*6;
const double pi=acos(-1);
int n,m,i,j,x[N],y[N],mn[S],ii[N][7],z,anc[20][S],dep[S];
double L=1e-7,R=2e5,M,dis[N];
pair<double,int>ev[S];int exb;
int main(){
	scanf("%d%d",&n,&m);for(i=1;i<=n;++i)scanf("%d%d",x+i,y+i),R=min(R,dis[i]=sqrt(1ll*x[i]*x[i]+1ll*y[i]*y[i]));
	for(R-=1e-7;R-L>1e-8;){
		M=(L+R)/2;exb=0;
		for(i=1;i<=n;++i){
			double a=atan2(y[i],x[i]),aa=acos(M/dis[i]);
			ev[++exb]={a-aa-pi*2,i};ev[++exb]={a+aa-pi*2,i};
			ev[++exb]={a-aa,i};ev[++exb]={a+aa,i};
			ev[++exb]={a-aa+pi*2,i};ev[++exb]={a+aa+pi*2,i};
			ii[i][0]=0;
		}
		sort(ev+1,ev+exb+1);
		for(i=1;i<=exb;++i)z=ev[i].second,ii[z][++ii[z][0]]=i;
		for(i=1;i<=exb;++i)mn[i]=exb;
		auto upi=[](int&a,int b){a>b?a=b:0;};
		for(i=1;i<=n;++i)upi(mn[ii[i][1]-1],ii[i][2]-1),upi(mn[ii[i][3]-1],ii[i][4]-1),upi(mn[ii[i][5]-1],ii[i][6]-1);
		for(i=exb-1;i;--i)upi(mn[i],mn[i+1]);
		memcpy(anc[0]+1,mn+1,exb<<2);for(i=exb-1;i;--i)dep[i]=dep[anc[0][i]]+1;
		for(i=1;i<20;++i)for(j=1;j<=exb;++j)anc[i][j]=anc[i-1][anc[i-1][j]];
		bool fl=0;
		for(i=1;i<n*6;++i)if(ev[i+1].first>-pi && ev[i+1].first<=pi){
			for(z=i,j=19;j>=0;--j)if(anc[j][z]<exb && ev[anc[j][z]].first<ev[i].first+pi*2-1e-5)z=anc[j][z];
			fl|=dep[i]-dep[z]+1<=m;
		}
		(fl?L:R)=M;
	}
	printf("%.8f\n",L);
	return 0;
}