#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
#define __builtin_popcount __builtin_popcountll
using ll=long long; using ld=long double;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); const ld pi=acos(0)*2;
template <typename T> inline void read(T &x){char c; bool nega=0; while((!isdigit(c=getchar()))&&(c!='-')); if(c=='-'){nega=1; c=getchar();} x=c-48; while(isdigit(c=getchar())) x=x*10+c-48; if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10); putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){ putchar('-'); x=-x;} writep(x);}
template <typename T> inline void writeln(T x){write(x); putchar('\n');}
#define taskname "C"
string vowels="aeiou";
bool is_vowel[256];
class word{
public:
    string s;
    int c;
    char last;
    void input(){
        cin>>s;
        for(char x: s){
            if(is_vowel[x]){
                last=x;
                c++;
            }
        }
    }
} w[100001];
vector <int> *wv[1000001];
vector <int> ne;
int n;
bool check(int x){
    int cnt[256];
    int y=x;
    for(int a: ne){
        for(char c: vowels) cnt[c]=0;
        for(int id: *wv[a]) cnt[w[id].last]++;
        int re=0;
        for(char c: vowels){
//            bug(a);
//            bug(c);
//            bug(cnt[c]);
            int d=min(cnt[c]/2, x);
            x-=d;
            cnt[c]-=d*2;
            re+=cnt[c];
        }
        y-=re/2;
        if(x<=0&&y<=0) return 1;
    }
    return 0;
}
vector <pair <int, int>> f;
vector <pair <int, int>> s;
void output(pair <int, int> f, pair <int, int> s){
    cout<<w[f.first].s<<' '<<w[s.first].s<<'\n';
    cout<<w[f.second].s<<' '<<w[s.second].s<<'\n';
}
void make(int x){
    cout<<x<<'\n';
    vector <int> cnt[256];
    int y=x;
    for(int a: ne){
        for(char c: vowels) cnt[c].clear();
        for(int id: *wv[a]) cnt[w[id].last].pb(id);
        vector <int> re;
        for(char c: vowels){
            int d=min((int)cnt[c].size()/2, x);
            x-=d;
            FOR(i, 1, d){
                s.pb(mp(cnt[c].back(), cnt[c][cnt[c].size()-2]));
                cnt[c].pop_back();
                cnt[c].pop_back();
            }
            for(int t: cnt[c]) re.pb(t);
        }
        while(y&&re.size()>=2){
            y--;
            f.pb(mp(re.back(), re[re.size()-2]));
            re.pop_back();
            re.pop_back();
        }
        if(x==0&&y==0) break;
    }
    FFOR(i, 0, f.size()) output(f[i], s[i]);
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(char c: vowels) is_vowel[c]=1;
    cin>>n;
    FOR(i, 1, n) w[i].input();
    FOR(i, 1, n) if(wv[w[i].c]==nullptr) wv[w[i].c]=new vector <int>();
    FOR(i, 1, n) wv[w[i].c]->pb(i);
    FOR(i, 1, 1000000) if(wv[i]!=nullptr) ne.pb(i);
//    bug(check(1));
//bug(check(4));
    int low=0, high=n, mid, res=0;
    while(low<=high){
        mid=(low+high)/2;
        if(check(mid)){
            res=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    make(res);
}