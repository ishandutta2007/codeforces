#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
typedef long long ll;
#define I inline void
#define IN inline int
#define STS system("pause")
template<class D>I read(D &res){
	res=0;register D g=1;register char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')g=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	res*=g;
}
typedef vector<int> V;
const int N=1<<12,M=1<<16,B=1<<8,K=1<<22;
int n,m,tot,a[N],c[K],d[K],pos[N],ans[M];
IN merge(int x,int y){
	if(!x||!y)return !x*y+!y*x;
	return c[tot]=x,d[tot]=y,++tot;
}
struct seg{
	vector<int> val;vector< vector<int> >id;
	I init(int x){val.resize(x);id.resize(x);F(i,0,x-1)id[i].resize(x-i);}
	seg(int x=-1){if(~x)init(1),val[0]=pos[x],id[0][0]=pos[x]+1;}
	IN ask(int l,int r){
		if(r<val.front()||l>val.back())return 0;
		l=lower_bound(val.begin(),val.end(),l)-val.begin();
		r=upper_bound(val.begin(),val.end(),r)-val.begin()-1;
		return l>r?0:id[l][r-l];
	}
	friend seg operator * (seg x,seg y){
		seg res;res.init(x.val.size()+y.val.size());
		merge(x.val.begin(),x.val.end(),y.val.begin(),y.val.end(),res.val.begin());
		F(i,0,res.val.size()-1)F(j,i,res.val.size()-1)
			res.id[i][j-i]=merge(x.ask(res.val[i],res.val[j]),y.ask(res.val[i],res.val[j]));
		return res;
	}
}t[N/B];
inline seg solve(int l,int r){
	if(l==r)return(l);
	int mid=(l+r)>>1;seg out;
	return solve(l,mid)*solve(mid+1,r);
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;tot=n--;
	F(i,0,n)cin>>a[i],a[i]--;
	F(i,0,n)pos[a[i]]=i;
	F(i,0,n/B)t[i]=solve(i*B,min(n,i*B+B-1));
	int l,r;
	F(i,0,m-1){
		cin>>l>>r;l--,r--;
		F(j,0,n/B)ans[i]=merge(ans[i],t[j].ask(l,r));
	}
	cout<<tot<<'\n';
	F(i,n+1,tot-1)cout<<c[i]<<' '<<d[i]<<'\n';
	F(i,0,m-1)cout<<ans[i]<<' ';
	return 0;
}