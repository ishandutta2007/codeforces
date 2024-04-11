#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,m,ans;
int a[N],f[2][N*2];
int id[2][N],g[2][N]; 
struct que{
	int x,tp,id;
}q[N*2];
bool cmp(que a,que b){
	return a.x<b.x;
}
void add(int x,int y,int z){
	for (;x<=m;x+=x&(-x)) f[z][x]=max(f[z][x],y);
}
int ask(int x,int z){
	int k=0;
	for (;x;x-=x&(-x)) k=max(k,f[z][x]);
	return k;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		q[++m]=(que){a[i]-i,0,i};
		q[++m]=(que){a[i]-i+1,1,i};
	}
	sort(q+1,q+m+1,cmp);
	int cnt=0;
	for (int i=1;i<=m;i++){
		cnt+=(i==1||q[i].x>q[i-1].x);
		id[q[i].tp][q[i].id]=cnt;
	}
	for (int i=1;i<=n;i++){
		g[0][i]=ask(id[0][i],0)+1;
		g[1][i]=max(g[1][i],ask(id[1][i],1)+1);
		if (i<n) g[1][i+1]=ask(id[1][i+1],0)+2;
		else ans=max(ans,ask(m,0)+1);
		ans=max(ans,max(g[0][i],g[1][i]));
		add(id[0][i],g[0][i],0);
		add(id[1][i],g[1][i],1); 
	}
	printf("%d",n-ans); 
}