#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define FFOR(i, j, k) for(int i=j; i<k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
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
#define taskname "B"
string s, t;
int n;
bool good[256];
int poss=-1;
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    cin>>s;
    for(char c: s) good[c]=1;
    cin>>s>>n;;
    FFOR(i, 0, s.size()) if(s[i]=='*') {poss=i; break;}
    FOR(tcase, 1, n){
        cin>>t;
        if(poss==-1){
            if(t.size()!=s.size()) puts("NO");
            else{
                FFOR(i, 0, s.size()) if(s[i]!='?'){
                    if(s[i]!=t[i]){
                        puts("NO");
                        goto line0;
                    }
                }
                else if(!good[t[i]]){
                    puts("NO");
                    goto line0;
                }
                puts("YES");
                line0:;
            }
        }
        else{
            if(s.size()>t.size()){
                if(s.size()==t.size()+1){
                    FFOR(i, 0, poss) if(s[i]!='?'){
                        if(s[i]!=t[i]){
                            puts("NO");
                            goto line05;
                        }
                    }
                    else if(!good[t[i]]){
                        puts("NO");
                        goto line05;
                    }
                    FFOR(i, poss+1, s.size())if(s[i]!='?'){
                        if(s[i]!=t[i-1]){
                            puts("NO");
                            goto line05;
                        }
                    }
                    else if(!good[t[i-1]]){
                        puts("NO");
                        goto line05;
                    }
                    puts("YES");
                    line05:;
                }
                else puts("NO");
            }
            else{
                int i, j;
                FFOR(i, 0, poss) if(s[i]!='?'){
                    if(s[i]!=t[i]){
                        puts("NO");
                        goto line1;
                    }
                }
                else if(!good[t[i]]){
                    puts("NO");
                    goto line1;
                }
                i=s.size()-1;
                j=t.size()-1;
                while(i>poss){
                    if(s[i]!='?'){
                        if(s[i]!=t[j]){
                            puts("NO");
                            goto line1;
                        }
                    }
                    else if(!good[t[j]]){
                        puts("NO");
                        goto line1;
                    }
                    i--;
                    j--;
                }
                DFOR(i, j, poss){
                    if(good[t[i]]){
                        puts("NO");
                        goto line1;
                    }
                }
                puts("YES");
                line1:;
            }
        }
    }

}