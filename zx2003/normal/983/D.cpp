#include<bits/stdc++.h>
using namespace std;
namespace W{
inline int max(const int&a,const int&b){return a>b?a:b;}
inline int min(const int&a,const int&b){return a<b?a:b;}
char ibuf[1<<25],*ih=ibuf;
inline void read(int&x){
	int f=1;
	for(;!isdigit(*ih);++ih)if(*ih=='-')f=-1;
	for(x=0;isdigit(*ih);x=x*10+*ih++-48);x*=f;
}
const int N=400005;
int xa[N],xcnt,ya[N*2],ycnt;
int n,x1[N],y1[N],x2[N],y2[N],i;
int ans;
struct eve{
	int x,v,id;
	bool operator<(const eve&rhs)const{return x<rhs.x;}
}ev[N];
int xb;
bool vi[N];
int mx[N<<3],mn[N<<3];
set<int>t[N<<2];
inline void maintain(int i){
	mn[i]=min(mn[i<<1],mn[i<<1|1]);
	mx[i]=max(mx[i<<1],mx[i<<1|1]);
	if(!t[i].empty()){
		if(mx[i]<*t[i].rbegin())mx[i]=vi[*t[i].rbegin()]?0:*t[i].rbegin();
		if(*t[i].rbegin()>mn[i])mn[i]=*t[i].rbegin();
	}
	if(mx[i]<mn[i])mx[i]=0;
}
void ins(int i,int l,int r,int x,int y,int v){
	if(l==x && r==y){
		t[i].insert(v);
		maintain(i);
		return;
	}
	int m=(l+r)>>1;
	if(x>m)ins(i<<1|1,m+1,r,x,y,v);
		else if(y<=m)ins(i<<1,l,m,x,y,v);
				else ins(i<<1,l,m,x,m,v),ins(i<<1|1,m+1,r,m+1,y,v);
	maintain(i);
}
void del(int i,int l,int r,int x,int y,int v){
	if(l==x && r==y){
		t[i].erase(v);
		return maintain(i);
	}
	int m=(l+r)>>1;
	if(x>m)del(i<<1|1,m+1,r,x,y,v);
		else if(y<=m)del(i<<1,l,m,x,y,v);
				else del(i<<1,l,m,x,m,v),del(i<<1|1,m+1,r,m+1,y,v);
	maintain(i);
}
void remaintain(int i,int l,int r,int x,int y){
	if(l==x && r==y)return maintain(i);
	int m=(l+r)>>1;
	if(x>m)remaintain(i<<1|1,m+1,r,x,y);
		else if(y<=m)remaintain(i<<1,l,m,x,y);
				else remaintain(i<<1,l,m,x,m),remaintain(i<<1|1,m+1,r,m+1,y);
	maintain(i);
}
int main(){
	fread(ibuf,1,1<<25,stdin);
	read(n);
	for(i=1;i<=n;++i){
		read(x1[i]);read(y1[i]);read(x2[i]);read(y2[i]);
		--x2[i];--y2[i];
		xa[++xcnt]=x1[i];xa[++xcnt]=x2[i];
		ya[++ycnt]=y1[i];ya[++ycnt]=y2[i];
		ya[++ycnt]=y1[i]-1;
		ya[++ycnt]=y2[i]+1;
		xa[++xcnt]=x2[i]+1;
	}
	sort(xa+1,xa+xcnt+1);
	xcnt=unique(xa+1,xa+xcnt+1)-xa-1;
	sort(ya+1,ya+ycnt+1);
	ycnt=unique(ya+1,ya+ycnt+1)-ya-1;
	for(i=1;i<=n;++i){
		x1[i]=lower_bound(xa+1,xa+xcnt+1,x1[i])-xa;
		x2[i]=lower_bound(xa+1,xa+xcnt+1,x2[i])-xa;
		y1[i]=lower_bound(ya+1,ya+ycnt+1,y1[i])-ya;
		y2[i]=lower_bound(ya+1,ya+ycnt+1,y2[i])-ya;
		ev[++xb]=(eve){x1[i],1,i};
		ev[++xb]=(eve){x2[i]+1,-1,i};
	}
	sort(ev+1,ev+xb+1);
	for(i=1;i<=xb;++i){
		for(;;){
			if(ev[i].v==1)ins(1,1,ycnt,y1[ev[i].id],y2[ev[i].id],ev[i].id);
				else del(1,1,ycnt,y1[ev[i].id],y2[ev[i].id],ev[i].id);
			if(i==xb || ev[i].x!=ev[i+1].x)break;
			++i;
		}
		for(;mx[1];){
			++ans;vi[mx[1]]=1;
			remaintain(1,1,ycnt,y1[mx[1]],y2[mx[1]]);
		}
	}
	printf("%d\n",ans+1);
	return 0;
}
}
int main(){
	return W::main();
}