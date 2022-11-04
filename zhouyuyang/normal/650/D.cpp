#include<bits/stdc++.h>
#define N 400005
using namespace std;
int a[N],lsa[N],lsb[N],ansla[N],anslb[N];
int p[N],cs[N],ok[N],ans[N],n,m,x,v,pcnt;
struct que{int v,id;};
vector<que> q[N];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&x,&v);
		q[x].push_back((que){v,i});
	}
	p[0]=-2e9,pcnt=1;
	for (int i=1;i<=n;i++){
		for (int k=q[i].size()-1;k>=0;k--){
			int pos=lower_bound(p,p+pcnt,q[i][k].v)-p;
			ansla[q[i][k].id]=pos;
		}
		int pos=lower_bound(p,p+pcnt,a[i])-p;
		lsa[i]=pos; p[pos]=a[i];
		if (pos==pcnt) pcnt++;
	}
	int lis=pcnt-1;
	p[0]=-2e9,pcnt=1;
	for (int i=n;i;i--){
		for (int k=q[i].size()-1;k>=0;k--){
			int pos=lower_bound(p,p+pcnt,-q[i][k].v)-p;
			anslb[q[i][k].id]=pos;
		}
		int pos=lower_bound(p,p+pcnt,-a[i])-p;
		lsb[i]=pos; p[pos]=-a[i];
		if (pos==pcnt) pcnt++;
	}
	memset(cs,-1,sizeof(cs));
	for (int i=1;i<=n;i++)
		if (lsa[i]+lsb[i]==lis+1)
			if (cs[lsa[i]]==-1) cs[lsa[i]]=i;
			else cs[lsa[i]]=-2;
	for (int i=1;i<=lis;i++)
		if (cs[i]>0) ok[cs[i]]=1;
	for (int i=1;i<=n;i++)
		for (int k=0;k<q[i].size();k++)
			ans[q[i][k].id]=max(ok[i]?lis-1:lis,ansla[q[i][k].id]+anslb[q[i][k].id]-1);
	for (int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
}