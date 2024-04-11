#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,k,ave,a[N],sa[N],i,j,anc[20][N],step[N],mn=N,mnid,u,v,l;
unordered_map<int,int>lst[N];
vector<vector<int>>ans;
int getsum(int s,int k){int ans=0;for(int i=0;i<k;++i)ans+=a[s+i];return ans;}
int RR;
void opt(int s,int v,int k){
	int tot=0,i;
assert(k>1);
	a[s+k-1]=getsum(s,k)-v-ave*(k-2);a[s]=v;for(i=1;i+1<k;++i)a[s+i]=ave;
	vector<int>ve={(s-1+n-(::k-k))%n};int kk=k;
	for(;kk<::k;++kk)ve.push_back(a[RR--]);reverse(ve.begin()+1,ve.end());
	ve.insert(ve.end(),a+s,a+s+k);
	ans.push_back(ve);
}
void solve(int l,int r){
	int i,tot=getsum(max(r-k+1,l),min(k,r-l+1));
	for(i=r-k+1;i>=l && tot*1.0/(r-i+1)<ave;i-=k-1,tot+=getsum(i,k-1));
int tt=i;
	if(i<l){
		if(i+k-1>l)RR=mnid,opt(l,ave,i+k-1-l+1);
	}else{
		opt(i,getsum(i,r-i+1)-ave*(r-i),k);
	}
	for(;i+=k-1,i<r;)opt(i,ave,k);
	if(l<tt)solve(l,tt);
}
int oa[N];
void spj(){
	for(auto u:ans){
		int s1=0,s2=0;
		assert(u.size()==k+1);
		for(int i=0;i<k;++i)s1+=oa[(u[0]+i)%n],s2+=u[1+i],assert(u[1+i]>=0);
		assert(s1==s2);
		for(int i=0;i<k;++i)oa[(u[0]+i)%n]=u[1+i];
	}
	for(int i=0;i<n;++i)assert(oa[i]==ave);
}
int main(){
	//freopen("1","r",stdin);
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;++i)scanf("%d",a+i),ave+=a[i+n]=a[i];
	ave/=n;
memcpy(oa,a+1,n<<2);
	for(i=1;i<=n*2;++i){
		sa[i]=sa[i-1]+a[i]-ave;
		anc[0][i]=lst[(i-1)%(k-1)][sa[i]];
		step[i]=anc[0][i]?step[anc[0][i]]+(i-anc[0][i]-1)/(k-1):0;
		lst[i%(k-1)][sa[i]]=i;
	}
	for(i=1;i<20;++i)for(j=1;j<=n*2;++j)anc[i][j]=anc[i-1][anc[i-1][j]];
	for(i=n+1;i<=n*2;++i){
		for(u=i,j=19;j>=0;--j)if(anc[j][u]>=i-n)u=anc[j][u];
		v=step[i]-step[u];l=u-(i-n);
		if(l)v+=l<=k?1:(l-k+k-2)/(k-1)+1;
		if(v<mn)mn=v,mnid=i;
	}
	for(i=mnid;i>mnid-n;i=anc[0][i])if(anc[0][i]+1<i)solve(max(mnid-n,anc[0][i])+1,i);
	printf("%d\n",int(ans.size()));
	assert(ans.size()==mn);
	for(auto u:ans){for(int x:u)printf("%d ",x);puts("");}
spj();
	return 0;
}