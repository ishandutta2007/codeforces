#include <bits/stdc++.h>

using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x*10)+(ch^48),ch=getchar();
    return !f?x:-x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=100010;

int n;
string s[N];
bool flg;

void solve(){
    n=rdi();flg=0;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++) if(s[i].front()==s[i].back()) {flg=1;break;}
    if(!flg){
        set<string> s1[4];
        for(int i=n;i>=1;i--){
            if(s[i].length()==2){
                string _s=s[i];reverse(_s.begin(),_s.end());
                for(int j:{2,3})
                    if(s1[j].find(_s)!=s1[j].end()) {flg=1;break;}
            }
            else{
                string _s=s[i];reverse(_s.begin(),_s.end());
                if(s1[3].find(_s)!=s1[3].end()) {flg=1;break;}
                _s=s[i].substr(0,2);reverse(_s.begin(),_s.end());
                if(s1[2].find(_s)!=s1[2].end()) {flg=1;break;}
            }
            if(s[i].length()==3) s1[3].insert(s[i].substr(1,2)),s1[3].insert(s[i]);
            else s1[2].insert(s[i]);
        }
    }
    puts(flg?"YES":"NO");
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    int T=rdi();
    while(T--) solve();
    return 0;
}