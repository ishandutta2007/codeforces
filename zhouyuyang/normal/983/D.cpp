#include<bits/stdc++.h>
using namespace std;
const int N=100005;
const int M=525000;
int a[N],b[N],c[N],d[N];
int n,ans,qx[N*2],qy[N*2];
int vis[N*2],mx[M],mn[M];
vector<pair<int,int> > v[N*2];
set<int> s[M];
void pushup(int k,int l,int r){
	if (l!=r){
		mx[k]=max(mx[k*2],mx[k*2+1]);
		mn[k]=min(mn[k*2],mn[k*2+1]);
	}
	else
		mx[k]=mn[k]=0;
	if (s[k].size()){
		if (vis[*s[k].rbegin()])
			mn[k]=max(mn[k],*s[k].rbegin());
		else mx[k]=max(mx[k],*s[k].rbegin());
	}
	if (mx[k]<mn[k])
		mx[k]=0;
}
void insert(int k,int l,int r,int x,int y,int v){
	//printf("%d %d %d %d\n",l,r,x,y);
	if (l==x&&r==y){
		if (v){
			if (v>0) s[k].insert(v);
			else s[k].erase(-v); 
		}
		pushup(k,l,r);
		return;
	}
	int mid=(l+r)/2;
	if (y<=mid) insert(k*2,l,mid,x,y,v);
	else if (x>mid) insert(k*2+1,mid+1,r,x,y,v);
	else insert(k*2,l,mid,x,mid,v),
		 insert(k*2+1,mid+1,r,mid+1,y,v);
	pushup(k,l,r);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
		qx[++*qx]=a[i]; qx[++*qx]=c[i];
		qy[++*qy]=b[i]; qy[++*qy]=d[i];
	}
	sort(qx+1,qx+*qx+1);
	sort(qy+1,qy+*qy+1);
	*qx=unique(qx+1,qx+*qx+1)-qx-1;
	*qy=unique(qy+1,qy+*qy+1)-qy-1;
	for (int i=1;i<=n;i++){
		a[i]=lower_bound(qx+1,qx+*qx+1,a[i])-qx;
		c[i]=lower_bound(qx+1,qx+*qx+1,c[i])-qx;
		b[i]=lower_bound(qy+1,qy+*qy+1,b[i])-qy;
		d[i]=lower_bound(qy+1,qy+*qy+1,d[i])-qy-1;
		v[a[i]].push_back(make_pair(i,i));
		v[c[i]].push_back(make_pair(i,-i));
	}
	for (int i=1;i<=*qx;i++){
		for (int j=0;j<v[i].size();j++)
			insert(1,1,*qy,b[v[i][j].first],d[v[i][j].first],v[i][j].second);
		for (;mx[1];){
			vis[mx[1]]=1; ans++;
			insert(1,1,*qy,b[mx[1]],d[mx[1]],0);
		}
	}
	printf("%d",ans+1);
}