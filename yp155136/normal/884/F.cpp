#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <stack>
using namespace std;

#define LL   long long
#define ld   long double
#define pii  pair<int,int>
#define pLL  pair<LL,LL>
#define vint vector<int>
#define vLL  vector<LL>

#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define MP make_pair
#define PB push_back

#define Si(x) scanf("%d",&(x));
#define Sii(x,y) scanf("%d %d",&(x),&(y));
#define Siii(x,y,z) scanf("%d %d %d",&(x),&(y),&(z));
#define Siiii(x,y,z,w) scanf("%d %d %d %d",&(x),&(y),&(z),&(w));
#define Siiiii(x,y,z,w,a) scanf("%d %d %d %d %d",&(x),&(y),&(z),&(w),&(a));
#define Siiiiii(x,y,z,w,a,b) scanf("%d %d %d %d %d %d",&(x),&(y),&(z),&(w),&(a),&(b));
#define SL(x) scanf("%lld",&(x));
#define SLL(x,y) scanf("%lld %lld",&(x),&(y));
#define SLLL(x,y,z) scanf("%lld %lld %lld",&(x),&(y),&(z));
#define SLLLL(x,y,z,w) scanf("%lld %lld %lld %lld",&(x),&(y),&(z),&(w));
#define SLLLLL(x,y,z,w,a) scanf("%lld %lld %lld %lld %lld",&(x),&(y),&(z),&(w),&(a));
#define SLLLLLL(x,y,z,w,a,b) scanf("%lld %lld %lld %lld %lld %lld",&(x),&(y),&(z),&(w),&(a),&(b));

#define Pi(x) printf("%d\n",(x));
#define Pii(x,y) printf("%d %d\n",(x),(y));
#define Piii(x,y,z) printf("%d %d %d\n",(x),(y),(z));
#define Piiii(x,y,z,w) printf("%d %d %d %d\n",(x),(y),(z),(w));
#define Piiiii(a,b,c,d,e) printf("%d %d %d %d %d\n",(a),(b),(c),(d),(e));
#define Piiiiii(a,b,c,d,e,f) printf("%d %d %d %d %d %d\n",(a),(b),(c),(d),(e),(f));
#define PL(x) printf("%lld\n",(x)*1LL);
#define PLL(x,y) printf("%lld %lld\n",(x)*1LL,(y)*1LL);
#define PLLL(x,y,z) printf("%lld %lld %lld\n",(x)*1LL,(y)*1LL,(z)*1LL);
#define PLLLL(x,y,z,w) printf("%lld %lld %lld %lld\n",(x)*1LL,(y)*1LL,(z)*1LL,(w)*1LL);
#define PLLLLL(a,b,c,d,e) printf("%lld %lld %lld %lld %lld\n",(a),(b),(c),(d),(e));
#define PLLLLLL(a,b,c,d,e,f) printf("%lld %lld %lld %lld %lld %lld\n",(a),(b),(c),(d),(e),(f));

#define Pi1(x) printf("%d",  (x));
#define PiL(x) printf("%lld",(x));
#define Pspace putchar(' ');
#define Pendl  puts("");

#define MEM0(x) memset( (x), 0, sizeof( (x) ) )
#define MEM1(x) memset( (x),-1, sizeof( (x) ) )
#define REP1(i,n)  for (int i = 1; (n) >= i ; ++i)
#define REP0(i,n)  for (int i = 0; (n) >  i ; ++i)
#define REP(L,R,k) for (int i = (L); (R) >= i; i+= (k) )

int myRnd(int L,int R) {
    return abs(( (rand()<<15)|rand() ) ) % (R-L+1) + L;
}

struct CostFlow {
	static const int MAX_N = 2e3 + 6;
	struct Edge {
		int to,cap,rev,cost;
	};
	int s,t,n;
	vector<Edge> edg[MAX_N];
	void init(int _n,int _s,int _t) {
		n=_n;
		s=_s;
		t=_t;
		for (int i=0;n>=i;i++) {
			edg[i].clear();
		}
	}
	#define SZ(x) ((int)(x).size())
	void add_edge(int from,int to,int cap,int cost) {
		edg[from].push_back({to,cap,SZ(edg[to]),cost});
		edg[to].push_back({from,0,SZ(edg[from])-1,-cost});
	}
	static const int INF = 1e9 + 7;
	int dis[MAX_N];
	int pre[MAX_N];
	int pre_id[MAX_N];
	bool in_que[MAX_N];
	pii flow() {
		int flow=0,cost=0;
		while (true) {
			for (int i=0;n>=i;i++) {
				dis[i] = INF;
				in_que[i] = false;
			}
			queue<int> que;
			que.push(s);
			dis[s] = 0;
			while (!que.empty()) {
				int t=que.front();
				que.pop();
				in_que[t] = false;
				int id=0;
				for (Edge e:edg[t]) {
					if (e.cap > 0 && dis[e.to] > dis[t] + e.cost) {
						dis[e.to] = dis[t] + e.cost;
						pre[e.to] = t;
						pre_id[e.to] = id;
						if (!in_que[e.to]) {
							que.push(e.to);
							in_que[e.to] = true;
						}
					}
					id++;
				}
			}
			if (dis[t] == INF) break;
			int mn_flow = INF;
			for (int i=t;i!=s; i=pre[i]) {
				mn_flow = min(mn_flow,edg[pre[i]][pre_id[i]].cap);
			}
			flow += mn_flow;
			for (int i=t;i!=s; i=pre[i]) {
				edg[pre[i]][pre_id[i]].cap -= mn_flow;
				edg[i][edg[pre[i]][pre_id[i]].rev].cap += mn_flow;
			}
			cost += mn_flow * dis[t];
		}
		return make_pair(flow,cost);
	}
} Flow;

int b[144];
int cnt[144];

int main () {
    int n;
    cin >> n;
    string ss;
    cin >> ss;
    ss=" "+ss;
    REP1(i,n)
    {
        cin >> b[i];
        cnt[ ss[i] ]++;
    }
    int s=0,t=2000;
    Flow.init(t,s,t);
    for (int i=1;n>=i;i++) {
        Flow.add_edge(i,t,1,0);
    }
    int nowid = n+3;
    for (int i='a';'z'>=i;i++) {
        if (!cnt[i]) continue;
        int _=nowid;
        Flow.add_edge(s,nowid++,cnt[i],0);
        for (int j=1;n/2>=j;j++) {
            int jj=n-j+1;
            int last=nowid;
            Flow.add_edge(_,nowid++,1,0);
            int cost=0;
            if (ss[j] == i) cost=-b[j];
            Flow.add_edge(last,j,1,cost);
            cost = 0;
            if (ss[jj] == i) cost = -b[jj];
            Flow.add_edge(last,jj,1,cost);
        }
    }
    cout << -Flow.flow().second<<endl;
}