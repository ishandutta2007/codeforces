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
#define taskname "129D"
class suffix_array{
public:
    string s;
    vector <int> sa;
    vector <int> rank;
    vector <int> lcp;
    vector <int> temp;
    int n;
    suffix_array(string str){
        s=str;
        n=s.size();
        FFOR(i, 0, n) sa.pb(i);
        sort(sa.begin(), sa.end(), [this](int a, int b){
            return s[a]<s[b];
        });
        rank.resize(n, 0);
        temp.resize(n, 0);
        rank[sa[0]]=0;
        FFOR(i, 1, n) rank[sa[i]]=rank[sa[i-1]]+(s[sa[i-1]]<s[sa[i]]);
        for(int length=1; rank[sa.back()]+1!=n; length*=2){
            auto cmp=[this, length](int a, int b){
                if(rank[a]!=rank[b]) return rank[a]<rank[b];
                a+=length;
                b+=length;
                if((a>=n)||(b>=n)) return a>b;
                return rank[a]<rank[b];
            };
            sort(sa.begin(), sa.end(), cmp);
            temp[sa[0]]=0;
            FFOR(i, 1, n) temp[sa[i]]=temp[sa[i-1]]+cmp(sa[i-1], sa[i]);
            rank=temp;
        }
        lcp.resize(n, 0);
        s+='#';
        FFOR(i, 0, n){
            if(i==sa.back()) continue;
            lcp[rank[i]]=i?max(0, lcp[rank[i-1]]-1):0;
            while(s[i+lcp[rank[i]]]==s[sa[rank[i]+1]+lcp[rank[i]]]) lcp[rank[i]]++;
        }
        s.pop_back();
    }
    string find(int cnt){///find cnt-th string (cnt<=10^5)
        FFOR(i, 0, n){
            int f=i?lcp[i-1]:0;
            while(f<n-sa[i]){
                cnt--;
                {
                    int j=i;
                    while((j+1<n)&&(lcp[j]>f)){
                        cnt--;
                        j++;
                    }
                }
                if(cnt<=0){
                    string res;
                    FOR(j, 0, f) res+=s[sa[i]+j];
                    return res;
                }
                f++;
            }
        }
        return "No such line.";
    }
};
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    string s;
    int k;
    cin>>s>>k;
    suffix_array A(s);
    cout<<A.find(k)<<'\n';
}