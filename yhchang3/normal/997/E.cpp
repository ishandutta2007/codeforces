#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 120001;
int stmn[N],stmx[N],st[N],a[N],tp,tpmn,tpmx;
vector<pair<int,int> > q[120001];
ll ans[120001];
#define ls idx<<1
#define rs idx<<1|1
struct SEG{
	int val[480010],tag[480010],cnt[480010],t[480010];
	ll res[480010];
	void push(int idx){
		val[ls]+=tag[idx];
		val[rs]+=tag[idx];
		tag[ls]+=tag[idx];
		tag[rs]+=tag[idx];
		tag[idx]=0;
		if(val[ls]==val[idx])
			t[ls]+=t[idx],res[ls]+=(ll)cnt[ls]*t[idx];
		if(val[rs]==val[idx])
			t[rs]+=t[idx],res[rs]+=(ll)cnt[rs]*t[idx];
		t[idx]=0;
	}
	void pull(int idx){
		val[idx]=min(val[ls],val[rs]);
		res[idx]=res[ls]+res[rs];
		cnt[idx]=(val[idx]==val[ls]?cnt[ls]:0)+(val[idx]==val[rs]?cnt[rs]:0);
	}
	void build(int idx,int l,int r){
		if(l==r){
			val[idx]=l,cnt[idx]=1;
			return;
		}
		int mid=(l+r)>>1;
		build(ls,l,mid);build(rs,mid+1,r);
		pull(idx);
	}
	void upd(int idx,int l,int r,const int& L,const int& R,int v){
		if(r<L||R<l)	return;
		if(L<=l&&r<=R){
			tag[idx]+=v;
			val[idx]+=v;
			return;
		}
		int mid=(l+r)>>1;
		push(idx);
		upd(ls,l,mid,L,R,v);
		upd(rs,mid+1,r,L,R,v);
		pull(idx);
	}
	void updt(int idx,int l,int r,const int& L,const int& R,int v){
		if(r<L||R<l)	return;
		if(L<=l&&r<=R){
			if(val[idx]!=0)	return;
			t[idx]+=v;
			res[idx]+=(ll)cnt[idx]*v;
			return;
		}
		int mid=(l+r)>>1;
		push(idx);
		updt(ls,l,mid,L,R,v);updt(rs,mid+1,r,L,R,v);
		pull(idx);
	}
	ll query(int idx,int l,int r,const int& L,const int& R){
		if(r<L||R<l)	return 0;
		if(L<=l&&r<=R)	return res[idx];
		int mid=(l+r)>>1;
		push(idx);
		ll ret=query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R);
		pull(idx);
		return ret;
	}
}T;
void build(int n){
	T.build(1,1,n);
	for(int i=1;i<=n;i++){
		T.upd(1,1,n,1,n,-1);
		while(tpmn&&a[i]<a[stmn[tpmn]])
			T.upd(1,1,n,stmn[tpmn-1]+1,stmn[tpmn],a[stmn[tpmn]]),tpmn--;
		while(tpmx&&a[i]>a[stmx[tpmx]])
			T.upd(1,1,n,stmx[tpmx-1]+1,stmx[tpmx],-a[stmx[tpmx]]),tpmx--;
		T.upd(1,1,n,stmn[tpmn]+1,i,-a[i]),stmn[++tpmn]=i;
		T.upd(1,1,n,stmx[tpmx]+1,i,a[i]),stmx[++tpmx]=i;
		T.updt(1,1,n,1,i,1);
		for(auto &[l,id]:q[i])
			ans[id]=T.query(1,1,n,l,i);
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int Q;
	cin>>Q;
	for(int i=1,l,r;i<=Q;i++){
		cin>>l>>r;
		q[r].emplace_back(l,i);
	}
	build(n);
	for(int i=1;i<=Q;i++)
		cout<<ans[i]<<'\n';
}