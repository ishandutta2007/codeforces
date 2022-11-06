#include<stdio.h>
#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <map>
#include <functional>
#include <stdio.h>
#include <array>
#include <algorithm>
#include <string>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <queue>
#include<iomanip>
#include<bitset>
#include<stack>
#include<set>
#include<limits>
#include <complex>
using namespace std;


const int mod = 1000000007;
struct Mod {
public:
    int num;
    Mod() : num(0) { ; }
    Mod(long long int n) : num((n % mod + mod) % mod) { ; }
    Mod(int n) : num((n % mod + mod) % mod) { ; }
    operator int() { return num; }
};

Mod operator+(const Mod a, const Mod b) { return Mod((a.num + b.num) % mod); }
Mod operator+(const long long int a, const Mod b) { return Mod(a) + b; }
Mod operator++(Mod &a) { return a + Mod(1); }
Mod operator-(const Mod a, const Mod b) { return Mod((mod + a.num - b.num) % mod); }
Mod operator-(const long long int a, const Mod b) { return Mod(a) - b; }
Mod operator--(Mod &a) { return a - Mod(1); }
Mod operator*(const Mod a, const Mod b) { return Mod(((long long)a.num * b.num) % mod); }
Mod operator*(const long long int a, const Mod b) { return Mod(a)*b; }
Mod operator+=(Mod &a, const Mod b) { return a = a + b; }
Mod operator+=(long long int &a, const Mod b) { return a = a + b; }
Mod operator-=(Mod &a, const Mod b) { return a = a - b; }
Mod operator-=(long long int &a, const Mod b) { return a = a - b; }
Mod operator*=(Mod &a, const Mod b) { return a = a * b; }
Mod operator*=(long long int &a, const Mod b) { return a = a * b; }
Mod operator^(const Mod a, const int n) {
    if (n == 0) return Mod(1);
    Mod res = (a * a) ^ (n / 2);
    if (n % 2) res = res * a;
    return res;
}
Mod inv(const Mod a) { return a ^ (mod - 2); }
Mod operator/(const Mod a, const Mod b) {
    assert(b.num != 0);
    return a * inv(b);
}
Mod operator/(const long long int a, const Mod b) {
    assert(b.num != 0);
    return Mod(a) * inv(b);
}
Mod operator/=(Mod &a, const Mod b) {
    assert(b.num != 0);
    return a = a * inv(b);
}

#define MAX_N 1024000

Mod fact[MAX_N], factinv[MAX_N];
void init() {
    fact[0] = Mod(1); factinv[0] = 1;
    for (int i = 0; i < MAX_N - 1; ++i) {
        fact[i + 1] = fact[i] * Mod(i + 1);
        factinv[i + 1] = factinv[i] / Mod(i + 1);
    }
}
Mod comb(const int a, const int b) {
    return fact[a] * factinv[b] * factinv[a - b];
}


template<typename T>
vector<vector<T>> keisann(const vector<vector<T>>l, const vector<vector<T>>r) {
    vector<vector<T>>ans(l.size(), vector<T>(r[0].size()));
    assert(l[0].size() == r.size());
    for (unsigned int h = 0; h < l.size(); ++h) {
        for (unsigned int i = 0; i < r.size(); ++i) {
            for (unsigned int w = 0; w < r[0].size(); ++w) {

                ans[h][w] += l[h][i] * r[i][w];
            }
        }
    }
    return ans;
}
template<typename T>
vector<vector<T>>powgyou(vector<vector<T>>a, const long long int n) {
    assert(a.size() == a[0].size());
    if (!n) {
        vector<vector<T>>e(a.size(), vector<T>(a[0].size()));
        for (unsigned int i = 0; i < a.size(); ++i) {
            e[i][i] = 1;
        }
        return e;
    }
    if (n == 1)return a;
    else {
        vector<vector<T>>ans(a.size(), vector<T>(a[0].size(), 0));
        ans = powgyou(a, n / 2);
        ans = keisann(ans, ans);
        if (n % 2) {
            ans = keisann(ans, a);
        }
        return ans;
    }
}

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(auto i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

const int INF = 2147483647;
const long long int L_INF = 9223372036854775807;

typedef int Weight;
struct Edge {
    int src, dst;
    Weight weight;
    Edge(int src, int dst, Weight weight) :
        src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
    return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;
#define RESIDUE(s,t) (capacity[s][t]-flow[s][t])

vector<pair<int, int>>uses;

//0
Weight maximumFlow(const Graph &ag, int s, int t) {

    Graph g(ag);
    for (int i = 0; i < ag.size(); ++i) {
        for (int j = 0; j < ag[i].size(); ++j) {
            int d = ag[i][j].dst;
            int s = ag[i][j].src;
            
            bool ok = false;
            for (int k = 0; k < ag[d].size(); ++k) {
                if (ag[d][k].src == s) {
                    ok = true; 
                    break;
                }
            }
            if (!ok) {
                g[d].push_back(Edge(d, s, 0));
            }
        }
    }

    int n = g.size();
    Matrix flow(n, Array(n)), capacity(n, Array(n));
    REP(u, n) FOR(e, g[u]) capacity[e->src][e->dst] += e->weight;

    Weight total = 0;
    while (1) {
        queue<int> Q; Q.push(s);
        vector<int> prev(n, -1); prev[s] = s;
        while (!Q.empty() && prev[t] < 0) {
            int u = Q.front(); Q.pop();
            FOR(e, g[u]) if (prev[e->dst] < 0 && RESIDUE(u, e->dst) > 0) {
                prev[e->dst] = u;
                Q.push(e->dst);
            }
        }
        if (prev[t] < 0) return total; // prev[x] == -1 <=> t-side
        Weight inc = INF;
        for (int j = t; prev[j] != j; j = prev[j])
            inc = min(inc, RESIDUE(prev[j], j));
        for (int j = t; prev[j] != j; j = prev[j])
            flow[prev[j]][j] += inc, flow[j][prev[j]] -= inc;
        total += inc;
    }
}

map<long long int, int>soinnsuu(long long int a) {
    map<long long int, int>ans;
    for (long long i = 2; i*i <= a; ++i) {
        while (a%i == 0) {
            ans[i]++;
            a /= i;
        }
    }
    if (a != 1)ans[a]++;


    return ans;
}

bool isso(long long int a) {
    if (a == 1)return false;
    for (long long int i = 2; i*i <= a; ++i) {
        if (!(a%i)) {
            return false;
        }
        else {
        }
    }
    return true;
}


struct vert {
    int deg;
    int s;
    int id;
    vert(int a, int b, int c) {
        deg = a;
        s = b;
        id = c;
    }
};


#include<stdio.h>
#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <map>
#include <functional>
#include <stdio.h>
#include <array>
#include <algorithm>
#include <string>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <queue>
#include<iomanip>
#include<bitset>
#include<stack>
#include<set>
#include<limits>
#include <complex>
using namespace std;
class Compare {
public:
    bool operator()(const pair<int, int>&l, const pair<int, int>&r) {
        return l.second > r.second;
    }
};

long long int powint(long long int a, int b) {
    if (b == 0)return 1;
    if (b == 1)return a;
    else {
        long long int ans = 1;
        long long int c = powint(a, b / 2);
        ans *= c*c;
        ans *= (b % 2) ? a : 1;
        return ans;
    }

}


#define Seg_Max_N (1<<18) 
// update(l,r,v) := [l,r]v. k,a,b

struct NODE {
    int sum;//. .
    int lazy;   //
    NODE() {
        sum = lazy = 0;
    }
};

NODE seg[2 * Seg_Max_N];

// inline!()
inline void lazy_evaluate_node(int k, int a, int b) {
    seg[k].sum += seg[k].lazy * (b - a + 1);
    if (k < Seg_Max_N) { // 2*k() < 2*N () . .
        seg[2 * k].lazy += seg[k].lazy; //.
        seg[2 * k + 1].lazy += seg[k].lazy;
    }
    seg[k].lazy = 0;
}

inline void update_node(int k) { // k. if.
    seg[k].sum = seg[2 * k].sum + seg[2 * k + 1].sum;
}

// update(l,r,v) := [l,r]. 1-indexed.
void update(int l, int r, int v, int k = 1, int a = 1, int b = Seg_Max_N) {
    if (l < 0||r<0)assert(false);
    lazy_evaluate_node(k, a, b);    // .

    if (b < l || r < a) //[a,b][l,r]
        return;
    if (l <= a && b <= r) { // [l,r][a,b]
        seg[k].lazy += v;
        lazy_evaluate_node(k, a, b); //.
        return;
    }

    int m = (a + b) / 2;
    update(l, r, v, 2 * k, a, m);
    update(l, r, v, 2 * k + 1, m + 1, b);
    update_node(k);
}

// get(l,r) := [l,r]. 1-indexed.
int get(int l, int r, int k = 1, int a = 1, int b = Seg_Max_N) {
    if (l < 0||r<0)assert(false);
    lazy_evaluate_node(k, a, b); // .

    if (b < l || r < a) //[a,b][l,r]
        return 0;

    if (l <= a && b <= r) { // [l,r][a,b]
        return seg[k].sum;
    }

    int m = (a + b) / 2;
    int vl = get(l, r, 2 * k, a, m);
    int vr = get(l, r, 2 * k + 1, m + 1, b);
    update_node(k);
    return vl + vr;
}
struct rect {
    long long int jiku;
    long long int amin;
    long long int amax;
};
struct ev {
    long long int atime;
    int atype;
    long long int a;
    long long int b;
};

//2:54
int main() {
    int N; cin >> N;
    long long int ans = 0;
    vector<rect >hlongs;
    vector<rect >wlongs;
    set<long long int>aset;
    for (int i = 0; i < N; ++i) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2)swap(x2, x1);
        if (y1 > y2)swap(y1, y2);
        aset.emplace(x1);
        aset.emplace(x2);
        aset.emplace(y1);
        aset.emplace(y2);
        if (x1 == x2) {
            
            hlongs.push_back(rect{ x1,y1,y2 });

        }
        else {
            wlongs.push_back(rect{ y1,x1,x2 });
        }
    }
    long long int num = 0;
    map<long long int, long long int>compress;
    for (auto it = aset.begin(); it != aset.end(); ++it) {
        compress[(*it)] = num;
        num++;
    }

    
    sort(hlongs.begin(), hlongs.end(), [](const rect&l, const rect&r) {return l.jiku == r.jiku ? (l.amin==r.amin?l.amax<r.amax:l.amin<r.amin) : l.jiku < r.jiku; });
    sort(wlongs.begin(), wlongs.end(), [](const rect&l, const rect&r) {return l.jiku == r.jiku ? (l.amin == r.amin ? l.amax<r.amax : l.amin<r.amin) : l.jiku < r.jiku; });


    long long int minusnum = 0;

    vector<rect>nhlongs,nwlongs;
    {
        int i = 0;
        if (!hlongs.empty()) {
            for (; i < hlongs.size();) {
                rect nowr(hlongs[i]);
                int nowc = i + 1;
                while (nowc<hlongs.size()&& nowr.jiku == hlongs[nowc].jiku) {
                    if (nowr.amax < hlongs[nowc].amin ) {
                        nhlongs.push_back(nowr);
                        nowr = hlongs[nowc];
                    }
                    else if (nowr.amin>hlongs[nowc].amax) {
                        nhlongs.push_back(nowr);
                        nowr = hlongs[nowc];
                    }
                    else {
                        nowr=(rect{ nowr.jiku,min(nowr.amin,hlongs[nowc].amin),max(nowr.amax,hlongs[nowc].amax) });
                    }
                    nowc++;
                }
                nhlongs.push_back(nowr);
                i = nowc;
                
            }

        }
    }
    {
        int i = 0;
        if (!wlongs.empty()) {
            for (; i < wlongs.size();) {
                rect nowr(wlongs[i]);
                int nowc = i + 1;
                while (nowc<wlongs.size() && nowr.jiku == wlongs[nowc].jiku) {
                    if (nowr.amax < wlongs[nowc].amin) {
                        nwlongs.push_back(nowr);
                        nowr = wlongs[nowc];
                    }
                    else if (nowr.amin>wlongs[nowc].amax) {
                        nwlongs.push_back(nowr);
                        nowr = wlongs[nowc];
                    }
                    else {
                        nowr = (rect{ nowr.jiku,min(nowr.amin,wlongs[nowc].amin),max(nowr.amax,wlongs[nowc].amax) });
                    }
                    nowc++; 
                }
                nwlongs.push_back(nowr);                            
                i = nowc;

            }

        }
    }
    wlongs = nwlongs;
    hlongs = nhlongs;
    for (int i = 0; i < hlongs.size(); ++i) {
        ans += hlongs[i].amax - hlongs[i].amin + 1;
    }
    for (int i = 0; i < wlongs.size(); ++i) {
        ans += wlongs[i].amax - wlongs[i].amin + 1;
    }
    for (int i = 0; i < hlongs.size(); ++i) {
        hlongs[i].amin = compress[hlongs[i].amin];
        hlongs[i].amax = compress[hlongs[i].amax];
        hlongs[i].jiku = compress[hlongs[i].jiku];
    }
    for (int i = 0; i < wlongs.size(); ++i) {
        wlongs[i].amin = compress[wlongs[i].amin];
        wlongs[i].amax = compress[wlongs[i].amax];
        wlongs[i].jiku = compress[wlongs[i].jiku];
    }
    

    vector<ev>evs;

    for (int i = 0; i < hlongs.size(); ++i) {
        ev aev{ 2 * hlongs[i].jiku+2,2,2*hlongs[i].amin-1 + 2,2*hlongs[i].amax+1 + 2 };
        evs.push_back(aev);
    }
    for (int i = 0; i < wlongs.size(); ++i) {
        ev inev{ 2 * wlongs[i].amin - 1 + 2,0,2*wlongs[i].jiku + 2,2*wlongs[i].jiku + 2 };
        ev outev{ 2 * wlongs[i].amax + 1 + 2,1,2*wlongs[i].jiku + 2,2*wlongs[i].jiku + 2 };
        evs.push_back(inev);
        evs.push_back(outev);
    }
    sort(evs.begin(), evs.end(), [](const ev&l, const ev&r) {return l.atime < r.atime; });

    for (int i = 0; i < evs.size(); ++i) {
        switch (evs[i].atype) {
        case 2:
            minusnum += get(evs[i].a, evs[i].b);
            break;
        case 0:
            update(evs[i].a, evs[i].a,1);
            break;
        case 1:

            update(evs[i].a, evs[i].a, -1);
            break;
        }
    }
    cout << ans - minusnum << endl;
    return 0;
}