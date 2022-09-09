#include<bits/stdc++.h>
using namespace std;
const int N=1005;
struct P{
	int x,y;
	inline void in(){scanf("%d%d",&x,&y);}
	inline P operator-(const P&rhs)const{return (P){x-rhs.x,y-rhs.y};}
	inline int reduce(){
		int d=__gcd(abs(x),abs(y));
		x/=d;y/=d;return d;
	}
	inline bool operator<(const P&rhs)const{return x==rhs.x?y<rhs.y:x<rhs.x;}
}a[9],m[N];
int k,n,i,j,l,p[9],ans,q[9],w,x;
map<P,vector<pair<int,int>>>mp[9];
vector<pair<int,int>>*b[N][9];
bool inq[N];
int main(){
	scanf("%d%d",&k,&n);
	for(i=1;i<=k;++i)a[i].in();
	for(i=1;i<=n;++i)m[i].in();
	for(i=1;i<=k;++i){
		for(j=1;j<=n;++j){
			P dt=m[j]-a[i];int z=dt.reduce();
			mp[i][dt].push_back(make_pair(z,j));
		}
		for(auto&u:mp[i]){
			sort(u.second.begin(),u.second.end());
			for(auto v:u.second)b[v.second][i]=&u.second;
		}
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=k;++j)p[j]=j;
		do{
			q[w=1]=i;inq[i]=1;
			for(j=1;j<=k && j<=w && w<=k;++j)
				for(l=0;x=b[q[j]][p[j]]->at(l).second,x!=q[j] && w<=k;++l)
					if(!inq[x])q[++w]=x,inq[x]=1;
			for(j=1;j<=w;++j)inq[q[j]]=0;
			if(w<=k){++ans;break;}
		}while(next_permutation(p+1,p+k+1));
	}
	printf("%d\n",ans);
	return 0;
}