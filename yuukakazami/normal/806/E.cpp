#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int MAX_N = int(5e5) + 10;

int go(int x,int a){
	if(x==a) return x;
	return x < a ? x + 1 : x - 1;
}

int n;
int a[MAX_N];

pair<int,int> key[MAX_N];

pair<int,int> vals[MAX_N];

const int INF = ~0U>>2;

struct Tree{
    int l,r;
    Tree*pl,*pr;

    int mi;
    int add;
    int cnt;

    void applyAdd(int a){
    	add += a;
    	mi += a;
    }

    void relax(){
    	if(add != 0){
    		pl->applyAdd(add);
    		pr->applyAdd(add);
    		add = 0;
    	}
    }
    
    void update(){
    	mi = min(pl->mi,pr->mi);
    	cnt = pl->cnt + pr->cnt;
    }
    
    Tree(int l,int r):l(l),r(r) {
        if(l+1==r){
        	add = 0;
            pl = pr =0;
            mi = INF;
            cnt = 0;
            return;
        }
        add = 0;
        pl=new Tree(l,(l+r)/2);
        pr=new Tree((l+r)/2,r);
        update();
    } 
    
    void apply(int L,int R,int a){
        if(L>=r||l>=R)
            return;
        if(L<=l&&R>=r){
            applyAdd(a);
            return;
        }
        relax();
        pl->apply(L,R,a);
        pr->apply(L,R,a);
        update();
    }

    void set(int i,int val){
    	if(i < l || i >= r) return;
    	if(l + 1 == r){
    		add = 0;
    		cnt = 1;
    		mi = val;
    		return;
    	}
    	relax();
    	pl->set(i,val);pr->set(i,val);
    	update();
    	return;
    }

    int get(int L,int R){
    	if(L >= R) return 0;
        if(L>=r||l>=R)
            return 0;
        if(L<=l&&R>=r){
            return cnt;
        }
        relax();
        return pl->get(L,R) + pr->get(L,R);
    }

    int get(int x){ // find last one smaller than x
    	if(l + 1 == r){
    		return l;
    	}
    	relax();
    	if(pr->mi < x)
    		return pr->get(x);
    	return pl->get(x);
    }

    vector<int> get_bf(int x){
    	if(l+1==r) {
    		if(mi < x) return {l};
    		return {};
    	}
    	relax();
    	auto ret = pr->get_bf(x);
    	if(!ret.empty()) return ret;
    	return pl->get_bf(x);
    }

    void print(){
    	if(l+1==r){
    		cout<<vals[l].se+1<<":"<<mi<<endl;
    		return;
    	}
    	relax();
    	pl->print();
    	pr->print();
    }
}*root;

multiset<int> S;

int simulate(int last){

	/*
	int cnt = 0;
	
	for(auto i = S.rbegin(); i != S.rend(); ++i){
		if(last - cnt <= *i){
			++cnt;
		} else break;
	}

	return last - cnt + (S.size() - cnt);
	*/

	if(root->mi >= last){
		return last - root->cnt;
	} else {
		int i = root->get(last);
		//x - i > a_i
		last -= root->get(i+1,n);
		return last + root->get(0,i+1);
	}
}

int main(){
	cin>>n; 

	rep(i,0,n) {
		scanf("%d",a+i);
		key[i] = mp(a[i],i);
		vals[i] = key[i];
	}

	sort(vals,vals+n);
	root = new Tree(0,n);

	int ans = 0;

	rep(i,0,n){
		int u = lower_bound(vals,vals+n,key[i]) - vals;
		//set u
		int cnt = root->get(u+1,n);
		//cout<<u<<":"<<key[i].fi + cnt<<endl;
		root->set(u,key[i].fi+cnt);
		root->apply(0,u,1);

		for(;;){
			int S = simulate(ans);
			if(S > 0) --ans;
			else {
				if(simulate(ans+1) <= 0)
					++ans;
				else
					break;
			}
		}

		printf("%d\n",ans);
		//printf("-----------------\n");
		//root->print();
	}
	return 0;
}