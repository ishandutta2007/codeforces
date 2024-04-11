#include<bits/stdc++.h>
using namespace std;
#define LL long long
struct nod{
	int w,a,b,flg;
	bool operator<(const nod &x) const{
		return w<x.w;
	}
};
int pre[1000010];
int find(int x){ return pre[x]==x?x:pre[x]=find(pre[x]);}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);

	int t;cin>>t;
	while(t--){
		int n,m,k;cin>>n>>m>>k;
		vector<nod> e;

		int ss=2e9;

		for(int i=1;i<=n;i++) pre[i]=i;
		for(int i=1;i<=m;i++){
			int a,b,c;cin>>a>>b>>c;
			int w=max(0,c-k);
			int flg=c>=k;

			ss=min(ss,abs(c-k));

			nod tmp = {w,a,b,flg};
			e.push_back(tmp);
		}
		sort(e.begin(),e.end());
		LL ans=0;
		int flg=0;
		for(auto &it:e){
			int a=it.a;
			int b=it.b;
			int fa=find(a);
			int fb=find(b);
			if(fa!=fb){
				pre[fa]=fb;
				ans+=it.w;
				flg|=it.flg;
			}
		}
		if(!flg) ans+=ss;
		cout<<ans<<endl;
	}
}