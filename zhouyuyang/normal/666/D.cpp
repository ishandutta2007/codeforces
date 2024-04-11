#include<bits/stdc++.h>
#define bas 47
#define N 200005
#define ll long long
using namespace std;
struct P{int x,y,id;}X[5],Y[5],Xx[5],Yy[5],st[5],a[5],Ans[5],tmp[5];
int ans,T,rev,visx[5],visy[5];
void work(int x,int xcnt,int ycnt,int v){
	//printf("233333333333 %d %d %d %d\n",x,xcnt,ycnt,v);
	if (x==5){
		if (ans<=v) return;
		ans=v;
		for (int i=1;i<=4;i++){
			Ans[i]=tmp[i];
			if (rev) swap(Ans[i].x,Ans[i].y);
		}
		return;
	}
	for (int i=1;i<=xcnt;i++)
		if (st[x].x==X[i].x&&!visx[i]){
			visx[i]=1; tmp[X[i].id]=st[x];
			work(x+1,xcnt,ycnt,max(v,abs(st[x].y-X[i].y)));
			visx[i]=0;
		}
	for (int i=1;i<=ycnt;i++)
		if (st[x].y==Y[i].y&&!visy[i]){
			visy[i]=1; tmp[Y[i].id]=st[x];
			work(x+1,xcnt,ycnt,max(v,abs(st[x].x-Y[i].x)));
			visy[i]=0;
		}
}
void work04(){
	for (int i=1;i<=3;i++)
		for (int j=i+1;j<=4;j++)
			if (X[i].x>X[j].x)
				swap(X[i],X[j]);
	if (X[1].x!=X[2].x||X[2].x==X[3].x||X[3].x!=X[4].x)
		return;
	int d=abs(X[2].x-X[3].x);
	if (X[1].y<X[2].y) swap(X[1],X[2]);
	if (X[3].y<X[4].y) swap(X[3],X[4]);
	X[2].y+=d; X[4].y+=d;
	int x1=X[1].id,x2=X[3].id;
	for (int i=1;i<=3;i++)
		for (int j=i+1;j<=4;j++)
			if (X[i].y>X[j].y)
				swap(X[i],X[j]);
	int tmp=(X[4].y-X[1].y+1)/2;
	int pos=X[4].y-tmp;
	if (tmp>=ans) return;
	ans=tmp;
	for (int i=1;i<=4;i++){
		Ans[X[i].id].x=X[i].x;
		Ans[X[i].id].y=(X[i].id==x1||X[i].id==x2)?pos:pos-d;
		if (rev) swap(Ans[X[i].id].x,Ans[X[i].id].y);
	}
}
void work13(){
	if (X[2].x!=X[1].x&&X[2].x!=X[3].x&&X[1].x!=X[3].x)
		return;
	if (X[1].x==X[3].x) swap(X[3],X[2]);
	if (X[2].x==X[3].x) swap(X[3],X[1]);
	int d=abs(X[1].x-X[3].x);
	if (!d) return;
	st[1].x=st[2].x=X[1].x;
	st[3].x=st[4].x=X[3].x;
	st[1].y=st[3].y=Y[1].y;
	st[2].y=st[4].y=Y[1].y+d;
	work(1,3,1,0);
	st[2].y=st[4].y=Y[1].y-d;
	work(1,3,1,0);
}
void work22(){
	int xdel=abs(X[1].x-X[2].x);
	int ydel=abs(Y[1].y-Y[2].y);
	if (!xdel&&!ydel) return;
	st[1].x=st[2].x=X[1].x;
	st[3].x=st[4].x=X[2].x;
	st[1].y=st[3].y=Y[1].y;
	st[2].y=st[4].y=Y[2].y;
	if (xdel==ydel) work(1,2,2,0);
	if (!ydel&&xdel){
		st[2].y=st[4].y=Y[1].y+xdel;
		work(1,2,2,0);
		st[2].y=st[4].y=Y[1].y-xdel;
		work(1,2,2,0);
		st[2].y=st[4].y=Y[2].y;
	}
	if (!xdel&&ydel){
		st[3].x=st[4].x=X[1].x+ydel;
		work(1,2,2,0);
		st[3].x=st[4].x=X[1].x-ydel;
		work(1,2,2,0);
		st[3].x=st[4].x=X[2].x;
	}
}
void dfs(int x,int sz1,int sz2){
	if (x==5){
		memcpy(X,Xx,sizeof(X));
		memcpy(Y,Yy,sizeof(Y));
		if (sz1<sz2){
			for (int i=1;i<=sz2;i++)
				swap(X[i],Y[i]);
			for (int i=1;i<=sz2;i++)
				swap(X[i].x,X[i].y);
			for (int i=1;i<=sz1;i++)
				swap(Y[i].x,Y[i].y);
			rev=1;
			swap(sz1,sz2);
		}
		else rev=0;
		if (!sz2) work04();
		if (sz2==1) work13();
		if (sz2==2) work22();
		//printf("%d %d %d %d\n",sz1,sz2,rev,ans);
		return;
	}
	Xx[sz1+1]=a[x];
	dfs(x+1,sz1+1,sz2);
	Yy[sz2+1]=a[x];
	dfs(x+1,sz1,sz2+1);
}
int main(){
	scanf("%d",&T);
	while (T--){
		ans=1e9;
		for (int i=1;i<=4;i++)
			scanf("%d%d",&a[i].x,&a[i].y),a[i].id=i;
		dfs(1,0,0);
	//	printf("2333333333 %d ",T); 
		if (ans==1e9){
			printf("-1\n");
			continue;
		}
		printf("%d\n",ans);
		for (int i=1;i<=4;i++)
			printf("%d %d\n",Ans[i].x,Ans[i].y);
	}
}