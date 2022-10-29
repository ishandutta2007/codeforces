#include<bits/stdc++.h>
#define maxn 2010
using namespace std;
struct Data{int x,y,w;};
struct cmp{
	int operator()(const vector<int>& a,const vector<int>& b)const{
		return a.size()==b.size()?a<b:a.size()<b.size();
	}
};
typedef pair<int,int> pii;
int p=0,np=1,a[maxn],b[maxn],n,dp[2][10][1010];
vector<Data>trans[1010];
map<vector<int>,int,cmp>st;
int trans2[1010][10],ax[20],id,f[1010];
void upd(int& x,int y){
	x=x<y?x:y;
}
void dfs(int nw,int lst){
	vector<int>G;
	for(int i=1;i<nw;++i)G.push_back(ax[i]);
	st[G]=0;
	if(nw==5)return ;
	for(int i=lst;i<=9;++i)
		ax[nw]=i,dfs(nw+1,i);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&a[i],&b[i]);
	dfs(1,1);
	for(auto& p:st)p.second=++id;
	for(auto p:st){
//		if(p.second==12){for(auto z:p.first)printf("[%d]",z);puts("");}
		const vector<int>& v=p.first;
		vector<int> ls;
		for(auto q:v)ls.push_back(q);
		sort(ls.begin(),ls.end());
		ls.erase(unique(ls.begin(),ls.end()),ls.end());
		for(auto q:ls){
			vector<int> ls2;
			int rsum=0;
			for(auto z:v)if(z!=q)ls2.push_back(z);else rsum++;
			trans[p.second].push_back(Data{q,st[ls2],rsum});
		}
		if(v.size()<4){
			for(int i=1;i<=9;++i){
				vector<int> ls3=v;
				ls3.push_back(i);
				sort(ls3.begin(),ls3.end());
				trans2[p.second][i]=st[ls3];
//				if(p.second==1)printf("[%d]",st[ls3]);
			}
		}
	}
//	printf("{%d}",n);
	memset(dp,0x3f,sizeof(dp));
	dp[np][1][1]=0;
	for(int i=1;i<=n;++i,swap(p,np))
		for(int l=id;l>=1;--l)
			for(int j=1;j<=9;++j)if(dp[np][j][l]!=0x3f3f3f3f){
			int val=dp[np][j][l];
//			printf("{%d,%d,%d,%d}",j,l,trans2[l][b[i]],b[i]);
			for(auto p:trans[l])upd(dp[np][p.x][p.y],val+abs(p.x-j)+p.w);//,printf("[%d,%d]",p.y,l);
			if(trans2[l][b[i]])upd(dp[p][a[i]][trans2[l][b[i]]],val+abs(a[i]-j)+1);
			dp[np][j][l]=0x3f3f3f3f;
		}
	for(int l=id;l>=1;--l)
		for(int j=1;j<=9;++j)if(dp[np][j][l]!=0x3f3f3f3f)
			for(auto p:trans[l])upd(dp[np][p.x][p.y],dp[np][j][l]+abs(p.x-j)+p.w);
	int ans=0x3f3f3f3f;
	for(int i=1;i<=9;++i)ans=min(ans,dp[np][i][1]);
	printf("%d",ans);
}