#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2e6+7;
int n,m1,m2,t;
int m,x[N],y[N],lsh[N];
int f[N][2],p[N][2];
inline void upd(int i,int j,int v,int z){
	if(f[i][j]<v)f[i][j]=v,p[i][j]=z;
}
bool flg[N][2];
int main(){
	n=read(),m1=read(),m2=read(),t=read();
	for(int i=1;i<=m1;i++)x[i]=lsh[++m]=read(),lsh[++m]=x[i]+1;
	for(int i=1;i<=m2;i++)y[i]=lsh[++m]=read(),lsh[++m]=y[i]+1;
	lsh[++m]=0,lsh[++m]=n+1;
	sort(lsh+1,lsh+m+1),m=unique(lsh+1,lsh+m+1)-lsh-1;
	for(int i=1;i<=m1;i++)flg[lower_bound(lsh+1,lsh+m+1,x[i])-lsh][0]=1;
	for(int i=1;i<=m2;i++)flg[lower_bound(lsh+1,lsh+m+1,y[i])-lsh][1]=1;
	for(int i=1;i<=m;i++)f[i][0]=f[i][1]=-1e9-7;
	f[1][0]=0;
	for(int i=1;i<m;i++){
		if(!flg[i][0])upd(i,0,min(t,f[i][1]),1);
		if(!flg[i][1])upd(i,1,min(t,f[i][0]),1);
		for(int j=0;j<2;j++){
			if(!flg[i+1][j])upd(i+1,j,f[i][j]+lsh[i+1]-lsh[i],0);
			else{
				int v=f[i][j]+lsh[i+1]-lsh[i]-t;
				if(v>0)upd(i+1,j,v,0);
			}
		}
	}
	if(f[m][0]<0 && f[m][1]<0)puts("No"),exit(0);
	int X=m,Y=f[m][0]<0?1:0;
	vector<pair<int,int> >shot;
	vector<int>ans;
	while(X!=1 || Y){
		if(p[X][Y])ans.push_back(lsh[X]),Y^=1;
		else{
			if(flg[X][Y])shot.push_back({lsh[X]-f[X][Y],Y});
			X--;
		}
	}
	reverse(ans.begin(),ans.end());
	reverse(shot.begin(),shot.end());
	puts("Yes");
	printf("%lu\n",ans.size());
	for(int x:ans)printf("%d ",x);puts("");
	printf("%lu\n",shot.size());
	for(auto i:shot)printf("%d %d\n",i.first,i.second+1);
	return 0;
}