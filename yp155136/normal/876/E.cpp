#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <ctime>
using namespace std;

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct SCC {
	static const int MAX_N = 2e5 +6;
	vector<int> edg[MAX_N];
	vector<int> rev_edg[MAX_N];
	int n;
	void init(int _n) {
		n=_n;

		for(int i=0;n>=i;i++){
			edg[i].clear();
			rev_edg[i].clear();
		}
	}
	void add_edge(int from,int to) {
		edg[from].push_back(to);
		rev_edg[to].push_back(from);
	}
	bool visit[MAX_N];
	int get_stamp[MAX_N];
	int in_scc[MAX_N];
	int stamp;
	void dfs1(int id) {
		visit[id]=1;
		for (int i:rev_edg[id]) {
			if (!visit[i]) dfs1(i);
		}
		get_stamp[++stamp] = id;
	}
	void dfs2(int id,int scc) {
		visit[id]=1;
		for (int i:edg[id]) {
			if (!visit[i]) dfs2(i,scc);
		}
		in_scc[id] = scc;
	}
	void make_scc() {
		memset(visit,0,sizeof(visit));
		stamp=0;
		for (int i=1;n>=i;i++) {
			if (!visit[i]) dfs1(i);
		}
		memset(visit,0,sizeof(visit));
		int scc=0;
		for (int i=n;i>=1;i--) {
			if (!visit[get_stamp[i]]) {
				dfs2(get_stamp[i],++scc);
			}
		}
	}
	bool judge() {
		make_scc();
		for (int i=1;n/2>=i;i++) {
			if (in_scc[i] == in_scc[i+n/2]) return false;
		}
		return true;
	}
	/*
	not a-->a+N or f(a,n)
	*/
} scc;

int f(int x,int n) {
	if (x>0) return x;
	else return -x+n;
}

const int MAX_N = 1e5 + 6;
const int INF = 1e9 + 7;
vector<int> v[MAX_N];

#define SZ(x) ((int)(x).size())

int main () {
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1;n>=i;i++) {
        int x;
        scanf("%d",&x);
        v[i].push_back(0);
        while (x--) {
            int y;
            scanf("%d",&y);
            v[i].push_back(y);
        }
        v[i].push_back(-INF);
    }
    scc.init(2*m);
    for (int i=1;n-1>=i;i++) {
        if (v[i] == v[i+1]) continue;
        int a=0,b=0;
        for (int j=1;min(SZ(v[i]),SZ(v[i+1]))>j;j++) {
            if (v[i][j] == -INF) break;
            if (v[i+1][j] == -INF) {
                puts("No");
                return 0;
            }
            else if (v[i][j] != v[i+1][j]) {
                a=v[i][j];
                b=v[i+1][j];
                break;
            }
        }
        if (!a && !b) continue;
        if (a<b) {
            scc.add_edge(f(-b,m),f(-a,m));
            scc.add_edge(f(a,m),f(b,m));
            //b --> a
            //not a --> not b
        }
        else {
            scc.add_edge(f(a,m),f(-a,m));
            //a must yes
            //not a --> a
            //b must no
            //b --> not b
            scc.add_edge(f(-b,m),f(b,m));
        }
    }
    bool ret=scc.judge();
    if (!ret) puts("No");
    else {
        puts("Yes");
        vector<int> ans;
        for (int i=1;m>=i;i++) {
            if (scc.in_scc[f(i,m)] > scc.in_scc[f(-i,m)]) {
                ans.push_back(i);
            }
        }
        printf("%d\n",SZ(ans));
        for (int i=0;SZ(ans)>i;i++) {
            if (i) printf(" ");
            printf("%d",ans[i]);
        }
        puts("");
    }
}