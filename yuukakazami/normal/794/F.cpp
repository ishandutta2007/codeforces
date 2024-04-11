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

const int MAX_N = int(1e5) + 10;

int n,q;
int a[MAX_N];

struct Tree{
    int l,r;
    Tree*pl,*pr;

    int perm[10]; // x-> y

	ll sum[10]; // sums of all digits with i
	ll ret;

	bool is_id(){
		rep(i,0,10) if(perm[i] != i) return 0;
		return 1;
	}

	void calc_ret(){
		ret = 0;
		rep(i,0,10)
			ret += sum[i] * perm[i];
	}

	void applyChange(int new_perm[]){
		int tmp[10];
		rep(i,0,10)
			tmp[i] = new_perm[perm[i]];
		rep(i,0,10) perm[i] = tmp[i];
		calc_ret();
	}

    void relax(){
    	pl->applyChange(perm);
    	pr->applyChange(perm);
    	//reset perm
    	ll nsum[10] = {};

    	rep(i,0,10){
    		nsum[perm[i]] += sum[i];
    	}

    	rep(i,0,10) sum[i] = nsum[i], perm[i] = i;
    }
    
    void update(){
    	assert(is_id());
    	memset(sum,0,sizeof sum);
    	rep(i,0,10){
    		sum[pl->perm[i]] += pl->sum[i];
    		sum[pr->perm[i]] += pr->sum[i];
    	}
    	calc_ret();
    }

    void init_sum(int a){
		int ds[20];
		int cnt = 0;
		while(a)
			ds[cnt++]=a%10,a/=10;

		memset(sum,0,sizeof sum);

		int pw = 1;
		rep(i,0,cnt){
			sum[ds[i]] += pw;
			pw *= 10;
		}
    }
    
    Tree(int l,int r):l(l),r(r) {
    	rep(i,0,10) perm[i] = i; 

        if(l+1==r){
            init_sum(a[l]);
            return;
        }

        pl=new Tree(l,(l+r)/2);
        pr=new Tree((l+r)/2,r);
        update();
    } 
    
    void apply(int L,int R,int perm[]){
        if(L>=r||l>=R)
            return;
        if(L<=l&&R>=r){
            applyChange(perm);
            return;
        }
        relax();
        pl->apply(L,R,perm);
        pr->apply(L,R,perm);
        update();
    }

    ll get(int L,int R){
    	if(L >= R) return 0;
        if(L>=r||l>=R)
            return 0;
        if(L<=l&&R>=r){
            return ret;
        }
        relax();
        return pl->get(L,R) + pr->get(L,R);
    }
}*root;

int main(){
	cin>>n>>q;
	rep(i,0,n){
		scanf("%d",a+i);
	}
	root = new Tree(0,n);

	rep(_,0,q){
		int cmd,l,r,x,y;
		scanf("%d",&cmd);
		if(cmd == 1){
			scanf("%d%d%d%d",&l,&r,&x,&y);
			--l;
			int perm[10]; rep(i,0,10) perm[i] = i;
			perm[x] = y;
			root->apply(l,r,perm);
		} else {
			scanf("%d%d",&l,&r);
			--l;
			ll ret = root->get(l,r);
			printf("%lld\n",ret);
		}
	}
	return 0;
}