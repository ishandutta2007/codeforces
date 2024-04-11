#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

const ll MOD=998244353;

struct SEG{
	int sz=1<<19;
	int s[(1<<20)+10];
	int t[(1<<20)+10];
	void init(){
		for(int i=0;i<sz*2-1;i++){
			s[i]=t[i]=0;
		}
	}
	void add(int a,int b,int x,int k,int l,int r){
		if(b<=l||r<=a)return;
		if(a<=l&&r<=b){
			s[k]+=x;
			t[k]+=x;
			return;
		}
		add(a,b,x,2*k+1,l,(l+r)/2);
		add(a,b,x,2*k+2,(l+r)/2,r);
		s[k]=max(s[2*k+1],s[2*k+2])+t[k];
	}
}seg;

int main(){
	static int n;
	static int p[300010];
	static int q[300010];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)scanf("%d",&q[i]);
	
	static int inv_p[300010];
	for(int i=1;i<=n;i++){
		inv_p[p[i]]=i;
	}
	
	static int ans[300010];
	seg.init();
	int ret=n,rem=0;
	while(rem<n){
		int loc=inv_p[ret];
		seg.add(1,loc+1,1,0,0,seg.sz);
		while(seg.s[0]>0){
			ans[rem]=ret;
			rem++;
			seg.add(1,q[rem]+1,-1,0,0,seg.sz);
		}
		ret--;
	}
	for(int i=0;i<n;i++){
		printf("%d%c",ans[i],(i+1==n)?'\n':' ');
	}
}