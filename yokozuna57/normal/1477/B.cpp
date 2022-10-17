#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

struct seg{
	int sz;
	vector<int> a;
	vector<int> b;
	void init(int n){
		sz=1;
		while(sz<n)sz<<=1;
		a.resize(sz*2-1);
		b.resize(sz*2-1);
	}
	void build(){
		for(int i=sz-2;i>=0;i--){
			a[i]=a[2*i+1]+a[2*i+2];
			b[i]=-1;
		}
	}
	void upd(int s,int t,int x,int k,int l,int r){
		//cerr<<s<<" "<<t<<" "<<x<<" "<<k<<" "<<l<<" "<<r<<endl;
		if(t<=l||r<=s)return;
		if(s<=l&&r<=t){
			b[k]=x;
			a[k]=x*(r-l);
			return;
		}
		if(b[k]!=-1){
			upd(l,r,b[k],2*k+1,l,(l+r)/2);
			upd(l,r,b[k],2*k+2,(l+r)/2,r);
			b[k]=-1;
		}
		upd(s,t,x,2*k+1,l,(l+r)/2);
		upd(s,t,x,2*k+2,(l+r)/2,r);
		a[k]=a[2*k+1]+a[2*k+2];
	}
	int sum(int s,int t,int k,int l,int r){
		//cerr<<s<<" "<<t<<" "<<k<<" "<<l<<" "<<r<<endl;
		if(t<=l||r<=s)return 0;
		if(s<=l&&r<=t)return a[k];
		if(b[k]!=-1){
			upd(l,r,b[k],2*k+1,l,(l+r)/2);
			upd(l,r,b[k],2*k+2,(l+r)/2,r);
			b[k]=-1;
		}
		int chl=sum(s,t,2*k+1,l,(l+r)/2);
		int chr=sum(s,t,2*k+2,(l+r)/2,r);
		return chl+chr;
	}
}seg;

int l_[200010],r_[200010];

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		//cerr<<T<<endl;
		int n,q;
		string s,t;
		scanf("%d%d",&n,&q);
		cin>>t>>s;
		seg.init(n);
		for(int i=0;i<seg.sz;i++){
			if(i<s.size())seg.a[i+seg.sz-1]=s[i]-'0';
			else seg.a[i+seg.sz-1]=0;
			seg.b[i+seg.sz-1]=-1;
		}
		seg.build();
		bool ok=true;
		for(int i=0;i<q;i++){
			scanf("%d%d",&l_[q-1-i],&r_[q-1-i]);
			l_[q-1-i]--;
			r_[q-1-i]--;
		}
		//cerr<<T<<endl;
		for(int i=0;i<q;i++){
			//cerr<<i<<endl;
			int l=l_[i],r=r_[i];
			//scanf("%d%d",&l,&r); l--; r--;
			int su=seg.sum(l,r+1,0,0,seg.sz);
			//cerr<<l<<" "<<r<<" "<<su<<endl;
			if(2*su==(r-l+1))ok=false;
			else if(2*su<r-l+1){
				seg.upd(l,r+1,0,0,0,seg.sz);
			}
			else {
				seg.upd(l,r+1,1,0,0,seg.sz);
			}
		}
		//cerr<<T<<endl;
		for(int i=0;i<n;i++){
			if(!ok)break;
			if((t[i]-'0')!=seg.sum(i,i+1,0,0,seg.sz))ok=false;
		}
		if(ok)puts("YES");
		else puts("NO");
	}
}