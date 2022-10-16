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
int n, m;
class query{
public:
    int l, r, k;
    void input(){
        read(l);
        read(r);
        read(k);
    }
};
vector <query> q;
set <pair <int, int> > s;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(m);
    q.resize(m);
    for(auto &t: q) t.input();
    int ans=n;
    for(auto t: q){
        ///remove
        int l=t.l;
        int r=t.r;
        while(!s.empty()){
            set <pair <int, int> >::iterator it=s.lower_bound(mp(l, 0));
            if(it==s.end()) break;
            if(it->second>r) break;
            ans+=it->second-it->first+1;
            s.erase(it);
        }
        if(!s.empty()){
            set <pair <int, int> >::iterator it=s.lower_bound(mp(l, 0));
            if(it!=s.end()){
                pair <int, int> p=*it;
                s.erase(it);
                if(p.first<=r){
                    ans+=r-p.first+1;
                    p.first=r+1;
                }
                s.insert(p);
            }
            it=s.lower_bound(mp(l, 0));
            if(it!=s.begin()){
                it--;
                pair <int, int> p=*it;
                if(p.second>=l){
                    s.erase(it);
                    if(p.second>r){
                        ans+=r-l+1;
                        s.insert(mp(p.first, l-1));
                        s.insert(mp(r+1, p.second));
                    }
                    else{
                        ans+=p.second-l+1;
                        p.second=l-1;
                        s.insert(p);
                    }
                }
            }
        }
        if(t.k==1){
            s.insert(mp(l, r));
            ans-=r-l+1;
        }
        writeln(ans);
    }
}