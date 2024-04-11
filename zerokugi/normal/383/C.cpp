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
const int INF = 1000000000;

typedef int SegT;
const int defvalue = 0;
class SegTree{
	private:
		vector<SegT> val;
		int n;
		
		SegT combine(SegT a, SegT b){
			return a + b;
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
			for(int i=n-1 + in.size()-1;n-1 <= i;i--){
				if(n-1 <= i) val[i] = in[i - (n-1)];
			}
		}		//i vf a XV
		SegT get(int i){
			i+=n-1;
			int ret = val[i];
			while(i>0){
				i=(i-1)/2;
				ret += val[i];
			}
			return ret;
		}
		//[a, b) x
		void query(int a,int b, int x,int k=0,int l=0,int r=-1){
			if(r==-1)r=n;
			if(r<=a||b<=l) return;
			if(a<=l&&r<=b){
				val[k] += x;
			}else{
				query(a,b,x,k*2+1,l,(l+r)/2);
				query(a,b,x,k*2+2,(l+r)/2,r);
			}
		}
};

struct Node{
	int ID;
	int posID;
	int depth;
	int l;
};
bool visited[200010] ={0};
int n,m;
int AllPosID = 0;
vector<Node> Tree;
vector< vector<int> > g;
int setNode(int s, int depth){
	if(visited[s]) return INF;
	visited[s] = true;
	Tree[s].depth = depth;
	int minl = INF;
	FOR(it, g[s]){
		minl = min(minl, setNode(*it, depth + 1));
	}
	Tree[s].posID = AllPosID ++;
	Tree[s].l = min(minl, Tree[s].posID);
	return Tree[s].l;
}

main(){
	scanf("%d %d", &n, &m);
	g = vector< vector<int> >(n);
	vector<int> a(n);
	REP(i, n){
		scanf("%d", &a[i]);
	}
	REP(i, n-1){
		int x,y;
		scanf("%d %d", &x, &y);
		g[x-1].push_back(y-1);
		g[y-1].push_back(x-1);
//		printf("%d->%d\n", x-1, y-1);
	}
	Tree = vector<Node>(n);
	REP(i, n) Tree[i].ID = i;
	setNode(0, 0);
//	REP(i, n){
//		printf("%d %d %d %d\n", Tree[i].ID, Tree[i].posID, Tree[i].l, Tree[i].depth);
//	}
	vector<int> b(n);
	REP(i, n){
		if(Tree[i].depth%2) b[Tree[i].posID] = -a[i];
		else b[Tree[i].posID] = a[i];
	}
//	REP(i, n){
//		cout << b[i] << " ";
//	}cout << endl;
	
	SegTree seg(b);
	REP(i, m){
		int t, x, val;
		scanf("%d ", &t);
		if(t == 1){
			scanf("%d %d", &x, &val);
			x--;
			seg.query(Tree[x].l, Tree[x].posID+1, val * (Tree[x].depth%2 ? -1 : 1));
//			printf("add [%d, %d): %d\n", Tree[x].l, Tree[x].posID+1, val * (Tree[x].depth%2 ? -1 : 1));
		}else{
			scanf("%d", &x);
			x--;
			cout << seg.get(Tree[x].posID) * (Tree[x].depth%2 ? -1 : 1) << endl;
//			printf("get(%d) = %d\n", Tree[x].posID, seg.get(Tree[x].posID) * (Tree[x].depth%2 ? -1 : 1));
		}
	}
	return 0;
}