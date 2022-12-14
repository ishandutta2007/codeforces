#include<bits/stdc++.h>
using namespace std;

struct SEG{
	int l,r;
	mutable int v;
	SEG(int l=0,int r=0,int v=0):l(l),r(r),v(v){}
	bool operator<(const SEG& rhs)const{
		return l==rhs.l?r<rhs.r:l<rhs.l;
	}
};

set<SEG> st;
int n,q,tot;
void split(int x){
	if(x>n)	return ;
	auto it=st.lower_bound(SEG(x,-1,0));
	if(it!=st.end()&&it->l==x)
		return;
	it--;
	int l=it->l,r=it->r,v=it->v;
	st.erase(it);
	st.insert(SEG(l,x-1,v));
	st.insert(SEG(x,r,v));
}

void modify(int l,int r,int x){
	split(l);split(r+1);
	for(auto it=st.lower_bound(SEG(l,-1,0));;it++){
		if(it->v==0)	tot-=(it->r-it->l+1);
		if(it->r==r)	break;
	}
	st.erase(st.lower_bound(SEG(l,-1,0)),st.lower_bound(SEG(r+1,-1,0)));
	st.insert(SEG(l,r,x));
	if(x==0)	tot+=r-l+1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	int l,r,k;
	st.insert(SEG(1,n,1));
	while(q--){
		cin>>l>>r>>k;
		modify(l,r,k-1);
		cout<<n-tot<<'\n';
	}
}