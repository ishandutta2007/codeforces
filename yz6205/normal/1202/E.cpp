#define ENABLE_LL
#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

#ifdef ENABLE_LL
#define int long long
#endif

#ifdef ENABLE_LL
#define I "%lld"
#define II "%lld%lld"
#define III "%lld%lld%lld"
#define IIII "%lld%lld%lld%lld"
#define IN "%lld\n"
#define IIN "%lld%lld\n"
#define IIIN "%lld%lld%lld\n"
#define IIIIN "%lld%lld%lld%lld\n"
#else
#define I "%d"
#define II "%d%d"
#define III "%d%d%d"
#define IIII "%d%d%d%d"
#define IN "%d\n"
#define IIN "%d%d\n"
#define IIIN "%d%d%d\n"
#define IIIIN "%d%d%d%d\n"
#endif

#ifdef __LOCALE__
#define see(a) std::cout << #a << "=" << a << std::endl
#define ses(a) std::cout << #a << "=" << a << " " 
#else
#define see(a) //std::cout << #a << "=" << a << std::endl
#define ses(a)
#endif
#define foreach(a,b) for (int a=0;a<(int)b.size();a++)
#define rep(i,n) for (int i=0;i<n;i++)
#define repa(i,n) for (int i=1;i<=n;i++)
#define repi(i,a,b) for (int i=a;i<=b;i++) 
#define repb(i,a,b) for (int i=a;i>=b;i--)
typedef pair < int , int > pr;
typedef pair < pr  , int > prr;
#define L first
#define R second
template <class T> inline bool checkMin(T& a , T b) { return (a > b ? a=b,1 : 0); }
template <class T> inline bool checkMax(T& a , T b) { return (a < b ? a=b,1 : 0); }

const int K = 26;
const int N = 400005;
const char B = 'a';
struct Node {
    Node* e[K];
    Node* fail;
    int item, dep;

    Node (int dep) : dep(dep)  {
        rep (i,K) e[i] = NULL;
        fail = NULL;
        item = 0;
    }
};

class AhoCorasick{
private:
    Node* R;
    int times[N];

public: 
    AhoCorasick () { R = new Node(0); }

    void insert(char* s) {
        Node* pos = R;
        while (*s) {
            int v = *s - B;
            if (pos->e[v] == NULL) pos->e[v] = new Node( pos->dep + 1 );
            pos = pos->e[v];
            s++;
        }
        pos->item++;
    }

    void build() {
        R->fail = R;
        queue < Node* > que;
        rep (i,K) if (R->e[i] != NULL) { que.push(R->e[i]); R->e[i]->fail = R; }
                  else                 R->e[i] = R;
        while (!que.empty()) {
            Node* u = que.front(); que.pop();
            rep (i,K) {
                if (u->e[i] != NULL) { 
                    u->e[i]->fail =  u->fail->e[i];
                    u->e[i]->item += u->e[i]->fail->item;
                    que.push( u->e[i] ); 
                } else { 
                    u->e[i]       =  u->fail->e[i]; 
                }
            }
        }
    }

    void query(char* s, int ans[]) {
        Node* u = R;
        int id = 0;
        while (*s) {
            int v = *s - B;
            u = u->e[v];
            ans[id] += u->item;
            id++; s++;
        }
    }

    ~AhoCorasick() {
        delete R;
    }
};

char t[N];
char s[N];
int st[N];
int n;

AhoCorasick Aho0, Aho1;

void init() {
    scanf("%s",t);
    scanf(I,&n);
    rep (i,n) {
        scanf("%s",s); 
        Aho0.insert(s);
        int l = strlen(s); reverse(s, s+l);
        Aho1.insert(s);
    }
}

int pre[N], suf[N];

void solve() {
    Aho0.build(); Aho1.build();
    Aho0.query(t, pre);
    int l = strlen(t);
    reverse(t, t + l);
    Aho1.query(t, suf);
    reverse(suf, suf+l);
    rep (i,l) ses(pre[i]); see("");
    rep (i,l) ses(suf[i]); see("");
    int ans = 0;
    repa (i,l - 1) ans += pre[i - 1] * suf[i];
    printf(IN,ans);
}


#ifdef ENABLE_LL
#undef int
#endif
int main(){
    init();
    solve();
    return 0;
}