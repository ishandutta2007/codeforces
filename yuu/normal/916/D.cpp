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
typedef long long ll;
typedef long double ld;
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
#define taskname "D"
class segment_tree{
    public: typedef segment_tree* iterator;
    int l, r, m;
    int value;
    iterator left, right;
    segment_tree(int l, int r, int value){
        this->l=l;
        this->r=r;
        this->value=value;
        m=(l+r)/2;
        left=right=nullptr;
    }
    public: iterator update(int u, int c){
        if(l>u||r<u) return this;
        iterator res=new segment_tree(l, r, value);
        if(l==r){
            res->value+=c;
            return res;
        }
        else{
            if(left==nullptr){
                left=new segment_tree(l, m, 0);
                right=new segment_tree(m+1, r, 0);
            }
            res->left=left->update(u, c);
            res->right=right->update(u, c);
            res->value=res->left->value+res->right->value;
            return res;
        }
    }
    public: int get(int u){
        if(l>=u) return 0;
        if(r<u) return value;
        if(left==nullptr){
            left=new segment_tree(l, m, 0);
            right=new segment_tree(m+1, r, 0);
        }
        return left->get(u)+right->get(u);
    }
    public: iterator set(int u, int c){///set a node to c
        iterator res=new segment_tree(l, r, value);
        if(l==r){
            res->value=c;
            return res;
        }
        else{
            if(left==nullptr){
                left=new segment_tree(l, m, 0);
                right=new segment_tree(m+1, r, 0);
            }
            res->left=left;
            res->right=right;
            if(m>=u) res->left=left->set(u, c);
            else res->right=right->set(u, c);
            return res;
        }
    }
    public: int get_value(int u){
        if(l==r) return value;
        if(left==nullptr){
            left=new segment_tree(l, m, 0);
            right=new segment_tree(m+1, r, 0);
        }
        if(u<=m) return left->get_value(u);
        return right->get_value(u);
    }
};
segment_tree::iterator tree[100001], value_tree[100001];
int q;
string s;
const int pmax=1000000000;
map <string, int> id;
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    tree[0]=new segment_tree(1, pmax, 0);
    cin>>q;
    value_tree[0]=new segment_tree(1, q, 0);
    {
        int t=0, x, a;
        string o, s;
        FOR(i, 1, q){
            cin>>o;
            if(o[0]=='u'){
                cin>>x;
                tree[i]=tree[i-x-1];
                value_tree[i]=value_tree[i-x-1];
            }
            else{
                value_tree[i]=value_tree[i-1];
                tree[i]=tree[i-1];
                cin>>s;
                if(id.find(s)==id.end()) id[s]=++t;
                a=id[s];
                int priority=value_tree[i]->get_value(a);
                if(o[0]=='s'){
                    cin>>x;
                    if(priority) tree[i]=tree[i-1]->update(priority, -1);
                    tree[i]=tree[i]->update(x, 1);
                    value_tree[i]=value_tree[i-1]->set(a, x);
                }
                else if(o[0]=='r'){
                    if(priority) tree[i]=tree[i-1]->update(priority, -1);
                    value_tree[i]=value_tree[i-1]->set(a, 0);
                }
                else{
                    if(priority==0) cout<<"-1\n";
                    else cout<<tree[i]->get(priority)<<'\n';
                    fflush(stdout);
                }
            }
        }
    }
}