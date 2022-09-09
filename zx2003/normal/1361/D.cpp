#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,i,j,l,x;
struct tupl{
	int x,y,l;
	inline void in(){
		cin>>x>>y;
		if(x || y)l=abs(__gcd(x,y)),x/=l,y/=l;else --i,--n;
	}
}a[N];
vector<tupl>ve[N];int m;
double xs[N],ans;
inline void solve1(){
	for(i=1;i<=m;++i)
		sort(ve[i].begin(),ve[i].end(),[&](const tupl&A,const tupl&B){return A.l<B.l;});
	for(i=1;i<=m;++i)if(ve[i].size()>=k/2 && n+1-ve[i].size()<=k-k/2)break;
	if(i>m)return;
	double tot=0;
	for(l=1;l<=m;++l)if(l!=i)for(j=0;j<ve[l].size();++j){
		x=ve[l].size()-j;
		tot+=1.0*(ve[l][j].l-(j?ve[l][j-1].l:0))*x*(k-x)*xs[l];
	}
	int l=k-k/2-(n+1-ve[i].size()),r=ve[i].size()-k/2;
	for(j=0;j<ve[i].size();++j){
		if(j<l)x=n+1-ve[i].size()+j;
			else if(j>r)x=ve[i].size()-j;
					else x=k/2;
		tot+=1.0*(ve[i][j].l-(j?ve[i][j-1].l:0))*x*(k-x)*xs[i];
	}
	ans=max(ans,tot);
}
inline void solve2(){
	static int pp[N];
	static vector<double>vv[N];
	priority_queue<pair<double,int>>q;
	for(i=1;i<=m;++i){
		pp[i]=0;
		reverse(ve[i].begin(),ve[i].end());
		double s=0,ss=0;
		vv[i].resize(ve[i].size());
		for(j=0;j<ve[i].size();++j){
//			ss+=s+1.0*ve[i][j].l*(k-j-1);
			ss+=1.0*(ve[i][j].l)*(k-j-1-j);
			vv[i][j]=ss*xs[i];
//			if(j+1<ve[i].size())s+=1.0*(ve[i][j].l-ve[i][j+1].l)*(j+1);
		}
		q.push({vv[i][0],i});
	}
	double tot=0,zz;
	for(;k-- && !q.empty();){
		tie(zz,i)=q.top();q.pop();tot+=zz;
		if(++pp[i]<vv[i].size())q.push({vv[i][pp[i]]-vv[i][pp[i]-1],i});
	}
//	if(q.empty())for(i=1;i<=m;++i)for(auto u:ve[i])tot+=u.l*xs[i];
	ans=max(ans,tot);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;for(i=1;i<=n;++i)a[i].in();
	sort(a+1,a+n+1,[&](const tupl&A,const tupl&B){return A.x==B.x?A.y<B.y:A.x<B.x;});
	for(i=1;i<=n;i=j){
		++m;xs[m]=sqrt(1ll*a[i].x*a[i].x+1ll*a[i].y*a[i].y);
		for(j=i;j<=n && a[j].x==a[i].x && a[j].y==a[i].y;++j)ve[m].push_back(a[j]);
	}
	solve1();
	solve2();
	printf("%.8f\n",ans);
}