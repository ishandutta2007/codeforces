#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#define int64 long long
#define next nxt
using namespace std;
const int mo=5301191;
double f[mo+10];
int64 e[mo+10];
int head[mo+10],next[mo+10];
int len,a[120][4],i,j,n,h[120];
int getid(int64 hash){
	int t=hash%mo;
	if(t<0)t+=mo;
	for(int i=head[t];i;i=next[i])if(e[i]==hash)return i;
	next[++len]=head[t]; head[t]=len; e[len]=hash;
	return -1;
}
int64 gethash(int n){
	int tot=0;
	for(int i=1;i<n;++i){
		int a1=a[i][1],a2=a[i][2],a3=a[i][3];
		if(a1>a3)swap(a1,a3);
		if(!a2 || (!a1 && !a3))continue;
		h[++tot]=a1*841+a2*29+a3;
	}
	sort(h+1,h+tot+1);
	int64 hash=0;
	for(int i=1;i<=tot;++i)hash=hash*24389+h[i];
	hash=hash*24389+a[n][1]*841+a[n][2]*29+a[n][3];
	return hash;
}
double dfs(int n){
	int id=getid(gethash(n));
	if(id!=-1)return f[id];
	id=len;
	double res=1.0/6,d[4];
	d[1]=d[2]=d[3]=1e10;
	int top=n;
	if(a[top][1] && a[top][2] && a[top][3])top++;
	for(int i=1;i<n;++i){
		int cnt=(a[i][1]!=0) + (a[i][2]!=0) + (a[i][3]!=0);
		if(cnt==1)continue;
		for(int j=1;j<=3;++j)if(a[i][j]){
			int h=a[i][j];
			a[i][j]=0;
			if(cnt==2 && a[i][2]==0){
				a[i][j]=h;
				continue;
			}
			for(int k=1;k<=3;++k)if(a[top][k]==0){
				a[top][k]=h;
				d[h]=min(d[h],dfs(top));
				a[top][k]=0;
			}
			a[i][j]=h;
		}
	}
	if(d[1]<1e9)f[id]+=d[1]/3;
		else res+=1.0/3;
	if(d[2]<1e9)f[id]+=d[2]/6;
		else res+=1.0/6;
	if(d[3]<1e9)f[id]+=d[3]/3;
		else res+=1.0/3;
	if(abs(res-1.0)<1e-9)return f[id]=0;
	f[id]=(f[id]+1)/(1-res);
	return f[id];
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		char tt[5];
		scanf("%s",tt+1);
		for(j=1;j<=3;++j){
			if(tt[j]=='G')a[i][j]=1;
			if(tt[j]=='R')a[i][j]=2;
			if(tt[j]=='B')a[i][j]=3;
		}
		if(a[i][1]>a[i][3])swap(a[i][1],a[i][3]);
	}
	printf("%.6lf\n",dfs(n));
}