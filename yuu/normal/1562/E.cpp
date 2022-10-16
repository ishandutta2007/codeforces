#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int sa[5001];
int r[5001];
int br[5001];
int lcp[5001];
int f[5001][16];
int dp[5001];
int get_lcp(int pos_a, int pos_b){
    int a=r[pos_a];
    int b=r[pos_b];
    if(a>b) swap(a, b);
    b--;
    int len=b-a+1;
    int lg=__lg(len);
    return min(f[a][lg], f[b-(1<<lg)+1][lg]);
}
void solve(){
    cin>>n>>s;
    s='0'+s;
    for(int i=1; i<=n; i++) sa[i]=i;
    sort(sa+1, sa+n+1, [](const int& a, const int& b){
        return (s[a]<s[b])||((s[a]==s[b])&&(a>b));
    });
    r[sa[1]]=1;
    for(int i=2; i<=n; i++) r[sa[i]]=r[sa[i-1]]+(s[sa[i]]!=s[sa[i-1]]);
    for(int half=1, length=2; half<=n; length*=2, half*=2){
        sort(sa+1, sa+n+1, [&half](const int& a, const int& b){
            if(r[a]!=r[b]) return r[a]<r[b];
            if(a+half>n){
                return a>b;
            }
            else if(b+half>n) return false;
            return r[a+half]<r[b+half];
        });
        for(int i=1; i<=n; i++) br[sa[i]]=r[sa[i]];
        r[sa[1]]=1;
        for(int i=2; i<=n; i++){
            r[sa[i]]=r[sa[i-1]];
            if(br[sa[i]]!=br[sa[i-1]]){
                r[sa[i]]++;
                continue;
            }
            if(sa[i-1]+half>n){
                r[sa[i]]++;
                continue;
            }
            r[sa[i]]+=br[sa[i]+half]>br[sa[i-1]+half];
        }
    }
    for(int i=2; i<=n; i++) r[sa[i]]=i;
    for(int i=1; i<n; i++){
        int l=0;
        while((sa[i]+l<=n)&&(sa[i+1]+l<=n)&&(s[sa[i]+l]==s[sa[i+1]+l])) l++;
        lcp[i]=l;
    }
    for(int i=1; i<n; i++) f[i][0]=lcp[i];
    for(int i=1, length=2, half=1; length<n; i++, length*=2, half*=2){
        for(int j=1; j+length<=n; j++){
            f[j][i]=min(f[j][i-1], f[j+half][i-1]);
        }
    }
    for(int i=0; i<=n; i++) dp[i]=0;
    for(int i=1; i<=n; i++){
        dp[i]=n-i+1;
        for(int j=1; j<i; j++) if(r[i]>r[j]){
            int lcp=get_lcp(j, i);
            int up=0;
            dp[i]=max(dp[i], dp[j]+(n-i+1)-lcp);
        }
    }
    cout<<*max_element(dp+1, dp+n+1)<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) solve();
}