#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=100010,M=26;
int n,ans;
char a[N],b[N];

set<int> pos[M];
void solve(){
    n=rdi();
    scanf("%s%s",a+1,b+1);

    for(int i=0;i<M;i++) pos[i].clear();
    for(int i=1;i<=n;i++){
        if(a[i]>b[i]) {puts("-1");return;}
        if(a[i]!=b[i]) pos[a[i]-'a'].insert(i);
    }

    int cur=0,sum=0;
    while(1){
        while(cur<M){
            for(auto it=pos[cur].begin();it!=pos[cur].end();){
                if(b[*it]-'a'==cur) it++,pos[cur].erase(prev(it));
                else it++;
            }
            if(pos[cur].empty()) cur++;
            else break;
        }
        if(cur>=M) break;

        int minx=M;
        for(auto tmp:pos[cur]) minx=min(minx,b[tmp]-'a');
        for(auto tmp:pos[cur]) pos[minx].insert(tmp);
        pos[cur].clear(),sum++;
    }
    printf("%d\n",sum);
}

int T;
int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    T=rdi();
    while(T--) solve();
    return 0;
}