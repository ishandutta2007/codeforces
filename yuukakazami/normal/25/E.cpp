#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <set>
#include <map>
#include <cstring>
#include <time.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define Debug(x) cout<<#x<<"="<<x<<endl;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define tr(e,x) for(typeof(x.begin()) e=x.begin();e!=x.end();e++)
#define printTime cout<<"Time:"<<pre-clock()<<endl;pre=clock();
const int inf=~0U>>1,seed=13331,maxn=100000+10,Log=20;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ull P[Log];
struct String
{
    char A[maxn];
    ull Hash[maxn][Log];
    int n;
    void doit()
    {
        rep(e,Log)
        {
            rep(i,maxn)if(i+(1<<e)<=n)
            {
                if(!e)Hash[i][e]=A[i];
                else Hash[i][e]=Hash[i][e-1]*P[e-1]+Hash[i+(1<<(e-1))][e-1];
            }
        }
    }
}Str[3];
int Lcp(String&A,int a,String&B,int b)
{
    int oa=a;
    for(int i=Log-1;i>=0;i--)
    {
        int tmp=1<<i;
        if(a+tmp<=A.n&&b+tmp<=B.n)
        {
            if(A.Hash[a][i]==B.Hash[b][i])
                a+=tmp,b+=tmp;
        }
    }
    return a-oa;
}
istream& operator>>(istream&in,String&str)
{
    scanf("%s",str.A);
    str.n=strlen(str.A);
}
bool Contain(String&A,String&B)
{
    rep(i,A.n)
        if(Lcp(A,i,B,0)==B.n)return true;
    return false;
}
int CalDist(String&A,String&B)
{
    rep(i,A.n)
        if(Lcp(A,i,B,0)==A.n-i)
            return A.n-i;
    return 0;
}
bool V[3]={};
int Dist[3][3],ans=0;
void Dfs(int x,int gone)
{
    V[x]=true;bool find=false;
    rep(i,3)if(!V[i])
    {
        find=true;
        Dfs(i,gone+Dist[x][i]);
    }
    if(!find)ans=max(ans,gone);
    V[x]=false;
}
int main()
{
    //freopen("in","r",stdin);
    P[0]=seed;rep(i,Log-1)P[i+1]=P[i]*P[i];
    rep(i,3)cin>>Str[i],Str[i].doit();
    rep(i,3)rep(j,3)if(j!=i)
        if(Contain(Str[j],Str[i]))
            V[i]=true;
        else
            Dist[i][j]=CalDist(Str[i],Str[j]);
    rep(i,3)if(!V[i])Dfs(i,0);
    int ret=0;rep(i,3)if(!V[i])ret+=Str[i].n;
    ret-=ans;
    if(!ret)cout<<Str[0].n<<endl;
    else cout<<ret<<endl;
}