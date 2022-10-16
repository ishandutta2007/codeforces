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
#define taskname "F"
class aho_corasick{
public:
    using pointer=aho_corasick*;
    pointer g[26];
    pointer f, p;
    char c;
    int w;
    aho_corasick(char c, pointer p){
        FFOR(i, 0, 26) g[i]=nullptr;
        w=0;
        this->c=c;
        this->p=p;
    }
    static void add(pointer root, string &s){
        for(char c: s){
            if(root->g[c]==nullptr) root->g[c]=new aho_corasick(c, root);
            root=root->g[c];
        }
        root->w++;
    }
    void self_construct(pointer root){
        if(p==nullptr) f=this;
        else{
            f=p->f;
            while((f->p!=nullptr)&&(f->g[c]==nullptr)) f=f->f;
            if(f->g[c]!=nullptr){
                f=f->g[c];
                if(f==this) f=root;
                else w+=f->w;
            }
        }
    }
    static void construct(pointer root){
        queue <pointer> q;
        pointer u;
        q.push(u=root);
        while(!q.empty()){
            u=q.front();
            q.pop();
            u->self_construct(root);
            FFOR(i, 0, 26) if(u->g[i]!=nullptr) q.push(u->g[i]);
        }
    }
    static int count(pointer root, string &s){
        pointer now=root;
        int res=0;
        for(char a: s){
            while((now->p!=nullptr)&&(now->g[a]==nullptr)) now=now->f;
            if(now->g[a]!=nullptr){
                now=now->g[a];
                res+=now->w;
            }
        }
        return res;
    }
};
aho_corasick::pointer tree[20], mtree[20];
int m;
vector <int> id[20], mid[20];
string s[300001];
void add(int u, vector <int> *id, aho_corasick::pointer *tree){
    vector <int> temp;
    temp.pb(u);
    FFOR(i, 0, 20) if(tree[i]!=nullptr){
        for(int x: id[i]) temp.pb(x);
        id[i].clear();
        tree[i]=nullptr;
    }
    else{
        tree[i]=new aho_corasick(255, nullptr);
        id[i]=temp;
        temp.clear();
        for(int x: id[i]) aho_corasick::add(tree[i], s[x]);
        aho_corasick::construct(tree[i]);
        break;
    }
}
int get(int u, vector <int> *id, aho_corasick::pointer *tree){
    int res=0;
    FFOR(i, 0, 20) if(tree[i]!=nullptr) res+=aho_corasick::count(tree[i], s[u]);
    return res;
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    FFOR(i, 0, 20) tree[i]=mtree[i]=nullptr;
    cin>>m;
    {
        int t;
        FOR(i, 1, m){
            cin>>t>>s[i];
            for(char &c: s[i]) c-='a';
            if(t==1) add(i, id, tree);
            else if(t==2) add(i, mid, mtree);
            else{
                writeln(get(i, id, tree)-get(i, mid, mtree));
                fflush(stdout);
            }
        }
    }
}