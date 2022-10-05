#include<bits/stdc++.h>
using namespace std;
map<int,char>mp[233],ans;
int n,m,l,r,c[202000];
char s[202000],x;
int A(int x,int v){
	for (;x<=n;x+=x&-x) c[x]+=v;
}
int Q(int &y){
	for (int t=y,i=18+(y=0);~i;--i) if ((y|1<<i)<=n&&t>c[y|1<<i]) y|=1<<i, t-=c[y]; ++y;
}
int main(){
	cin.tie(0); cin>>n>>m>>s+1;
	for (int i=1;i<=n;++i) mp[s[i]][i]=1, A(i,1);
	for (;m--;){
		cin>>l>>r>>x; Q(l),Q(r);
		for (map<int,char>::iterator it=mp[x].lower_bound(l);it!=mp[x].end()&&it->first<=r;){
			A(it->first,-1); mp[x].erase(it++);
		}
	}
	for (int i=0;i<233;++i) for (auto o:mp[i]) ans[o.first]=i;
	for (auto o:ans) cout<<o.second;
}