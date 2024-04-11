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
#include<bitset>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<int,P> P1;

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

const int INF=1000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

typedef bitset<7002> B;

void out(B b){
	for(int i = 30 ; i >= 0 ; i --){
		if(b[i])printf("1");
		else printf("0");
	}
	puts("");
}

int modcnt(B b){
	int t = 4096;
	while(t > 0){
		b ^= b>>t;
		t /= 2;
	}
	if(b[0])return 1;
	else return 0;
}

vector<int> div(ll n){
	vector<P> ret;
	for(int i = 2 ; i*i <= n ; i ++){
		if(n%i == 0){
			P p = P(i,0);
			while(n%i == 0){
				n /= i;
				p.sc ++;
			}
			ret.push_back(p);
		}
	}
	if(n > 1)ret.push_back(P(n,1));
	vector<int> divs;
	divs.push_back(1);
	for(P p: ret){
		vector<int> divs_;
		for(int x: divs){
			for(int i = 0 ; i <= p.sc ; i ++){
				divs_.push_back(x);
				x *= p.fr;
			}
		}
		divs = divs_;
	}
	return divs;
}

int main(){
	static B init[7002];
	static B mask[7002];
	static vector<int> D[7002];
	init[1].reset();
	init[1][1] = true;
	mask[1][0] = 0;
	mask[1][1] = 1;
	for(int i = 2 ; i < 7002 ; i ++){
		D[i] = div(i);
		mask[1][i] = 0;
		int cnt = 0;
		for(int j: D[i]){
			init[i][j] = true;
			if(mask[1][j])cnt ++;
		}
		mask[1][i] = cnt&1;
	}
	for(int i = 2 ; i <= 7000 ; i ++){
		mask[i].reset();
		for(int j = i ; j <= 7000 ; j += i){
			mask[i][j] = mask[1][j/i];
		}
	}
	//out(mask[1]);
	
	int n,q;
	scanf("%d%d",&n,&q);
	
	static B b[100010];
	rep(i,100010)b[i].reset();
	
	for(;q>0;--q){
		int t,x,y,z;
		scanf("%d%d%d",&t,&x,&y);
		if(t == 1){
			b[x] = init[y];
		}
		else if(t == 2){
			scanf("%d",&z);
			b[x] = b[y]^b[z];
		}
		else if(t == 3){
			scanf("%d",&z);
			b[x] = b[y]&b[z];
		}
		else if(t == 4){
			printf("%d",(b[x]&mask[y]).count()&1);
		}
		/*cout << 14-q << endl;
		out(b[1]);
		out(b[2]);
		out(b[3]);
		out(b[4]);
		puts("---------------");*/
	}
	printf("\n");
}