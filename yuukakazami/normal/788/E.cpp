#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n)-1;i>=(a);i--)

const int MAX_N = int(1e5 + 10);
const int mod = 1000000007;

void add(int&x,int c){ x+=c; if(x>=mod) x-=mod; }

int a[MAX_N],n,m;

template<class T>
struct Index: public vector<T> {
    using vector<T>::erase;
    using vector<T>::begin;
    using vector<T>::end;
    void doit() {
        sort(begin(), end());
        erase(unique(begin(), end()), end());
    }
    int get(T x) {
        return lower_bound(begin(), end(), x) - begin();
    }
};

Index<int> idx;

struct Tree {
	Tree*pl, *pr;
	int l, r;

	int ret;
	int sumLd,sumL;
	int sumRd,sumR;
	int cnt;

	void setLeaf(int L,int R){
		ret = sumL = sumLd = sumR = sumRd = cnt = 0;
		if(L==-1){
			return;
		}
		sumL = L;
		sumR = R;
		cnt = 1;
	}

	void update() {
		ret = (1LL * pl->sumLd * pr->sumR + 1LL * pr->sumRd * pl->sumL + pl->ret + pr->ret ) % mod;
		sumL = (pl->sumL + pr->sumL) % mod;
		sumR = (pl->sumR + pr->sumR) % mod;
		sumLd = (pl->sumLd + 1LL * pl->sumL * pr->cnt + pr->sumLd) % mod;
		sumRd = (pr->sumRd + 1LL * pr->sumR * pl->cnt + pl->sumRd) % mod;
		cnt = pl->cnt + pr->cnt;
	}

	Tree(int l, int r, vector<int>&L,vector<int>&R) :
			l(l), r(r) {
		if (l + 1 == r) {
			setLeaf(L[l],R[l]);
			return;
		}
		pl = new Tree(l, l + r >> 1, L, R);
		pr = new Tree(l + r >> 1, r, L, R);
		update();
	}

	void change(int i,int L,int R) {
		if(i<l||i>=r) return;
		if(l + 1 == r){
			setLeaf(L,R);
			return;
		}
		pl->change(i,L,R);
		pr->change(i,L,R);
		update();
	}
};


Tree* tr[MAX_N];

int L[MAX_N],R[MAX_N];

struct TA{
	int a[MAX_N],n;

	void init(int _n){
		n=_n;
		memset(a,0,sizeof(int)*n);
	}

	void add(int p,int x){
		for(p++;p<=n;p+=p&-p)
			a[p-1] += x;
	}

	int get(int p){
		int r = 0;
		for(p++;p;p-=p&-p)
			r += a[p-1];
		return r;
	}
}ta;

vector<int> pos[MAX_N];

int posInData[MAX_N];
 
int main(){
	cin>>n;
	rep(i,0,n){
		scanf("%d",a+i);
		idx.push_back(a[i]);
	}
	idx.doit();
	rep(i,0,n){
		a[i] = idx.get(a[i]);
	}
	cin>>m;

	ta.init(idx.size());
	rep(i,0,n){
		L[i] = ta.get(a[i]);
		ta.add(a[i],1);
	}
	ta.init(idx.size());
	per(i,0,n){
		R[i] = ta.get(a[i]);
		ta.add(a[i],1);
	}

	rep(i,0,n){
		posInData[i] = pos[a[i]].size();
		pos[a[i]].push_back(i);
	}

	rep(i,0,idx.size()){
		vector<int> L,R;
		for(auto e:pos[i]) L.push_back(::L[e]), R.push_back(::R[e]);
		tr[i] = new Tree(0, pos[i].size(), L, R);
	}

	int ans = 0;

	rep(i,0,idx.size()) add(ans,tr[i]->ret);
	//cout<<"C:"<<ans<<endl;
 
	rep(i,0,m){
		int t,x;
		scanf("%d%d",&t,&x);--x;

		Tree*tr = ::tr[a[x]];

		add(ans,mod-tr->ret);

		if(t==1)
			tr->change(posInData[x],-1,-1);
		else
			tr->change(posInData[x],L[x],R[x]);

		add(ans,tr->ret);

		printf("%d\n",ans);
	}
	return 0;
}