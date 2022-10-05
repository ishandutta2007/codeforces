#include<bits/stdc++.h>
using namespace std;

struct R{
	int to,fl,co,nex;
}r[3010*3010<<1];
int hea[6010]={0},cnt=1,n,a[6010],in[6010],st,en,ans,x,y,z,pv[6010],pe[6010],tot;

void A(int u,int v,int f,int c){
	r[++cnt]=(R){v,f,-c,hea[u]}; hea[u]=cnt;
	r[++cnt]=(R){u,0,c,hea[v]}; hea[v]=cnt;
}

queue<int>q;
void Spfa(){
	while (!q.empty()) q.pop();
	memset(in,0,sizeof in);
	memset(a,33,sizeof a);
	a[st]=0; 
	for (q.push(st);!q.empty();in[x]=0){
		x=q.front(); q.pop();
		for (int i=hea[x];i>0;i=r[i].nex) if (r[i].fl){
			y=r[i].to;
			z=r[i].co+a[x];
			if (z<a[y]){
				a[y]=z;
				pv[y]=x;
				pe[y]=i;
				if (!in[y]++) q.push(y);
			}
		}
	}
	ans-=a[en];
	for (x=en;x!=st;x=pv[x]){
		r[pe[x]].fl--;
		r[pe[x]^1].fl++;
	}
}

int main(){
	cin>>n;
	for (int i=1;i<=n;cin>>a[i++]);
	for (int i=1;i<n;i++){
		tot=0;
		for (int j=i+1;j<=n&&tot<4;j++){
			if (a[i]-a[j]==1){
				tot++;
				A(i+n,j,1,0);
			}
		}
	}
	for (int i=1;i<n;i++){
		tot=0;
		for (int j=i+1;j<=n&&tot<4;j++){
			if (a[i]-a[j]==-1){
				tot++;
				A(i+n,j,1,0);
			}
		}
	}
	for (int i=1;i<n;i++){
		tot=0;
		for (int j=i+1;j<=n&&tot<4;j++){
			if (abs(a[i]-a[j])%7==0){
				tot++;
				A(i+n,j,1,0);
			}
		}
	}
		
	st=n<<1|1;en=st+1;
	for (int i=1;i<=n;i++){
		A(st,i,1,0);
		A(i+n,en,1,0);
		A(i,i+n,1,1);
	}
	A(st,en,4,0);
	for (int i=1;i<=4;i++) Spfa();
	cout<<ans;
}