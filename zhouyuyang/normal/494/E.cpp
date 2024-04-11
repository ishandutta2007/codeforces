#include<bits/stdc++.h>
#define y1 wzpakking
using namespace std;
int t[265000],cov[265000];
struct que{
	int x,y1,y2,v;
}q[100005];
int top,Y[100005];
int m,K,k,ans,n;
void change(int k,int l,int r,int x,int y,int v){
	if (l==x&&r==y){
		cov[k]+=v;
		if (cov[k]) t[k]=Y[r]^Y[l-1];
		else if (l!=r) t[k]=t[k*2]^t[k*2+1];
		else t[k]=0;
		return;
	}
	int mid=(l+r)/2;
	if (y<=mid) change(k*2,l,mid,x,y,v);
	else if (x>mid) change(k*2+1,mid+1,r,x,y,v);
	else change(k*2,l,mid,x,mid,v),
		 change(k*2+1,mid+1,r,mid+1,y,v);
	if (!cov[k]) t[k]=t[k*2]^t[k*2+1]; 
}
bool cmp(que a,que b){
	return a.x<b.x;
}
int solve(){
	int x1,y1,x2,y2,prex=0,ans=0;
	for (int i=1;i<=m;i++){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		q[++top]=(que){x1-1,y1-1,y2,1};
		q[++top]=(que){x2,y1-1,y2,-1};
		Y[++Y[0]]=y1-1; Y[++Y[0]]=y2;
	}
	sort(q+1,q+top+1,cmp);
	sort(Y+1,Y+Y[0]+1);
	Y[0]=unique(Y+1,Y+Y[0]+1)-Y-1;
	for (int i=1;i<=top;i++){
		ans^=(q[i].x^prex)&t[1]; prex=q[i].x;
		q[i].y1=lower_bound(Y+1,Y+Y[0]+1,q[i].y1)-Y;
		q[i].y2=lower_bound(Y+1,Y+Y[0]+1,q[i].y2)-Y;
		change(1,1,Y[0],q[i].y1+1,q[i].y2,q[i].v);
	}
	return ans;
}
int main(){
	scanf("%*d%d%d",&m,&K);
	int k=1;
	for (;k<=K;k*=2);
	puts(solve()&(k-1)?"Hamed":"Malek");
}