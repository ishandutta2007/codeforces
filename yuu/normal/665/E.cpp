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
ll k, a, s;
class trie{
public:
    using pointer=trie*;
    int value;
    pointer g[2];
    trie(){
        value=0;
        g[0]=g[1]=nullptr;
    }
    static void add(pointer root, ll x){
        DFOR(i, 31, 0){
            if(root->g[bit(x, i)]==nullptr) root->g[bit(x, i)]=new trie();
            root=root->g[bit(x, i)];
            root->value++;
        }
    }
    static int get(pointer root, ll x){
        int res=0;
        DFOR(i, 31, 0){
            int cont=bit(x, i)^bit(k, i);
            if(root->g[1-cont]!=nullptr) if(bit(k, i)==0) res+=root->g[1-cont]->value;
            root=root->g[cont];
            if(root==nullptr) break;
        }
        if(root!=nullptr) res+=root->value;
        return res;
    }
};
trie::pointer tree;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    tree=new trie();
    ll ans=0;
    read(n);
    read(k);
    FOR(i, 1, n){
        trie::add(tree, s);
        read(a);
        s^=a;
        ans+=trie::get(tree, s);
    }
    writeln(ans);
}