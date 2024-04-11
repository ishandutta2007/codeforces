#include<bits/stdc++.h>
using namespace std;

const int MN = 4000100;

int ma[MN],mi[MN],tag[MN];

void push(int idx){
	int lson=idx<<1,rson=idx<<1|1;
	if(tag[idx]){
		tag[lson]+=tag[idx];
		tag[rson]+=tag[idx];
		tag[idx]=0;
	}
}

void pull(int idx){
	int lson=idx<<1,rson=idx<<1|1;
	ma[idx]=max(ma[lson]+tag[lson],ma[rson]+tag[rson]);
	mi[idx]=min(mi[lson]+tag[lson],mi[rson]+tag[rson]);
}


void modify(int idx,int l,int r,int L,int R,int v){
	if(L>r||R<l)	return;
	if(L<=l&&r<=R){
		tag[idx]+=v;
		return;
	}
	int mid=(l+r)>>1;
	push(idx);
	modify(idx<<1,l,mid,L,R,v);modify(idx<<1|1,mid+1,r,L,R,v);
	pull(idx);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	int m=0;
	int p=0;
	for(int i=0;i<n;i++){
		if(s[i]=='R')
			p++;
		else if(s[i]=='L')
			p=max(p-1,0);
		m=max(p,m);
	}
	int last=0;
	vector<char> v(m+1,0);
	p=0;
	for(int i=0;i<n;i++){
		if(s[i]=='R')
			p++;
		else if(s[i]=='L')
			p=max(p-1,0);
		else{
			if(v[p]=='(')
				modify(1,0,m,p,m,-1),last--;
			if(v[p]==')')
				modify(1,0,m,p,m,1),last++;
			v[p]=s[i];
			if(v[p]=='(')
				modify(1,0,m,p,m,1),last++;
			if(v[p]==')')
				modify(1,0,m,p,m,-1),last--;
		}
		int MA=ma[1]+tag[1],MI=mi[1]+tag[1];
		if(last||MI<0)
			cout<<-1<<' ';
		else
			cout<<MA<<' ';
	}
	cout<<endl;
}