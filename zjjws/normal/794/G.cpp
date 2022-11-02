#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>
#define LL long long
using namespace std;
inline LL rin()
{
    LL s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)return -s;
    return s;
}
const int N=6e5+3;
const int M=1e9+7;
inline int prpr(int x,int y){return 1LL*x*y%M;}
inline int ksm(int x,int y){int ans=1;for(;y;y>>=1){if(y&1)ans=prpr(ans,x);x=prpr(x,x);}return ans;}
int pw[N];
int sl[N];
int sr[N];
int mu[N];
bool pri[N];
vector<int>prime;
int Gura_do_not_know_my_exist;
//El Psy Congroo
int CS[N];
inline int cs(int n)
{
    if(CS[n])return CS[n];
    int ans=0;
    for(int l=1,r,nw;l<=n;l=r+1)r=n/(nw=n/l),ans=(ans+prpr(mu[r]-mu[l-1],prpr(nw,nw)))%M;
    return CS[n]=ans;
}
inline void init(int n)
{
    pw[0]=1;for(int i=1;i<N;i++)pw[i]=(pw[i-1]<<1)%M;
    pw[0]=0;for(int i=2;i<N;i++)pw[i]=(pw[i-1]+pw[i])%M;
    sl[0]=1;for(int i=1;i<N;i++)sl[i]=prpr(sl[i-1],i);sr[N-1]=ksm(sl[N-1],M-2);
    sr[0]=1;for(int i=N-2;i>=1;i--)sr[i]=prpr(sr[i+1],i+1);
    mu[1]=1;
    for(int i=2,now;i<N;i++)
    {
        if(!pri[i])prime.push_back(i),mu[i]=-1;
        for(vector<int>::iterator j=prime.begin();j!=prime.end();j++){if((now=(*j)*i)>=N)break;pri[now]=true;if(i%(*j)==0)break;mu[now]=-mu[i];}
        mu[i]+=mu[i-1];
    }
    for(int l=1,r,nw;l<=n;l=r+1)
    {
        r=n/(nw=n/l);
        Gura_do_not_know_my_exist+=prpr(pw[r]-pw[l-1],cs(nw));
        Gura_do_not_know_my_exist%=M;
    }
    return;
}
inline int C(int a,int b){return (a<b||b<0)?(0):(prpr(sl[a],prpr(sr[b],sr[a-b])));}
inline int Gcd(int a,int b){return (!b)?(a):(Gcd(b,a%b));}
int n;
int ans;
string S,T;
inline void work(int i,int a,int b,int x,int y)
{
    a+=i;b+=i;
    if(!a&&!b){ans=(ans+prpr(Gura_do_not_know_my_exist,C(x+y,i+y)))%M;return;}
    if((1LL*a*b)<=0)return;
    int c=Gcd(a,b);a/=c;b/=c;
    ans=(ans+prpr(pw[n/max(a,b)],C(x+y,i+y)))%M;
    return;
}
inline bool check(int s,int t)
{
    if(s!=t)return false;for(int i=0;i<s;i++)if(S[i]!=T[i]||S[i]=='?'||T[i]=='?')return false;
    printf("%d\n",prpr(pw[n],pw[n]));return true;
}
int main()
{
    int s,t,a,b,x,y;a=b=x=y=0;
    cin>>S>>T;s=S.length();t=T.length();n=rin();init(n);
    if(check(s,t))return 0;
    for(int i=0;i<s;i++){if(S[i]=='A')a++;if(S[i]=='B')b--;if(S[i]=='?')x++;}
    for(int i=0;i<t;i++){if(T[i]=='A')a--;if(T[i]=='B')b++;if(T[i]=='?')y++;}
    for(int i=-y;i<=x;i++)work(i,a,b+y-x,x,y);
    if(s==t)
    {
        int cut=1;
        for(int i=0;i<s;i++)
        {
            if(S[i]=='?'&&T[i]=='?'){cut=(cut<<1)%M;continue;}
            if(S[i]=='?'||T[i]=='?'||S[i]==T[i])continue;
            cut=0;break;
        }
        ans=(ans+prpr(prpr(pw[n],pw[n])-Gura_do_not_know_my_exist,cut))%M;
        ans=(ans+M)%M;
    }
    printf("%d\n",ans);
    return 0;
}