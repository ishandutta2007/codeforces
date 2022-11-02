#include<bits/stdc++.h>
using namespace std;
const int N=17;
int n,p[1<<N];bool used[1<<N];
struct Edge{int nxt,to;}e[N*(1<<N)];int fir[1<<N];
void add(int u,int v,int i){e[i]=(Edge){fir[u],v},fir[u]=i;}
int col[1<<N];
void solve(){
	cin>>n;
	for(int i=0;i<(1<<n);++i){
		used[i]=0,p[i]=fir[i]=col[i]=0;
	}
	for(int i=1;i<=n*(1<<(n-1));++i){
		int u,v;scanf("%d%d",&u,&v);
		add(u,v,i<<1),add(v,u,i<<1|1);
	}
	p[0]=0,used[0]=true;
	for(int i=fir[0],j=0;i;i=e[i].nxt,j++){
		p[1<<j]=e[i].to,used[e[i].to]=true;
	}
	for(int i=1;i<(1<<n);++i){
		if(p[i]) continue;
		vector<int> bag;
		set<int> fuck1,fuck2;
		for(int j=0;j<n;++j){
			if(i&(1<<j)) bag.push_back(p[i^(1<<j)]);
		}
		for(int j=0;j<(int)bag.size();++j){
			if(!j){
				for(int c=fir[bag[j]];c;c=e[c].nxt)
				if(!used[e[c].to]) fuck2.insert(e[c].to);
			}
			else{
				fuck1=fuck2,fuck2.clear();
				for(int c=fir[bag[j]];c;c=e[c].nxt){
					if(fuck1.find(e[c].to)==fuck1.end()) continue;
					fuck2.insert(e[c].to);
				}
			}
		}
		p[i]=*fuck2.begin(),used[*fuck2.begin()]=true;
	}
	for(int i=0;i<(1<<n);++i) printf("%d ",p[i]);
	printf("\n");
	if(n-(n&(-n))) return printf("-1\n"),void();
	for(int i=0;i<(1<<n);++i){
		int tmp=i;
		for(int j=0;j<n;++j)
		col[p[i]]^=j*(tmp&1),tmp>>=1;
	}
	for(int i=0;i<(1<<n);++i) printf("%d ",col[i]);
	return printf("\n"),void();
}
int main(){
	int T;cin>>T;
	while(T--) solve();
}