#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define setbit(s, i) (s|=(1LL<<(i)))
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
using ll=long long;
using ld=long double;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
#define taskname "E"
int n;
ll k;
int f[100000];
ll w[100000];
int done[100000];
int num[100000];
int low[100000];
int cnt;
vector <int> v;
int from[100000];
vector <int> cc[100000];
vector <pair <int, ll> > g[100000];
vector <ll> sum[100000];
class min_query{
public:
    int from, left, right;
    min_query(int from, int left, int right){
        this->from=from;
        this->left=left;
        this->right=right;
    }
};
vector <min_query> q[100000];
ll d[100000];
int h[100000];
bool root[100000];
int pos[100000];
int from_pos[100000];
int ccnt;
int acs[100000][20];
int mw[100000][20];
ll s[100000];
ll m[100000];
ll sumw[100000];
ll minw[100000];
void dfs(int u){
    cnt++;
    done[u]=1;
    num[u]=low[u]=cnt;
    v.pb(u);
    if(!done[f[u]]){
        dfs(f[u]);
        low[u]=min(low[u], low[f[u]]);
    }
    else if(done[f[u]]==1) low[u]=min(low[u], num[f[u]]);
    if(num[u]==low[u]){
        root[ccnt]=1;
        int x;
        do{
            x=v.back();
            v.pop_back();
            from[x]=ccnt;
            done[x]=2;
            cc[ccnt].pb(x);
        }
        while(x!=u);
        reverse(cc[ccnt].begin(), cc[ccnt].end());
        ccnt++;
    }
}
ll get_sum(int r, int pos, ll k){
    if(k==0) return 0;
    if(k>=cc[r].size()) return sumw[r]*(k/cc[r].size())+get_sum(r, pos, k%cc[r].size());
    if(pos+k>cc[r].size()) return get_sum(r, pos, cc[r].size()-pos)+get_sum(r, 0, k-cc[r].size()+pos);
    return sum[r][pos+k-1]-(pos?(sum[r][pos-1]):(0));
}
void add_minquery(int from, int r, int pos, ll k){
    if(k>=cc[r].size()) m[from]=min(m[from], minw[r]);
    else if(pos+k>cc[r].size()){
        add_minquery(from, r, pos, cc[r].size()-pos);
        add_minquery(from, r, 0, k-cc[r].size()+pos);
    }
    else{
        q[r].pb(min_query(from, pos, pos+k-1));
    }
}
void prepare(int r){
    FFOR(i, 0, cc[r].size()) pos[cc[r][i]]=i;
    for(int u: cc[r]) sumw[r]+=w[u];
    minw[r]=1e9;
    for(int u: cc[r]) minw[r]=min(minw[r], w[u]);
    ll now=0;
    for(int u: cc[r]){
        now+=w[u];
        sum[r].pb(now);
    }
}
void solve_min_queries(int r){
    sort(q[r].begin(), q[r].end(), [](min_query A, min_query B){
        return A.right<B.right;
    });
    int x=0;
    deque <pair <int, ll> > d;
    for(min_query A: q[r]){
        while(x<=A.right){
            while((!d.empty())&&(d.back().second>=w[cc[r][x]])) d.pop_back();
            d.pb(mp(x, w[cc[r][x]]));
            x++;
        }
        int low=0, high=d.size()-1, mid, res=high;
        while(low<=high){
            mid=(low+high)/2;
            if(d[mid].first>=A.left){
                res=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        m[A.from]=min(m[A.from], d[res].second);
    }
}
vector <int> ac;
void dfs_tree(int u, int r, int entrance){
    ac.pb(u);
    if(u==r){
        for(int v: cc[u]){
            s[v]=get_sum(u, pos[v], k);
            add_minquery(v, u, pos[v], k);
        }
    }
    else{
        mw[u][0]=w[cc[u][0]];
        for(int i=0; (acs[acs[u][i]][i]!=-1); i++){
            acs[u][i+1]=acs[acs[u][i]][i];
            mw[u][i+1]=min(mw[u][i], mw[acs[u][i]][i]);
        }
        if(k<=h[u]){
            s[cc[u][0]]=d[u]-d[ac[h[u]-k]];
            int x=u;
            DFOR(i, __lg(h[x]+1), 0) if(acs[x][i]!=-1){
                if(h[acs[x][i]]>=h[u]-k){
                    m[cc[u][0]]=min(m[cc[u][0]], (ll)mw[x][i]);
                    x=acs[x][i];
                }
            }
        }
        else{
            s[cc[u][0]]=d[u]+get_sum(r, entrance, k-h[u]);
            int x=u;
            DFOR(i, __lg(h[x]+1), 0) if(acs[x][i]!=-1){
                m[cc[u][0]]=min(m[cc[u][0]], (ll)mw[x][i]);
                x=acs[x][i];
            }
            add_minquery(cc[u][0], r, entrance, k-h[u]);
        }
    }
    for(pair <int, ll> v: g[u]){
        d[v.first]=d[u]+v.second;
        h[v.first]=h[u]+1;
        acs[v.first][0]=u;
        if(u==r) dfs_tree(v.first, r, from_pos[v.first]);
        else dfs_tree(v.first, r, entrance);
    }
    ac.pop_back();
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(k);
    FFOR(i, 0, n) read(f[i]);
    FFOR(i, 0, n) read(w[i]);
    ///detect all cycle
    FFOR(i, 0, n) if(!done[i]) dfs(i);
    FFOR(i, 0, n) if(from[i]!=from[f[i]]){
        root[from[i]]=0;
        g[from[f[i]]].pb(mp(from[i], w[i]));
    }
    FFOR(i, 0, n) m[i]=1e9;
    FFOR(i, 0, ccnt) if(root[i]) prepare(i);
    FFOR(i, 0, n) if(from[i]!=from[f[i]]){
        from_pos[from[i]]=pos[f[i]];
    }
    FOR(lg, 0, __lg(ccnt+1)) FFOR(i, 0, ccnt) acs[i][lg]=-1;
    FFOR(i, 0, ccnt) if(root[i]){
        dfs_tree(i, i, -1);
        solve_min_queries(i);
    }
    FFOR(i, 0, n){
        write(s[i]);
        putchar(' ');
        writeln(m[i]);
    }
}