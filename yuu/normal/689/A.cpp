#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
typedef long long ll;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar()))
        x=x*10+c-48;
    if(nega)
        x=-x;
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
#define taskname "A"
pair <int, int> pos[10];
bool good[5][5];
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    int n;
    string s;
    cin>>n;
    cin>>s;
    n--;
    FOR(i, 1, 4)
        FOR(j, 1, 3)
            good[i][j]=1;
    good[4][1]=good[4][3]=0;
    FOR(i, 0, n){
        if(s[i]=='0') pos[i]=mp(4, 2);
        else if(s[i]<'4') pos[i]=mp(1, s[i]-48);
        else if(s[i]<'7') pos[i]=mp(2, s[i]-51);
        else pos[i]=mp(3, s[i]-54);
    }
    FOR(i, 0, n)
        if(!good[pos[i].first+1][pos[i].second]) goto line1;
    puts("NO");
    return 0;
    line1:;
    FOR(i, 0, n)
        if(!good[pos[i].first-1][pos[i].second]) goto line2;
    puts("NO");
    return 0;
    line2:;
    FOR(i, 0, n)
        if(!good[pos[i].first][pos[i].second+1]) goto line3;
    puts("NO");
    return 0;
    line3:;
    FOR(i, 0, n)
        if(!good[pos[i].first][pos[i].second-1]) goto line4;
    puts("NO");
    return 0;
    line4:;
    puts("YES");
}