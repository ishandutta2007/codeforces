#include <bits/stdc++.h>

using namespace std;

using i64=long long;
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
#define rdi64 read<i64>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

int n,k;
int cnt[26];
void solve(){
    n=rdi(),k=rdi();
    static char s[300];scanf("%s",s+1);
    for(int i=1;i<=n;i++) cnt[s[i]-'a']++;
    for(int i=1;i<=k;i++){
        for(int j=0;j<=25;j++){
            if(cnt[j]<i||j>=n/k){
                cout<<(char)(j+'a');
                break;
            }
        }
    }
    cout<<'\n';

    for(int i=0;i<26;i++)
        cnt[i]=0;
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    int T=rdi();
    while(T--)
        solve();
    return 0;
}