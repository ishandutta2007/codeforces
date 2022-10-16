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
#define taskname "C"
const ll inf=mask(60);
ll n, m, bounty, increase, damage;
class enemy{
    public: ll health, max_health, regen, last;
    void calculate(ll start){
        ///start at health
        if(max_health<=damage||(health<=damage&&regen==0)) last=inf;
        else{
            if(health>damage) last=-inf;
            else last=start+(damage-health)/regen;
        }
    }
} e[100001];
class event{
    public: ll time, enemy, health;
    bool operator <(event e){
        return time<e.time;
    }
} ev[100001];
class splay_tree{
    public:
    typedef splay_tree* iterator;
    ll value, count, priority;
    iterator parent, left, right;
    splay_tree(){
        value=count=0;
        priority=rand()*rand();
        left=right=parent=nullptr;
    }
    splay_tree(ll value){
        this->value=value;
        this->count=1;
        priority=rand()*rand();
        left=right=parent=nullptr;
    }
    inline void fix(){
        count=1;
        if(left!=nullptr) count+=left->count;
        if(right!=nullptr) count+=right->count;
    }
    inline void rotate_left(){
        iterator y=parent;
        iterator z=this->left;
        parent=y->parent;
        if(parent!=nullptr){
            if(y==parent->left) parent->left=this;
            else parent->right=this;
        }
        left=y;
        y->parent=this;
        y->right=z;
        if(z!=nullptr) z->parent=y;
        y->fix();
        fix();
    }
    inline void rotate_right(){
        iterator y=parent;
        iterator z=this->right;
        parent=y->parent;
        if(parent!=nullptr){
            if(y==parent->left) parent->left=this;
            else parent->right=this;
        }
        right=y;
        y->parent=this;
        y->left=z;
        if(z!=nullptr) z->parent=y;
        y->fix();
        fix();
    }
    inline void splay(iterator &root){
        while(parent!=nullptr){
            if(priority<parent->priority) return;
            if(parent->left==this) rotate_right();
            else rotate_left();
        }
        root=this;
    }
    inline void forced_splay(){
        while(parent!=nullptr){
            if(parent->left==this) rotate_right();
            else rotate_left();
        }
    }
    static inline void insert(iterator &root, iterator i, ll value){
        if(i==nullptr||root==nullptr) exit(-1);
        while(true){
            i->count++;
            if(value<(i->value)){
                if(i->left!=nullptr) i=i->left;
                else{
                    i->left=new splay_tree(value);
                    i->left->parent=i;
                    i->left->splay(root);
                    return;
                }
            }
            else{
                if(i->right!=nullptr) i=i->right;
                else{
                    i->right=new splay_tree(value);
                    i->right->parent=i;
                    i->right->splay(root);
                    return;
                }
            }
        }
    }
    static inline void erase(iterator &root, iterator i, ll value){
        while(true){
            i->count--;
            if(value<(i->value)){
                if(i->left!=nullptr) i=i->left;
                else return;
            }
            else if(value>(i->value)){
                if(i->right!=nullptr) i=i->right;
                else return;
            }
            else{
                i->forced_splay();
                iterator left=i->left;
                iterator right=i->right;
                delete i;
                if(left==nullptr){
                    right->parent=nullptr;
                    root=right;
                    return;
                }
                if(right==nullptr){
                    left->parent=nullptr;
                    root=left;
                    return;
                }
                left->parent=nullptr;
                right->parent=nullptr;
                while(left->right!=nullptr) left=left->right;
                left->forced_splay();
                left->right=right;
                right->parent=left;
                left->fix();
                root=left;
                return;
            }
        }
    }
    static inline ll get(iterator &root, iterator i, ll value){
        ll res=root->count;
        while(true){
            if((i->value)>=value){
                if(i->left!=nullptr) i=i->left;
                else{
                    i->splay(root);
                    return res;
                }
            }
            else{
                if(i->left!=nullptr) res-=i->left->count;
                res--;
                if(i->right!=nullptr) i=i->right;
                else{
                    i->splay(root);
                    return res;
                }
            }
        }
    }
};
splay_tree::iterator tree;
set <ll> notable;
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    srand(time(NULL));
    read(n);
    read(m);
    read(bounty);
    read(increase);
    read(damage);
    FOR(i, 1, n){
        read(e[i].max_health);
        read(e[i].health);
        read(e[i].regen);
    }
    FOR(i, 1, m){
        read(ev[i].time);
        read(ev[i].enemy);
        read(ev[i].health);
        notable.insert(ev[i].time-1);
    }
    notable.insert(0);
    sort(ev+1, ev+m+1);
    tree=new splay_tree(-mask(60));
    FOR(i, 1, n){
        e[i].calculate(0);
        if(e[i].last!=-inf) notable.insert(e[i].last);
        splay_tree::insert(tree, tree, e[i].last);
    }
    ll ans=0, res;
    FOR(i, 1, m){
        while((!notable.empty())&&((*notable.begin())<ev[i].time)){
            res=splay_tree::get(tree, tree, *notable.begin());
            ans=max(ans, res*(bounty+(*notable.begin())*increase));
            notable.erase(notable.begin());
        }
        splay_tree::erase(tree, tree, e[ev[i].enemy].last);
        e[ev[i].enemy].health=ev[i].health;
        e[ev[i].enemy].calculate(ev[i].time);
        splay_tree::insert(tree, tree, e[ev[i].enemy].last);
        if(e[ev[i].enemy].last!=-inf) notable.insert(e[ev[i].enemy].last);
    }
    while(!notable.empty()){
        res=splay_tree::get(tree, tree, *notable.begin());
        ans=max(ans, res*(bounty+(*notable.begin())*increase));
        notable.erase(notable.begin());
    }
    if(increase){
        FOR(i, 1, n) if((e[i].max_health<=damage)||((e[i].regen==0)&&(e[i].health<=damage))){
            puts("-1");
            return 0;
        }
    }
    writeln(ans);
}