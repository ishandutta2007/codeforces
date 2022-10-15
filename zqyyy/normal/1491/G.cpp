#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second
const int N=2e5+7;
int n,c[N],p[N];
bool vis[N];
vector<pii>ans;
vector<vector<int> >res;
inline void op(int x,int y){
	ans.emplace_back(x,y);
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)c[i]=read(),p[c[i]]=i;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		int x=p[i],sz=1;vis[i]=1;vector<int>pot(0);
		while(!vis[x])vis[x]=1,pot.push_back(x),x=p[x],sz++;
		if(sz==1)continue;
		pot.push_back(i);
		reverse(pot.begin(),pot.end());
		res.push_back(pot);
	}
	int j;
	for(j=0;j<(int)res.size()-1;j+=2){
		vector<int>t1=res[j],t2=res[j+1];
		op(*t1.rbegin(),*t2.begin());
		for(int i=0;i<(int)t1.size()-1;i++)op(t1[i],*t2.begin());
		for(int i=1;i<(int)t2.size()-1;i++)op(t2[i],*t1.rbegin());
		op(*t1.rbegin(),*t2.rbegin());
		op(*t1.rbegin(),*t2.begin());
	}
	if(j!=(int)res.size()){
		vector<int>t=res[j];
		if((int)t.size()==2){
			for(int i=1;i<=n;i++)vis[i]=0;
			for(int x:t)vis[x]=1;
			int x=0;
			for(int i=1;i<=n;i++)
				if(!vis[i]){x=i;break;}
			op(t[0],x),op(t[1],x),op(t[0],x);
		}else{
			int x=*--(--t.end()),y=*--(--(--t.end()));
			op(*t.rbegin(),x);
			for(int i=0;i<(int)t.size()-3;i++)op(x,t[i]);
			op(*t.rbegin(),y),op(x,y),op(*t.rbegin(),x);
		}
	}
	printf("%lu\n",ans.size());
	for(auto x:ans)printf("%d %d\n",x.fi,x.se);
	return 0;
}