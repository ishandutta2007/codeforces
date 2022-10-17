#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define rep(i,x) for(int i=0;i<x;i++)
#define rep1(i,x) for(int i=1;i<=x;i++)
#define rrep(i,x) for(int i=x-1;i>=0;i--)
#define rrep1(i,x) for(int i=x;i>0;i--)
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
#define mp1(a,b,c) P1(a,P(b,c))

const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
const ll INF = 1000000000000000000;

struct SEG{
	int siz = 1<<19;
	ll s[1<<20];
	ll t[1<<20];
	void init(){
		rep(i,2*siz-1){
			s[i] = 0;
			t[i] = 0;
		}
	}
	void add(int a,int b,ll x,int k,int l,int r){
		if(b <= l || r <= a)return;
		if(a <= l && r <= b){
			s[k] += x;
			t[k] += x;
			return;
		}
		add(a,b,x,2*k+1,l,(l+r)/2);
		add(a,b,x,2*k+2,(l+r)/2,r);
		s[k] = min( s[2*k+1] , s[2*k+2] ) + t[k];
	}
	ll query(int a,int b,int k,int l,int r){
		if(b <= l || r <= a)return INF;
		if(a <= l && r <= b)return s[k];
		ll chl = query(a,b,2*k+1,l,(l+r)/2);
		ll chr = query(a,b,2*k+2,(l+r)/2,r);
		return min( chl , chr ) + t[k];
	}
}seg;

int main(){
	static int n,q;
	static int p[500010];
	static ll w[500010];
	static int v[500010],l[500010],r[500010];
	scanf("%d%d",&n,&q);
	for(int i = 2 ; i <= n ; i ++){
		scanf("%d%lld",&p[i],&w[i]);
	}
	rep(i,q)scanf("%d%d%d",&v[i],&l[i],&r[i]);
	
	static int R[500010];
	rep1(i,n)R[i] = i;
	for(int i = n ; i >= 2 ; --i){
		R[p[i]] = max( R[p[i]] , R[i] );
	}
	
	seg.init();
	static int cnt[500010] = {};
	rep1(i,n){
		cnt[p[i]] ++;
	}
	static ll d[500010];
	d[1] = 0;
	seg.add(1,2,INF,0,0,seg.siz);
	for(int i = 2 ; i <= n ; i ++){
		d[i] = d[p[i]] + w[i];
		seg.add(i,i+1,cnt[i]==0?d[i]:INF,0,0,seg.siz);
	}
	
	static vector<P2> Que;
	rep(i,q)Que.pb(P2(P(v[i],i),P(l[i],r[i])));
	sor(Que);
	
	static ll ans[500010];
	int k = 0;
	rep1(i,n){
		/*puts("========");
		cout << i << ":" << endl;
		rep1(i,6){
			cout << seg.query(i,i+1,0,0,seg.siz) << endl;
		}*/
		
		while(k < Que.size() && Que[k].fr.fr == i){
			ans[Que[k].fr.sc] = seg.query(Que[k].sc.fr,Que[k].sc.sc+1,0,0,seg.siz);
			k ++;
		}
		if(i == n)break;
		int loc = i;
		while(loc != p[i+1]){
			seg.add(0,seg.siz,-w[loc],0,0,seg.siz);
			seg.add(loc,R[loc]+1,2*w[loc],0,0,seg.siz);
			loc = p[loc];
		}
		seg.add(0,seg.siz,w[i+1],0,0,seg.siz);
		seg.add(i+1,R[i+1]+1,-2*w[i+1],0,0,seg.siz);
	}
	
	rep(i,q){
		printf("%lld\n",ans[i]);
	}
}