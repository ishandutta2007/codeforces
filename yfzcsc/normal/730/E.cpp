#include<bits/stdc++.h>
#define maxn 200
using namespace std;
struct st{
	int u,scr,chan,fl;
	st(){}
	st(int u,int scr,int chan,int fl):
		u(u),scr(scr),chan(chan),fl(fl){}
	int operator<(const st& s)const{
		if(scr!=s.scr)return scr<s.scr;
		return u>s.u;
	}
}x[maxn];
int ans=0;
int main(){
	int n;scanf("%d",&n);
	int a,d;
	for(int i=1;i<=n;++i){
		scanf("%d%d",&a,&d);
		x[i]=(st(i,a,d,0));
	}
	sort(x+1,x+n+1);
	while(true){
		int y=0,mxy=0,z=0;
		for(int j=1;j<=n;++j)
			if(x[j].chan>0&&x[j].fl==0){
				y=j;mxy=x[j].u;break;
			}
		if(!y)break;
		x[y].scr+=x[y].chan,x[y].fl=1;
		sort(x+1,x+n+1);
		for(int j=1;j<=n;++j)
			if(x[j].u==mxy){
				z=j;break;
			}
		ans+=abs(y-z);
	//	printf("[%d,%d]",y,z);
	}
	while(true){
		int y=0,mxy=0,z=0;
		for(int j=n;j>=1;--j)
			if(x[j].chan<0&&x[j].fl==0){
				y=j;mxy=x[j].u;break;
			}
		if(!y)break;
		x[y].scr+=x[y].chan,x[y].fl=1;
		sort(x+1,x+n+1);
		for(int j=1;j<=n;++j)
			if(x[j].u==mxy){
				z=j;break;
			}
		ans+=abs(y-z);
	//	printf("[%d,%d]",y,z);
	}
	printf("%d",ans);
}