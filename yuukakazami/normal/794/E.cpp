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
const int MAX_N = int(3e5) + 10;

int n;
int a[MAX_N];

int even[MAX_N];
int odd[MAX_N];


struct Tree{
    int l,r;
    Tree*pl,*pr;
    int mx;

    void update(){
    	mx = max(pl->mx,pr->mx);
    }
    
    Tree(int l,int r,int seq[]):l(l),r(r) {
        if(l+1==r){
        	mx = seq[l];
            return;
        }

        pl=new Tree(l,(l+r)/2,seq);
        pr=new Tree((l+r)/2,r,seq);
        update();
    } 

    int get(int L,int R){
    	if(L >= R) return -1;
        if(L>=r||l>=R)
            return -1;
        if(L<=l&&R>=r){
            return mx;
        }
        return max(pl->get(L,R), pr->get(L,R));
    }
}*rodd,*reven;


int main(){
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",a+i);

	rep(i,0,n){
		if(i+1 < n)
			even[i] = max(a[i],a[i+1]);
		if(i > 0 && i + 1 < n)
			odd[i] = max(min(a[i-1],a[i]),min(a[i],a[i+1]));
	}
	rodd = new Tree(0,n,odd);
	reven = new Tree(0,n,even);

	rep(k,0,n){
		//remove k
		int len = n-k;
		//start in [0,k+1)
		//l, l + len/2
		int ans;
		if(len%2==0){//even
			ans = reven->get(len/2-1,k+1+len/2-1);
		} else {//odd
			if(len == 1){
				ans = *max_element(a,a+n);
			} else {
				ans = rodd->get(len/2,k+1+len/2);
			}
		}
		printf("%d ",ans);
	}
	puts("");
	return 0;
}