#include <iostream>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstring>

#include <algorithm>
#include <utility>

#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>

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

const int N=100010,INF=0x3f3f3f3f;

int n;
string s,s1;

bool ispalin(const string &s){
    for(int i=0;i<(int)s.length()/2;i++){
        if(s[i]!=s[s.length()-i-1]) return false;
    }
    return true;
}

int cnt[N],cnt1[N],ans;

void solve(){
    for(int i=0;i<26;i++) cnt[i]=0;
    ans=0;

    cin>>n>>s;
    for(int i=0;i<n;i++) cnt[s[i]-'a']++;

    for(int i=0;i<26;i++){
        if(!cnt[i]) continue;

        s1.clear();
        memset(cnt1,0,sizeof(int)*(n+2));

        for(int j=0,tot=0;j<n;j++){
            if(s[j]!=i+'a') s1+=s[j],tot++;
            else cnt1[tot]++;
        }
        if(!ispalin(s1)) continue;
        int sum=0;
        for(int j=0;j+j<=n-cnt[i];j++){
            if(j+j==n-cnt[i]) sum+=cnt1[j];
            else sum+=min(cnt1[j],cnt1[n-cnt[i]-j])*2;
        }
        ans=max(ans,n-cnt[i]+sum);
    }
    cout<<(ans?(n-ans):-1)<<'\n';
}

int T;
int main(){
    ios::sync_with_stdio(0);
    cin>>T;
    while(T--) solve();
    return 0;
}