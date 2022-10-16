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
int k, n;
string s[2500];
bool good[2500];
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>k>>n;
    FFOR(i, 0, k){
        cin>>s[i];
        FFOR(j, 0, i) if(s[i]==s[j]){
            i--;
            k--;
            break;
        }
        set <char> cs;
        for(char c: s[i]) cs.insert(c);
        good[i]=(cs.size()!=s[i].size());
    }
    if(k==1){
        swap(s[0][0], s[0][1]);
        cout<<s[0];
        return 0;
    }
    bool same=0;
    vector <int> pos_now;
    FFOR(y, 0, n){
        if(s[0][y]!=s[1][y]){
            pos_now.pb(y);
            if(pos_now.size()>4){
                cout<<"-1";
                return 0;
            }
        }
    }
    vector <int> pos;
    FFOR(i, 0, pos_now.size()) FFOR(j, 0, n) if(j!=pos_now[i]){
        if(s[0][pos_now[i]]==s[0][j]){
            if(same) continue;
            same=1;
        }
        swap(s[0][pos_now[i]], s[0][j]);
        FFOR(x, 1, k){
            pos.clear();
            FFOR(y, 0, n){
                if(s[x][y]!=s[0][y]){
                    pos.pb(y);
                    if(pos.size()>2) break;
                }
            }
            if((pos.size()>2)||(pos.size()==1)) goto line0;
            if(pos.size()==2){
                if((s[0][pos[0]]!=s[x][pos[1]])||(s[0][pos[1]]!=s[x][pos[0]])) goto line0;
            }
            else if(!good[x]) goto line0;
        }
        cout<<s[0];
        return 0;
        line0:;
        swap(s[0][pos_now[i]], s[0][j]);
    }
    swap(s[0], s[1]);
    same=0;
    FFOR(i, 0, pos_now.size()) FFOR(j, 0, n) if(j!=pos_now[i]){
        if(s[0][pos_now[i]]==s[0][j]){
            if(same) continue;
            same=1;
        }
        swap(s[0][pos_now[i]], s[0][j]);
        FFOR(x, 1, k){
            pos.clear();
            FFOR(y, 0, n){
                if(s[x][y]!=s[0][y]){
                    pos.pb(y);
                    if(pos.size()>2) break;
                }
            }
            if((pos.size()>2)||(pos.size()==1)) goto line1;
            if(pos.size()==2){
                if((s[0][pos[0]]!=s[x][pos[1]])||(s[0][pos[1]]!=s[x][pos[0]])) goto line1;
            }
            else if(!good[x]) goto line1;
        }
        cout<<s[0];
        return 0;
        line1:;
        swap(s[0][pos_now[i]], s[0][j]);
    }

    cout<<"-1";
}