#include <bits/stdc++.h> //qaq
using namespace std;
typedef long long ll;
const int MAXSIZE=30000020;
int bufpos;
char buf[MAXSIZE];
#define NEG 0
void init(){
    #ifdef LOCAL
        freopen("746F.txt","r",stdin);
    #endif
    buf[fread(buf,1,MAXSIZE,stdin)]='\0';
    bufpos=0;
}
#if NEG
int readint(){
    bool isneg;
    int val=0;
    for(;!isdigit(buf[bufpos]) && buf[bufpos]!='-';bufpos++);
    bufpos+=(isneg=buf[bufpos]=='-');
    for(;isdigit(buf[bufpos]);bufpos++)
        val=val*10+buf[bufpos]-'0';
    return isneg?-val:val;
}
#else
int readint(){
    int val=0;
    for(;!isdigit(buf[bufpos]);bufpos++);
    for(;isdigit(buf[bufpos]);bufpos++)
        val=val*10+buf[bufpos]-'0';
    return val;
}
#endif
char readchar(){
    for(;isspace(buf[bufpos]);bufpos++);
    return buf[bufpos++];
}
int readstr(char* s){
    int cur=0;
    for(;isspace(buf[bufpos]);bufpos++);
    for(;!isspace(buf[bufpos]);bufpos++)
        s[cur++]=buf[bufpos];
    s[cur]='\0';
    return cur;
}
const int maxn=200002;
struct segtree{
    int n;
    int cnt[40002],sum[40001];
    int p,v0,v1;
    int qwq;
    void update(int o,int l,int r){
        if (l==r){
            cnt[o]+=v0;
            sum[o]+=v1;
            return;
        }
        int mid=(l+r)/2;
        if (p<=mid)
            update(o*2,l,mid);
        else update(o*2+1,mid+1,r);
        cnt[o]=cnt[o*2]+cnt[o*2+1];
        sum[o]=sum[o*2]+sum[o*2+1];
    }
    void add(int x){
        qwq+=x;
        p=x,v0=1,v1=x/2;
        update(1,1,n);
    }
    void del(int x){
        qwq-=x;
        p=x,v0=-1,v1=-(x/2);
        update(1,1,n);
    }
    int query(int k){
        int o=1,l=1,r=n,res=0;
        while(l<r){
            int mid=(l+r)/2;
            if (k>cnt[o*2+1])
                k-=cnt[o*2+1],res+=sum[o*2+1],o=o*2,r=mid;
            else o=o*2+1,l=mid+1;
        }
        if (k>cnt[o])
            return qwq-res-sum[o];
        else return qwq-res-sum[o]/cnt[o]*k;
    }
}t;
int a[maxn],qwq[maxn],sum[maxn];
int main(){
    init();
    int n=readint(),w=readint(),k=readint();
    for(int i=1;i<=n;i++)
        a[i]=readint();
    for(int i=1;i<=n;i++)
        qwq[i]=readint();
    for(int i=n;i;i--)
        sum[i]=sum[i+1]+a[i];
    t.n=10000;
    int j=0,ans=0;
    for(int i=1;i<=n;i++){
        while(t.query(w)<=k){
            j++;
            if (j>n)
                break;
            t.add(qwq[j]);
        }
        ans=max(ans,sum[i]-sum[j]);
        t.del(qwq[i]);
    }
    printf("%d",ans);
}