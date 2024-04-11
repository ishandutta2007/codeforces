#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
#define LL long long
using namespace std;
inline int rin()
{
    int s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)s=-s;
    return s;
}

const int N=1e5+3;
const int S=1e6+3;
const int M=1e9+7;

inline int prpr(int x,int y){return 1LL*x*y%M;}
inline int ksm(int x,int y){int ans=1;for(;y;y>>=1){if(y&1)ans=prpr(ans,x);x=prpr(x,x);}return ans;}

int n,q;
string t;
string s[22];
inline void Read()
{
    n=rin();q=rin();
    cin>>s[0];
    cin>>t;
    return;
}

const int Mod=19260817;
const int K=37;

int sl[S<<1];
inline int Hash_add(int x,int y){return (x+y)%Mod;}
inline int Hash_prpr(int x,int y){return 1LL*x*y%Mod;}
inline int Hash_check(int *a,int l,int r){return (l>r)?(0):((a[r]-Hash_prpr(a[l-1],sl[r-l+1])+Mod)%Mod);}

int pro[N];
int inv[N];

struct gyq
{
    vector<int>num;
    vector<int>add;
    inline void push(int num_,int val_)
    {
        num.push_back(num_);
        if(add.empty())add.push_back(val_);
        else add.push_back((add.back()+val_)%M);
        return;
    }
    inline int cheak(int ed)
    {
        int l=0,r=num.size()-1;
        int ans=0;
        for(;l<=r;)
        {
            int mid=(l+r)>>1;
            if(num[mid]<=ed)ans=add[mid],l=mid+1;
            else r=mid-1;
        }
        return ans;
    }
}d[26];
inline void init()
{
    Read();
    for(int i=1;s[i-1].length()<1e6;i++)s[i]=s[i-1]+t[i-1]+s[i-1];

    sl[0]=1;
    for(int i=1;i<(S<<1);i++)sl[i]=Hash_prpr(sl[i-1],K);
    
    pro[0]=inv[0]=1;
    for(int i=1;i<=n;i++)pro[i]=prpr(pro[i-1],2);
    inv[n]=ksm(pro[n],M-2);
    for(int i=n-1;i>=1;i--)inv[i]=prpr(inv[i+1],2);

    for(int i=1;i<=n;i++)d[t[i-1]-'a'].push(i,pro[n-i]);
    return;
}

string Alpha;
int lens;
int num;
int L;

int Beta[S];
int Zeta[S<<1];
int Gamma[26];

LL ans;
inline int work()
{
    memset(Gamma,0,sizeof(Gamma));
    int i,j,k;
    num=rin();
    cin>>Alpha;
    lens=Alpha.length();
    for(i=0;s[i].length()<lens&&i<num;i++);if(s[i].length()<lens)return 0;
    for(j=1;j<=lens;j++)Beta[j]=Hash_add(Hash_prpr(Beta[j-1],K),Alpha[j-1]-'a'+1);
    for(j=1,L=s[i].length(),ans=0;j<=L;j++)
    {
        Zeta[j]=Hash_add(Hash_prpr(Zeta[j-1],K),s[i][j-1]-'a'+1);
        if(j>=lens&&Hash_check(Zeta,j-lens+1,j)==Beta[lens])ans++;
    }
    for(k=1;k<=lens;k++)Gamma[Alpha[k-1]-'a']+=(Hash_add(Hash_prpr(Hash_add(Hash_prpr(Hash_check(Zeta,L-k+2,L),K),Alpha[k-1]-'a'+1),sl[lens-k]),Zeta[lens-k])==Beta[lens]);
    ans=prpr(ans,ksm(2,num-i));
    for(k=0;k<26;k++)ans=(ans+prpr(Gamma[k],prpr(d[k].cheak(num)-d[k].cheak(i),inv[n-num])))%M;
    return (ans%M+M)%M;
}

int main()
{
    init();
    for(;q;q--)printf("%d\n",work());
    return 0;
}