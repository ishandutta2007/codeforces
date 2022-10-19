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

int main(){
	static int n,m,q;
	static int p[200010];
	static int a[200010];
	static int l[200010],r[200010];
	scanf("%d%d%d",&n,&m,&q);
	rep1(i,n)scanf("%d",&p[i]);
	rep1(i,m)scanf("%d",&a[i]);
	rep1(i,q)scanf("%d%d",&l[i],&r[i]);
	
	static int t[200010];
	rep1(i,n-1)t[p[i]] = p[i+1];
	t[p[n]] = p[1];
	
	//rep1(i,n)cout << t[i] << " ";
	//cout << endl;
	
	static int nex[200010][20];
	static int pre[200010];
	rep(i,200010)pre[i] = m+1;
	rrep1(i,m){
		nex[i][0] = pre[t[a[i]]];
		pre[a[i]] = i;
	}
	nex[m+1][0] = m+1;
	
	//rep1(i,m)cout << nex[i][0] << " ";
	//cout << endl;
	
	rep1(j,19)rep1(i,m+1)nex[i][j] = nex[nex[i][j-1]][j-1];
	
	static int R[200010];
	rep1(i,m){
		int _n = n-1;
		R[i] = i;
		rrep(j,20){
			if(_n >= (1<<j)){
				R[i] = nex[R[i]][j];
				_n -= 1<<j;
			}
		}
	}
	
	/*rep1(i,m){
		cout << R[i] << " ";
	}
	cout << endl;*/
	
	static int ret[200010];
	vector<P1> vec;
	rep1(i,q){
		vec.pb(mp1(l[i],r[i],i));
	}
	sor(vec);
	int loc = m+1;
	int _R = m+1;
	rrep(i,vec.size()){
		while(loc > vec[i].fr){
			_R = min( _R , R[loc-1] );
			loc --;
		}
		if(_R <= vec[i].sc.fr)ret[vec[i].sc.sc] = 1;
		else ret[vec[i].sc.sc] = 0;
	}
	
	rep1(i,q){
		printf("%d",ret[i]);
	}
	printf("\n");
	return 0;
}