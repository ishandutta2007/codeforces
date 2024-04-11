#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)

vector<bool> eratosthenes_sieve(int n){
	if(n<2)return vector<bool>();
	vector<bool> res(n+1);
	res[0]=res[1]=false;res[2]=true;
	int i,j,m=sqrt(n)+1e-9;
	for(i=3;i<=n;i+=2){
		if(i<=m){
			if(res[i]==false){
				for(j=i+i+i;j<=n;j+=i+i){
					res[j]=true;
				}
			}
		}
		res[i]=!res[i];
	}
	return res;
}
vector<int> prime_list(const vector<bool>& isprime){
	vector<int> res;if(isprime.size()<=2)return res;
	res.push_back(2);
	for(unsigned int i=3;i<isprime.size();i+=2)
		if(isprime[i])res.push_back(i);
	return res;
}
vector<int> prime_list(int n){
	return prime_list(eratosthenes_sieve(n));
}

// _XV NG

pii defvalue(1000000, -1);
class SegTree{
	typedef pii SegT;
	private:
		vector<SegT> val;
		int n;
		
		inline SegT combine(SegT a, SegT b){
			return min(a, b);
		}
		
	public:
		SegTree(int size){
			n=1;
			while(n<size)n<<=1;
			val=vector<SegT>(2*n, defvalue);
		}
		SegTree(const vector<SegT> &in){
			n=1;
			while(n<in.size())n<<=1;
			val=vector<SegT>(2*n, defvalue);
			for(int i=n-1 + in.size()-1;i>=0;i--){
				if(n-1 <= i) val[i] = in[i - (n-1)];
				else val[i] = min(val[i*2+1],val[i*2+2]);
			}
		}
		//i vf a XV
		void update(int i,SegT a){
			i+=n-1;
			val[i]=a;
			while(i>0){
				i=(i-1)/2;
				val[i]=min(val[i*2+1],val[i*2+2]);
			}
		}
		//[a, b) l
		SegT query(int a,int b,int k=0,int l=0,int r=-1){
			if(r==-1)r=n;
			if(r<=a||b<=l) return defvalue;
			if(a<=l&&r<=b){
				return val[k];
			}else{
				return combine(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
			}
		}
		void swap(int x, int y){
			int t = val[x+n-1].first;
			update(x, pii(val[y+n-1].first, x));
			update(y, pii(t, y));
		}
};


vector<int> pl;
vector<bool> ps;
int plis[100001];
vector<pii> in;
int n;
main(){
	scanf("%d", &n);
	ps = eratosthenes_sieve(n);
	pl = prime_list(ps);
	for(int i=2;i<=n;i++){
		int mp = *(upper_bound(pl.begin(), pl.end(), i)-1);
		plis[i] = mp;
	}
	
	REP(i, n){
		int x;
		scanf("%d", &x);
		in.push_back(pii(x, i));
	}
	
	SegTree seg(in);
	vector<pii> ans;
	REP(i, n){
		int src = seg.query(i, n).second;
		while(i < src){
//			printf("%d %d\n", i, src);
			int tar = plis[src-i+1];
//			printf("plis[%d] = %d\n", src-i+1, tar);
			seg.swap(src, src-tar+1);
			ans.push_back(pii(src, src-tar+1));
			src = src - tar + 1;
		}
//		printf("%d %d %d\n", seg.query(0, 1), seg.query(1, 2), seg.query(2, 3));
	}
	printf("%d\n", (int)ans.size());
	REP(i, ans.size()) printf("%d %d\n", ans[i].second+1, ans[i].first+1);
	return 0;
}