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
#define taskname "D"
int n;
string s;
int cnt[256];
int get_min_cost(int a, int b, int c){
    if(a>b) swap(a, b);
    if(b>c) swap(b, c);
    if(a>b) swap(a, b);
    if(a>0||c<0) return 1e9;
    int d=min(abs(a), abs(c));
    int ans=d;
    a+=d;
    c-=d;
    if(a==0) a=c;
    if(a>b) swap(a, b);
    if(abs(a)>abs(b)) return 1e9;
    ans+=abs(a);
    return ans;
}
int atob[256][256];
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    cin>>s;
    for(char &c: s) cnt[c]++;
    cnt['0']-=n/3;
    cnt['1']-=n/3;
    cnt['2']-=n/3;
    string temp="012";
    sort(temp.begin(), temp.end(), [](char a, char b){
        return cnt[a]<cnt[b];
    });
    if(cnt[temp[1]]>0){
        atob[temp[1]][temp[0]]=cnt[temp[1]];
        atob[temp[2]][temp[0]]=cnt[temp[2]];
    }
    else{
        atob[temp[2]][temp[0]]=-cnt[temp[0]];
        atob[temp[2]][temp[1]]=-cnt[temp[1]];
    }
    FOR(i, '0', '2') FOR(j, '0', i) if(atob[i][j]){
        for(auto &c: s) if((c==i)&&atob[i][j]){
            c=j;
            atob[i][j]--;
        }
    }
    reverse(s.begin(), s.end());
    FOR(i, '0', '2') DFOR(j, '2', i) if(atob[i][j]){
        for(auto &c: s) if((c==i)&&atob[i][j]){
            c=j;
            atob[i][j]--;
        }
    }
    reverse(s.begin(), s.end());
    cout<<s;
}