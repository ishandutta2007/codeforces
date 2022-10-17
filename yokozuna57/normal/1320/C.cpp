#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;

#define fr first
#define sc second
#define mp1(a,b,c) P1(a,P(b,c))
#define mp2(a,b,c,d) P2(P(a,b),P(c,d))

const ll INF = 1000000000000000000;

struct SEG{
	int siz = 1<<20;
	ll s[1<<21],t[1<<21];
	void init(){
		for(int i = 0 ; i < siz*2-1 ; i ++){
			s[i] = -INF;
			t[i] = 0;
		}
	}
	void add(int a,int b,ll x,int k,int l,int r){
		if(b <= l || r <= a)return;
		if(a <= l && r <= b){
			t[k] += x;
			return;
		}
		add(a,b,x,2*k+1,l,(l+r)/2);
		add(a,b,x,2*k+2,(l+r)/2,r);
		s[k] = max( s[2*k+1]+t[2*k+1] , s[2*k+2]+t[2*k+2] );
	}
	void chmax(int a, ll x){
		int b = a+siz-1;
		x -= t[b];
		while(b > 0){
			b = (b-1)/2;
			x -= t[b];
		}
		a += siz-1;
		s[a] = max( s[a] , x );
		while(a > 0){
			x += t[a];
			a = (a-1)/2;
			s[a] = max( s[a] , x );
		}
	}
	ll query(int a,int b,int k,int l,int r){
		if(b <= l || r <= a)return -INF;
		if(a <= l && r <= b)return s[k]+t[k];
		ll chl = query(a,b,2*k+1,l,(l+r)/2);
		ll chr = query(a,b,2*k+2,(l+r)/2,r);
		return max(chl,chr)+t[k];
	}
}seg;

int main(){
	static int n,m,p;
	static int a[200010],c[200010];
	static int b[200010],d[200010];
	static int x[200010],y[200010],z[200010];
	scanf("%d%d%d",&n,&m,&p);
	for(int i = 0 ; i < n ; i ++){
		scanf("%d%d",&a[i],&c[i]);
	}
	for(int i = 0 ; i < m ; i ++){
		scanf("%d%d",&b[i],&d[i]);
	}
	for(int i = 0 ; i < p ; i ++){
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
	}
	
	seg.init();
	vector<P2> QUERY;
	for(int i = 0 ; i < n ; i ++){
		QUERY.push_back(mp2(a[i],0,c[i],0));
	}
	for(int i = 0 ; i < m ; i ++){
		seg.chmax(b[i],-d[i]);
	}
	for(int i = 0 ; i < p ; i ++){
		QUERY.push_back(mp2(x[i],1,y[i],z[i]));
	}
	sort(QUERY.begin(),QUERY.end());
	
	ll ret = -INF;
	for(P2 q: QUERY){
		if(q.fr.sc == 0){
			ret = max( ret , seg.s[0]+seg.t[0]-q.sc.fr );
		}
		else {
			seg.add(q.sc.fr+1,seg.siz,q.sc.sc,0,0,seg.siz);
		}
		//cout << q.fr.fr << " " << q.fr.sc << " " << q.sc.fr << " " << q.sc.sc << endl;
		//cout << seg.query(2,3,0,0,seg.siz) << endl;
	}
	cout << ret << endl;
}