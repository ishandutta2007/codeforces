#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)

int n, m;
char bra[1000010];

struct Bra{
	int l, r, b;
	Bra(){}
	Bra(int x,int y,int z):l(x),r(y),b(z){}
};

typedef Bra SegT;
const SegT defvalue(0, 0, 0);
class SegTree{
	private:
		vector<SegT> val;
		int n;
		
		SegT combine(SegT a, SegT b){
			SegT ret;
			ret.l = a.l + b.l;
			ret.r = a.r + b.r;
			ret.b = a.b + b.b + min(a.l - a.b, b.r - b.b);
			return ret;
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
				if(n-1 <= i) val.at(i) = in.at(i - (n-1));
				else val[i] = combine(val[i*2+1],val[i*2+2]);
			}
		}
		//a<=x<b
		SegT query(int a,int b,int k=0,int l=0,int r=-1){
			if(r==-1)r=n;
			if(r<=a||b<=l) return defvalue;
			if(a<=l&&r<=b){
				return val[k];
			}else{
				return combine(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
			}
		}
};

main(){
	scanf("%s ", bra);
	vector<Bra> B(strlen(bra), Bra(0, 0, 0));
	for(n=0;bra[n];n++){
		if(bra[n] == '(') B[n].l = 1;
		else if(bra[n] == ')') B[n].r = 1;
	}
	SegTree seg(B);
	scanf("%d ", &m);
	while(m --){
		int ql, qr;
		scanf("%d %d", &ql, &qr);
		printf("%d\n", seg.query(ql - 1, qr).b * 2);
	}
	return 0;
}