#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef __int128_t i128;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}

template<typename T>
inline void write(T x){
    if(!x) {return (void)putchar('0');}
    static int bit[255],tp;tp=0;
    while(x) bit[++tp]=x%10,x/=10;
    while(tp) putchar(bit[tp--]+'0');
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=600010;

int n,nxt[N],f[N];
char s[N];
i128 ans;

i128 sum;
map<int,int> m;
void chkmin(int x){
    auto it=m.upper_bound(x);
    while(it!=m.end()){
        sum-=(i64)(it->fi-x)*it->se;
        m[x]+=it->se,m.erase(it++);
    }
}

void insert(int x) {sum+=x,m[x]++;}
void erase(int x) {sum-=x;if(!(--m[x])) m.erase(x);}

int st[N],tp,w[N];

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();
    for(int i=1,j=0;i<=n;i++){
        scanf("%s %d",&s[i],&w[i]);
        s[i]=(s[i]-'a'+ans)%26+'a',w[i]=w[i]^(ans&((1<<30)-1));
        
        if(i>1){
            while(j&&s[j+1]!=s[i]) j=nxt[j];
            if(s[j+1]==s[i]) ++j;
            nxt[i]=j;

            if(s[i]==s[nxt[i-1]+1]) f[i-1]=f[nxt[i-1]];
            else f[i-1]=nxt[i-1];
            int x=i-1;
            while(x){
                if(s[x+1]==s[i]) x=f[x];
                else erase(w[*lower_bound(st+1,st+tp+1,i-x)]),x=nxt[x];
            }
            if(s[1]==s[i]) insert(w[i]);
            chkmin(w[i]),ans+=sum;
        }
        
        while(tp&&w[st[tp]]>=w[i]) --tp;
        st[++tp]=i,ans+=w[st[1]];

        write(ans);puts("");
    }
    return 0;
}