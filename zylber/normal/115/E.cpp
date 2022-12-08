#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#define MOD 1000000007
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define dforsn(a, s, n) for(int a = (n)-1; a>=s; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
typedef long long tint;
using namespace std;

struct minNodo
{
    tint mini, prop;
    minNodo(){ mini=0; prop=0; }
    
    void merge(const minNodo &a, const minNodo &b)
    {
        mini=max(a.mini+prop, b.mini+prop);
    }
    
    void update(int i,int j, tint x)
    {
        prop+=x;
        mini+=x;
    }
    
    void split(int i,int j, minNodo &a, minNodo &b)
    {
        if(prop!=0)
        {
            int c = (i+j)/2;
            a.update(i,c, prop);
            b.update(c,j, prop);
            prop = 0;
        }
    }
};

/*template <typename Stats, typename UpdateData>
struct SegmentTree
{
    struct Node
    {
        UpdateData lazy;
        Stats stat;
        void merge(const Node &a, const Node &b) {stat.merge(a.stat,b.stat);}
        void update(int i, int j, const UpdateData &data) {lazy.update(i,j,data); stat.update(i,j,data);}
        void split(int i, int j, Node &a, Node &b)
        {
            int c = (i+j)/2;
            a.update(i,c, lazy);
            b.update(c,j, lazy);
            lazy = UpdateData();
        }
    };
    int N, qA, qB;
    UpdateData qData;
    vector<Node> v;
    SegmentTree(int userN, Node* &userData) {N = 1; while (N < userN) N *= 2; v.resize(2*N); userData = v.data() + N;}
    // Funciones internas (private)
    Stats iget(int a, int b, int i) // Get interno
    {
        if (qA <= a && b <= qB) return v[i].stat;
        if (qB <= a || b <= qA) return Stats();
        v[i].split(a,b, v[2*i], v[2*i+1]);
        int c = (a+b)/2;
        Stats res;
        res.merge(iget(a, c, 2*i), iget(c, b, 2*i+1));
        return res;
    }
    void iupdate(int a, int b, int i) // Update interno
    {
        if (qA <= a && b <= qB) {v[i].update(a,b, qData); return ;}
        if (qB <= a || b <= qA) return;
        v[i].split(a,b, v[2*i], v[2*i+1]);
        int c = (a+b)/2;
        iupdate(a, c, 2*i);
        iupdate(c, b, 2*i+1);
        v[i].merge(v[2*i], v[2*i+1]);
    }
    // Funciones que puede llamar el usuario (public)
    void init() {dforsn(i,1, N) v[i].merge(v[2*i], v[2*i+1]);} // Se inicializa luego de llenar el arreglo userData con los valores iniciales.
    Stats get(int a,int b) {qA = a; qB = b; return iget(0, N, 1); } // Get que llama el usuario
    void updateRange(int a,int b, const UpdateData &data) {qData = data; qA = a; qB = b; iupdate(0, N, 1);} // updateRange que puede llamar el usuario
    void update(int i, const UpdateData &data) { updateRange(i,i+1, data); } // update que puede llamar el usuario
};*/

template <typename Node, typename UpdateData>
struct SegmentTree
{
    int N, qA, qB;
    UpdateData qData;
    vector<Node> v;
    SegmentTree(int userN, Node* &userData) {N = 1; while (N < userN) N *= 2; v.resize(2*N); userData = v.data() + N;}
    // Funciones internas (private)
    Node iget(int a, int b, int i) // Get interno
    {
        if (qA <= a && b <= qB) return v[i];
        if (qB <= a || b <= qA) return Node();
        v[i].split(a,b, v[2*i], v[2*i+1]);
        int c = (a+b)/2;
        Node res;
        res.merge(iget(a, c, 2*i), iget(c, b, 2*i+1));
        return res;
    }
    void iupdate(int a, int b, int i) // Update interno
    {
        if (qA <= a && b <= qB) {v[i].update(a,b, qData); return ;}
        if (qB <= a || b <= qA) return;
        v[i].split(a,b, v[2*i], v[2*i+1]);
        int c = (a+b)/2;
        iupdate(a, c, 2*i);
        iupdate(c, b, 2*i+1);
        v[i].merge(v[2*i], v[2*i+1]);
    }
// Funciones que puede llamar el usuario (public)
    void init() {dforsn(i,1, N) v[i].merge(v[2*i], v[2*i+1]);} // Se inicializa luego de llenar el arreglo userData con los valores iniciales.
    Node get(int a,int b) {qA = a; qB = b; return iget(0, N, 1); } // Get que llama el usuario
    void updateRange(int a,int b, const UpdateData &data) {qData = data; qA = a; qB = b; iupdate(0, N, 1);} // updateRange que puede llamar el usuario
    void update(int i, const UpdateData &data) { updateRange(i,i+1, data); } // update que puede llamar el usuario
};

vector<pair<tint, tint> > intervs[200010];

tint DP[200010];
tint cost[200010];

int main()
{
#ifdef ACMTUYO
    freopen("87E.in","r",stdin);
#endif
    int n, m;
    cin >> n >> m;
    
    minNodo* start;
    static SegmentTree<minNodo, tint> tree(n, start);
    tree.init();

    forn(i, n) cin >> cost[i];
    
    forn(i, m)
    {
        int a, b, g;
        cin >> a >> b >> g;
        a--; b--;
        intervs[b].push_back(make_pair(a,g));
    }

    tint ans=0;
    forn(i, n)
    {
        tree.updateRange(0, i+1, -cost[i]);
        int vs=intervs[i].size();
        forn(j, vs)
        {
            //cout << i << " " << intervs[i][j].first+1 << " " << intervs[i][j].second << endl;
            tree.updateRange(0, intervs[i][j].first+1, intervs[i][j].second); 
        }
        
        //forn(j, n+1) tree.get(j, j+1);
        /*forn(j, n+1) cout << tree.v[j+tree.N].mini << " ";
        cout << endl;*/
        
        DP[i]=max(0LL, tree.get(0, i+1).mini);
        if(i) DP[i]=max(DP[i], DP[i-1]);
        tree.update(i+1, DP[i]);
        /*forn(j, n+1) cout << tree.v[j+tree.N].mini << " ";
        cout << endl;*/
        ans=max(ans, DP[i]);
    }
    
    cout << ans << endl;
    
    return 0;
}