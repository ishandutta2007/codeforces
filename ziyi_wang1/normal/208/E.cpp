#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
#define I inline void
#define IN inline int
#define C(x,y) memset(x,y,sizeof(x))
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
vector<int>e[101000],vec,t[101000],q[101000];
int n,m,cnt,dep[101000],st[101000],p[101000],w[101000],ans[101000],lc[5050000],rc[5050000],tr[5050000],root[101000];
I D_1(int x,int depth){
	dep[x]=depth;st[depth]=x;
	for(auto d:e[x])D_1(d,depth+1);
	for(auto d:t[x]){
		if(depth<=w[d])continue;
		q[st[depth-w[d]]].emplace_back(d);
	}
}
I modi(int &k,int l,int r,int x){
	if(!k)k=++cnt;tr[k]++;
	if(l==r)return;
	re mid=(l+r)>>1;
	if(x<=mid)modi(lc[k],l,mid,x);
	else modi(rc[k],mid+1,r,x);
}
IN ques(int k,int l,int r,int x){
	if(l==r)return tr[k];
	re mid=(l+r)>>1;
	if(x<=mid)return ques(lc[k],l,mid,x);
	else return ques(rc[k],mid+1,r,x);
}
IN merge(int x,int y){
	if(!x||!y)return x+y;
	tr[x]+=tr[y];lc[x]=merge(lc[x],lc[y]);rc[x]=merge(rc[x],rc[y]);
	return x;
}
I D_2(int x){
	for(auto d:e[x]){
		D_2(d);
		if(!root[x])root[x]=root[d];
		else root[x]=merge(root[x],root[d]);
	}
//	cout<<x<<":";
	for(auto d:q[x])ans[d]=ques(root[x],1,n,dep[x]+w[d])-1;//,cout<<d<<" ";
	modi(root[x],1,n,dep[x]);
}
int main(){
	read(n);
	F(i,1,n){
		read(m);
		if(!m)vec.emplace_back(i);
		else e[m].emplace_back(i);
	}
	read(m);
	F(i,1,m){
		read(p[i]);read(w[i]);t[p[i]].emplace_back(i);
	}
	for(auto now:vec)D_1(now,1),D_2(now);
	F(i,1,m)printf("%d ",ans[i]);
	return 0;
}