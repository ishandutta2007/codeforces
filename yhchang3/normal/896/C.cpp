#include<bits/stdc++.h>
using namespace std;
int n,m,seed,vmax;

int rnd(){
	int res=seed;
	seed = (7LL*seed+13)%(1000000007);
	return res;
}
struct SEG{
	int l,r;
	mutable long long int v;
	SEG(int l=0,int r=0,long long int v=0):l(l),r(r),v(v){}
	bool operator<(const SEG& rhs)const{
		return l==rhs.l?r<rhs.r:l<rhs.l;
	}
};
set<SEG> st;
void split(int x){
	if(x>n)	return;
	auto it=st.lower_bound(SEG(x,-1,0));
	if(it!=st.end()&&it->l==x)
		return;
	it--;
	int l=it->l,r=it->r;
	long long int v=it->v;
	st.erase(it);
	st.insert(SEG(l,x-1,v));
	st.insert(SEG(x,r,v));
}
void add(int l,int r,int v){
	split(l);split(r+1);
	for(auto it=st.lower_bound(SEG(l,-1,0));;it++){
		it->v+=v;
		if(it->r==r)	break;
	}
}
void modify(int l,int r,int v){
	split(l);split(r+1);
	st.erase(st.lower_bound(SEG(l,-1,0)),st.lower_bound(SEG(r+1,-1,0)));
	st.insert(SEG(l,r,v));
}
long long int ksm(long long int x,int b,int mod){
	long long int res=1;
	while(b){
		if(b&1)	res=res*x%mod;
		x=x*x%mod;
		b>>=1;
	}
	return res;
}
long long int q3(int l,int r,int x){
	split(l);split(r+1);
	vector<pair<long long int,int> > v;
	for(auto it=st.lower_bound(SEG(l,-1,0));;it++){
		v.emplace_back(it->v,it->r-it->l+1);
		if(it->r==r)	break;
	}
	sort(v.begin(),v.end());
	for(auto it:v){
		x-=it.second;
		if(x<=0)	return it.first;
	}
	return -1;
}

int q4(int l,int r,int x,int mod){
	split(l);split(r+1);
	long long int res=0;
	for(auto it=st.lower_bound(SEG(l,-1,0));;it++){
		(res+=(it->r-it->l+1)*ksm((it->v)%mod,x,mod))%=mod;
		if(it->r==r)	break;
	}
	return (int) res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>seed>>vmax;
	for(int i=1;i<=n;i++)
		st.insert(SEG(i,i,rnd()%vmax+1));
	for(int i=1;i<=m;i++){
		int op=rnd()%4+1,l=rnd()%n+1,r=rnd()%n+1,x,y;
		if(l>r)	swap(l,r);
		if(op==3)
			x=rnd()%(r-l+1)+1;
		else
			x=rnd()%vmax+1;
		if(op==4)	y=rnd()%vmax+1;
		if(op==1)
			add(l,r,x);
		else if(op==2)
			modify(l,r,x);
		else if(op==3)
			cout<<q3(l,r,x)<<'\n';
		else
			cout<<q4(l,r,x,y)<<'\n';
	}

}