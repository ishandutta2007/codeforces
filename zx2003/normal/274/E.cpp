#include<cstdio>
#include<ctime>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int f1[4]={-1,-1,1,1},f2[4]={-1,1,1,-1},mo=999983,M=100005;
typedef long long ll;
int n,m,k,x,y,d,u,v,i,j;
char c[5];
bool flag,bbb;
ll ans;
vector<int> v1[M*3],v2[M*3];
struct hash1{
	int h[mo],xb;
	struct node{
		int x,y,next;
	}a[M];
	inline void clear(){
		memset(h,xb=0,sizeof h);
	}
	void ins(int x,int y){
		int u=(1ll*x*n-n+y)%mo;
		a[++xb]=(node){x,y,h[u]};
		h[u]=xb;
	}
	bool find(int x,int y){
		if(!x || x>n || !y || y>m)return 1;
		for(int u=(1ll*x*n-n+y)%mo,i=h[u];i;i=a[i].next)if(a[i].x==x && a[i].y==y)return 1;
		return 0;
	}
}h1;
inline int abs(int x){
	return x>0?x:-x;
}
inline ll solve(int a,int b,int d){
	ll ans=0;
	for(;;){
		//printf("%d %d\n",a,b);
		//if(clock()>900)return 0;
		if(d&1){
			if(d&2)u=*upper_bound(v1[a+b].begin(),v1[a+b].end(),a);
				else u=*(lower_bound(v1[a+b].begin(),v1[a+b].end(),a)-1);
			v=a+b-u;
		}else{
			if(d&2)u=*upper_bound(v2[M+a-b].begin(),v2[M+a-b].end(),a);
				else u=*(lower_bound(v2[M+a-b].begin(),v2[M+a-b].end(),a)-1);
			v=u-a+b;
		}
		if(((d&1 && a+b==x+y) || (!(d&1) && a-b==x-y)) && bbb && (u-x)*(x-a)>=0)
			return flag=1,ans+abs(x-a);
		ans+=abs(u-a);
		bool b1=h1.find(u-f1[d],v),b2=h1.find(u,v-f2[d]);
		if(b1==b2)return ans;
			else if(b1)a=u,b=v-f2[d],d^=1;
					else a=u-f1[d],b=v,d=3-d;
		bbb=1;
	}	
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(i=0;i<=n+1;++i){
		v1[i].push_back(i);
		v1[i+m+1].push_back(i);
		v2[i+M].push_back(i);
		v2[i+M-m-1].push_back(i);
	}
	for(i=0;i<=m+1;++i){
		v1[i].push_back(0);
		v1[i+n+1].push_back(n+1);
		v2[M-i].push_back(0);
		v2[M+n+1-i].push_back(n+1);
	}
	for(i=1;i<=k;++i){
		scanf("%d%d",&x,&y);
		h1.ins(x,y);
		v1[x+y].push_back(x);
		v2[M+x-y].push_back(x);
	}
	for(i=0;i<M*3;++i){
		if(!v1[i].empty())sort(v1[i].begin(),v1[i].end());
		if(!v2[i].empty())sort(v2[i].begin(),v2[i].end());
	}
	scanf("%d%d%s",&x,&y,c);
	if(*c=='N')d=c[1]=='W'?0:1;
		else d=c[1]=='W'?3:2;
	ans=solve(x,y,d);
	if(!flag)bbb=0,ans+=solve(x,y,(d+2)&3)-1;
	cout<<ans<<endl;
	return 0;
}