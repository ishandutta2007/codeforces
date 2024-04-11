#include<bits/stdc++.h>
using namespace std;

struct DSU{
	int p[401],sz[401];
	void init(int n){
		for(int i=1;i<=n;i++)	sz[p[i]=i]=1;
	}
	int F(int x){
		return x==p[x]?x:p[x]=F(p[x]);
	}
	bool U(int x,int y){
		x=F(x),y=F(y);
		if(x==y)	return false;
		if(sz[x]<sz[y])	swap(x,y);
		p[y]=x;
		sz[x]+=sz[y];
		return true;
	}
}D,Dwo[801];
vector<pair<int,int> > edge;

string s[20];
int id[20][20];
bool black[401];
int c;
int ecnt[401];
bool ind[801];
int X[401],Y[401];
void prepare_o1(){
	D.init(c);
	for(int i=0;i<edge.size();i++)
		if(ind[i])
			D.U(edge[i].first,edge[i].second);
	for(int i=0;i<edge.size();i++)
		if(ind[i]){
			Dwo[i].init(c);
			for(int j=0;j<edge.size();j++)
				if(i!=j&&ind[j])
					Dwo[i].U(edge[j].first,edge[j].second);
		}
}
void prepare_o2(){
	for(int i=1;i<=c;i++)
		ecnt[i]=0;
	for(int i=0;i<edge.size();i++)
		if(ind[i])
			ecnt[edge[i].first]++,ecnt[edge[i].second]++;	
}
bool o1(int ins){
	int l=edge[ins].first,r=edge[ins].second;
	return D.F(l)!=D.F(r);
}
bool o1(int ins,int rem){
	int l=edge[ins].first,r=edge[ins].second;
	return Dwo[rem].F(l)!=Dwo[rem].F(r);
}
bool o2(int ins){
	int l=edge[ins].first,r=edge[ins].second;
	return (!black[l]||ecnt[l]!=2)&&(!black[r]||ecnt[r]!=2);
}
bool o2(int ins,int rem){
	int l=edge[ins].first,r=edge[ins].second;
	int ll=edge[rem].first,rr=edge[rem].second;
	if(black[ll])	ecnt[ll]--;
	if(black[rr])	ecnt[rr]--;
	bool res=(!black[l]||ecnt[l]!=2)&&(!black[r]||ecnt[r]!=2);
	if(black[ll])	ecnt[ll]++;
	if(black[rr])	ecnt[rr]++;
	return res;
}
bool augment(){
	prepare_o1();
	prepare_o2();
	vector<int> p(edge.size(),-2);
	queue<int> q;
	int gs=edge.size();
	for(int i=0;i<gs;i++)
		if(!ind[i]&&o1(i))
			p[i]=-1,q.emplace(i);
	int last=-1;
	while(!q.empty()){
		int cur=q.front();q.pop();
		if(ind[cur]){
			for(int to=0;to<gs;to++)
				if(p[to]==-2&&!ind[to]&&o1(to,cur))
					p[to]=cur,q.emplace(to);
		}
		else{
			if(o2(cur)){
				last=cur;
				break;
			}
			for(int to=0;to<gs;to++)
				if(p[to]==-2&&ind[to]&&o2(cur,to))
					p[to]=cur,q.emplace(to);
		}
	}
	if(last==-1)	return false;
	while(last!=-1){
		ind[last]^=1;
		last=p[last];
	}
	return true;
}
string ans[50];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		edge.clear();
		memset(id,0,sizeof id);
		memset(black,0,sizeof black);
		memset(ind,0,sizeof ind);
		int b;
		c=b=0;
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>s[i];
			for(int j=0;j<m;j++)
				if(s[i][j]=='O'){
					id[i][j]=++c;
					X[c]=i,Y[c]=j;
					if(i+j!=0&&(i+j)%2==0)
						black[id[i][j]]=true,b++;
				}
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				if(i+1<n&&id[i][j]&&id[i+1][j]&&i+j!=0)
					edge.emplace_back(id[i][j],id[i+1][j]);
				if(j+1<m&&id[i][j]&&id[i][j+1]&&i+j!=0)
					edge.emplace_back(id[i][j],id[i][j+1]);
			}
		while(augment());
		b<<=1;
		for(int i=0;i<edge.size();i++)
			if(ind[i])
				b--;
		if(b==0)
			cout<<"YES"<<'\n';
		else{
			cout<<"NO"<<'\n';
			continue;
		}
		for(int i=0;i<2*n-1;i++)
			ans[i]=string(2*m-1,' ');
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				ans[2*i][2*j]=s[i][j];
		D.init(c);
		for(int i=0;i<edge.size();i++)
			if(ind[i])
				D.U(edge[i].first,edge[i].second);
		for(int i=0;i<edge.size();i++)
			if(!ind[i]&&D.U(edge[i].first,edge[i].second))
				ind[i]=true;
		for(int i=0;i<edge.size();i++)
			if(ind[i]){
				int x1=X[edge[i].first],y1=Y[edge[i].first];
				int x2=X[edge[i].second],y2=Y[edge[i].second];
				if(make_pair(x1,y1)>make_pair(x2,y2))
					swap(x1,y1),swap(x2,y2);
				if(x1==x2)
					ans[x1*2][y1*2+1]='O';
				else
					ans[x1*2+1][y1*2]='O';
			}
		if(s[0][0]==s[0][1]&&D.U(id[0][0],id[0][1]))
			ans[0][1]='O';
		if(s[0][0]==s[1][0]&&D.U(id[0][0],id[1][0]))
			ans[1][0]='O';
		for(int i=0;i<2*n-1;i++)
			cout<<ans[i]<<'\n';
	}
}