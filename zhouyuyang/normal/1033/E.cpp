#include<bits/stdc++.h>
using namespace std;
int ask(vector<int> x,vector<int> y){
	int ans=0,tmp;
	if (x.size()!=1){
		printf("? %d\n",x.size());
		for (int i=0;i<x.size();i++) printf("%d ",x[i]);
		puts("");
		fflush(stdout);
		scanf("%d",&tmp); ans-=tmp;
	}
	if (y.size()!=1){
		printf("? %d\n",y.size());
		for (int i=0;i<y.size();i++) printf("%d ",y[i]);
		puts("");
		fflush(stdout);
		scanf("%d",&tmp); ans-=tmp;
	}
	printf("? %d\n",x.size()+y.size());
	for (int i=0;i<x.size();i++) printf("%d ",x[i]);
	for (int i=0;i<y.size();i++) printf("%d ",y[i]);
	puts("");
	fflush(stdout);
	scanf("%d",&tmp); ans+=tmp;
	return ans;
}
pair<int,int> find_edge(vector<int> v1,vector<int> v2,int lasv=-1){
	if (lasv==-1) lasv=ask(v1,v2);
	if (!lasv) return make_pair(0,0);
	if (v1.size()<v2.size()) swap(v1,v2);
	if (v1.size()==1) return make_pair(v1[0],v2[0]);
	vector<int> ls,rs;
	for (int i=0;i<v1.size();i++)
		if (i&1) ls.push_back(v1[i]);
		else rs.push_back(v1[i]);
	int lv=ask(ls,v2);
	if (lv) return find_edge(ls,v2,lv);
	else return find_edge(rs,v2,lasv-lv);
}
pair<int,int> check(vector<int> v){
	if (v.size()==1) return make_pair(0,0);
	vector<int> ls,rs;
	for (int i=0;i<v.size();i++)
		if (i&1) ls.push_back(v[i]);
		else rs.push_back(v[i]);
	pair<int,int> tmp=find_edge(ls,rs);
	if (tmp.first!=0) return tmp;
	tmp=check(ls);
	if (tmp.first!=0) return tmp;
	return check(rs);
}
vector<int> e[605];
int n,fa[605],in[605],q[605];
void dfs(int x){
	for (int i=0;i<e[x].size();i++)
		if (e[x][i]!=fa[x]){
			fa[e[x][i]]=x;
			in[e[x][i]]=in[x]^1;
			dfs(e[x][i]);
		}
}
int getLCA(int x,int y){
	memset(in,0,sizeof(in));
	for (;x;x=fa[x]) in[x]=1;
	for (;!in[y];y=fa[y]);
	return y;
}
vector<int> findpath(int x,int y){
	vector<int> ans;
	for (;x!=y;x=fa[x]) ans.push_back(x);
	ans.push_back(y);
	return ans;
}
int main(){
	scanf("%d",&n);
	if (n==1){
		printf("Y 0");
		return 0;
	}
	for (int i=1;i<=n;i++) fa[i]=i;
	in[1]=1; int h=0,t=1; q[1]=1;
	while (t!=n){
		int x=q[++h];
		for (;t!=n;){
			vector<int> v0,v1;
			v0.push_back(x);
			for (int i=1;i<=n;i++)
				if (!in[i]) v1.push_back(i);
			pair<int,int> res=find_edge(v0,v1);
			if (res.first==0) break;
			if (res.first!=x) swap(res.first,res.second);
			//printf("wzpakking %d %d\n",x,res.second);
			e[x].push_back(res.second);
			e[res.second].push_back(x);
			in[res.second]=1;
			q[++t]=res.second;
		}
	}
	in[1]=0; dfs(1); fa[1]=0;
	//for (int i=1;i<=n;i++) printf("%d\n",fa[i]);
	vector<int> v0,v1;
	for (int i=1;i<=n;i++)
		if (in[i]) v0.push_back(i);
		else v1.push_back(i);
	pair<int,int> x=check(v0);
	if (x.first){
		printf("N");
		int LCA=getLCA(x.first,x.second);
		vector<int> pth1=findpath(x.first,LCA);
		vector<int> pth2=findpath(x.second,LCA);
		pth2.pop_back();
		reverse(pth2.begin(),pth2.end());
		for (int i=0;i<pth2.size();i++)
			pth1.push_back(pth2[i]);
		printf(" %d\n",pth1.size());
		for (int i=0;i<pth1.size();i++)
			printf("%d ",pth1[i]);
		return 0;
	}
	x=check(v1);
	if (x.first){
		printf("N");
		int LCA=getLCA(x.first,x.second);
		vector<int> pth1=findpath(x.first,LCA);
		vector<int> pth2=findpath(x.second,LCA);
		pth2.pop_back();
		reverse(pth2.begin(),pth2.end());
		for (int i=0;i<pth2.size();i++)
			pth1.push_back(pth2[i]);
		printf(" %d\n",pth1.size());
		for (int i=0;i<pth1.size();i++)
			printf("%d ",pth1[i]);
	}
	else{
		printf("Y %d\n",v1.size());
		for (int i=0;i<v1.size();i++)
			printf("%d ",v1[i]);
	}
}