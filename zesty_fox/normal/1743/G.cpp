// LUOGU_RID: 97304948
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

const int L=40;

int fib[L];
void init(){
    fib[0]=fib[1]=1;
    for(int i=2;i<L;i++)
        fib[i]=fib[i-1]+fib[i-2];
}

int calc(int x){
    for(int i=L-1;i>=2;i--)
        if(x>fib[i]) x-=fib[i];
    return x==1;
}

inline bool isfib(int x){
    return binary_search(fib,fib+L,x);
}

const int N=3010,MOD=998244353;

int n;

int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    init();n=rdi();
    
    i64 lst=1,sum=1;
    vector<pair<int,i64>> v,tmp;
    for(int i=1;i<=n;i++){
        static char s[N];
        scanf("%s",s+1);int len=strlen(s+1);
        for(int j=1;j<=len;j++){
            for(auto cur:v)
                if(calc(cur.fi+1)==s[j]-'0')
                    tmp.pb({cur.fi+1,cur.se});
            if(s[j]=='1') tmp.pb({1,lst});
            i64 val=sum-lst;
            for(auto cur:tmp)
                if(cur.fi>1&&isfib(cur.fi)) val-=cur.se;
            v.swap(tmp),tmp.clear();
            val%=MOD,(sum+=val)%=MOD,lst=val;
        }
        lst=(lst%MOD+MOD)%MOD;
        cout<<lst<<endl;
    }
    return 0;
}