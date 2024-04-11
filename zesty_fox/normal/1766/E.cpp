// LUOGU_RID: 97280224
#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using u64=unsigned long long;
using db=double;
using pii=pair<int,int>;
using vi=vector<int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch-'0'),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back

int n;
i64 ans;

const int S=16;
const pii tr[S][4]={
{{0,1},{1,1},{2,1},{3,1}},
{{1,1},{1,0},{4,1},{3,0}},
{{2,1},{5,1},{2,0},{3,0}},
{{3,1},{1,0},{2,0},{3,0}},
{{4,1},{4,0},{4,0},{6,0}},
{{5,1},{5,0},{5,0},{7,0}},
{{6,1},{4,0},{8,0},{6,0}},
{{7,1},{9,0},{5,0},{7,0}},
{{8,1},{10,1},{8,0},{6,0}},
{{9,1},{9,0},{11,1},{7,0}},
{{10,1},{10,0},{10,0},{12,0}},
{{11,1},{11,0},{11,0},{13,0}},
{{12,1},{14,0},{10,0},{12,0}},
{{13,1},{11,0},{15,0},{13,0}},
{{14,1},{14,0},{14,0},{12,0}},
{{15,1},{15,0},{15,0},{13,0}}};

int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    n=rdi();
    static int cnt[S];
    for(int i=1;i<=n;i++){
        int cur=rdi();

        ++cnt[0];
        static int tmp[S];
        for(int s=0;s<S;s++){
            tmp[tr[s][cur].fi]+=cnt[s];
            if(tr[s][cur].se) ans+=(i64)cnt[s]*(n-i+1);
        }
        copy(tmp,tmp+S,cnt),fill(tmp,tmp+S,0);
    }
    cout<<ans<<endl;
    return 0;
}