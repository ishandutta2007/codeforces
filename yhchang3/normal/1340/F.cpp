#include<bits/stdc++.h>
using namespace std;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const int maxn = 100010;
const int mod[2] = {1000000009, 1000000007};
const int base[2] = {1000000007, 998244353};
pair<int,int> mult[maxn];
struct HSH{
	pair<int,int> hsh;
	HSH(pair<int,int> hsh = {0,0}):hsh(hsh){}
	HSH operator+(const HSH& rhs)const{
		HSH res({hsh.first+rhs.hsh.first,hsh.second+rhs.hsh.second});
		if(res.hsh.first>=mod[0])	res.hsh.first-=mod[0];
		if(res.hsh.second>=mod[1])	res.hsh.second-=mod[1];
		return res;
	}
	HSH operator*(const pair<int,int> c)const{
		return HSH({1LL*hsh.first*c.first%mod[0],1LL*hsh.second*c.second%mod[1]});
	}
	bool operator==(const HSH& rhs)const{
		return hsh == rhs.hsh;
	}
	bool operator!=(const HSH& rhs)const{
		return hsh != rhs.hsh;
	}
}NUL;
struct TNode{
	int l, r, sz;
	HSH key, hsh;
	TNode(int l=0,int r=0,int sz=0):l(l),r(r),sz(sz){}
}T[8000000];
int stp;
int newnode(int v=0){
	++stp;
	T[stp].l=T[stp].r=0;
	T[stp].sz=1;
	T[stp].hsh=T[stp].key=HSH({v,v});
	return stp;
}
void Tpull(int cur){
	T[cur].sz = T[T[cur].l].sz + T[T[cur].r].sz + 1;
	T[cur].hsh = T[T[cur].l].hsh*mult[T[T[cur].r].sz + 1] + T[cur].key *mult[T[T[cur].r].sz] + T[T[cur].r].hsh;
}
int merge(int l,int r){
	if(!l||!r)	return l?l:r;
	int res = newnode();
	if(rng()%(T[l].sz+T[r].sz)<T[l].sz)
		T[res] = T[l], T[res].r = merge(T[l].r,r);
	else
		T[res] = T[r], T[res].l = merge(l,T[r].l);
	Tpull(res);
	return res;
}

void split(int rt,int &l,int &r,int k){
	if(rt==0)	return l=r=0,void();
	int res = newnode();
	T[res] = T[rt];
	if(T[T[rt].l].sz >= k)
		split(T[rt].l,l,T[res].l,k),r=res;
	else
		split(T[rt].r,T[res].r,r,k-1-T[T[rt].l].sz),l=res;
	Tpull(res);
}
#define ls idx<<1
#define rs idx<<1|1
int a[maxn];
struct SEGTREE{
	int cl[maxn<<2], op[maxn<<2];
	bool bad[maxn<<2];
	void pull(int idx){
		if(bad[ls]||bad[rs])
			return bad[idx] = true,void();
		if(T[op[ls]].sz >= T[cl[rs]].sz){
			int l,r;
			split(op[ls],l,r,T[op[ls]].sz-T[cl[rs]].sz);
			if(T[cl[rs]].hsh!=T[r].hsh)
				bad[idx]=true;
			else{
				cl[idx] = cl[ls];
				op[idx] = merge(l,op[rs]);
				bad[idx]=false;
			}
		}
		else{
			int l,r;
			split(cl[rs],l,r,T[cl[rs]].sz-T[op[ls]].sz);
			if(T[op[ls]].hsh!=T[r].hsh)
				bad[idx]=true;
			else{
				cl[idx] = merge(l,cl[ls]);
				op[idx] = op[rs];
				bad[idx]=false;
			}
		}
	}
	void build(int idx,int l,int r){
		if(l==r){
			cl[idx] = op[idx] = 0;
			if(a[l]>0)
				op[idx] = newnode(a[l]);
			else
				cl[idx] = newnode(-a[l]);
			return;
		}
		int mid = (l+r)>>1;
		build(ls,l,mid),build(rs,mid+1,r);
		pull(idx);
	}
	void modify(int idx,int l,int r,int pos,int val){
		if(l==r){
			cl[idx] = op[idx] = 0;
			if(val>0)
				op[idx] = newnode(val);
			else
				cl[idx] = newnode(-val);
			return;
		}
		int mid = (l+r)>>1;
		if(pos<=mid)
			modify(ls,l,mid,pos,val);
		else
			modify(rs,mid+1,r,pos,val);
		pull(idx);
	}
	bool query(int idx,int l,int r,int L,int R,int &CL,int &OP){
		if(L<=l&&r<=R){
			return CL=cl[idx],OP=op[idx],bad[idx];
		}
		if(L>r||l>R)
			return CL=OP=0,false;
		int mid = (l+r)>>1;
		int lCL,rCL,lOP,rOP;
		bool faill = query(ls,l,mid,L,R,lCL,lOP);
		bool failr = query(rs,mid+1,r,L,R,rCL,rOP);
		if(faill||failr)	return true;
		if(T[lOP].sz >= T[rCL].sz){
			int l,r;
			split(lOP,l,r,T[lOP].sz-T[rCL].sz);
			if(T[rCL].hsh!=T[r].hsh)
				return true;
			else{
				CL = lCL;
				OP = merge(l,rOP);
				return false;
			}
		}
		else{
			int l,r;
			split(rCL,l,r,T[rCL].sz-T[lOP].sz);
			if(T[lOP].hsh!=T[r].hsh)
				return true;
			else{
				CL = merge(l,lCL);
				OP = rOP;
				return false;
			}
		}
	}
}ST;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	mult[0]={1,1};
	for(int i=1;i<maxn;i++)
		mult[i] = {1LL*mult[i-1].first*base[0]%mod[0],1LL*mult[i-1].second*base[1]%mod[1]};
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ST.build(1,1,n);
	int q;
	cin>>q;
	while(q--){
		int op, l, r;
		cin>>op>>l>>r;
		if(op==1)
			ST.modify(1,1,n,l,r), a[l]=r;
		else{
			int cursz = stp;
			int CL,OP;
			bool fail = ST.query(1,1,n,l,r,CL,OP);
			if(fail || T[CL].hsh != NUL || T[OP].hsh != NUL)
				cout<<"No\n";
			else
				cout<<"Yes\n";
			stp = cursz;
		}
		if(stp>=7e6)
			stp=0,ST.build(1,1,n);
	}
}