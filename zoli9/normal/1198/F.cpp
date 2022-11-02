#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
int n;
int t[100009];
int csoport[100009];
vector<int> primes[2];
vector<int> multpl[2];
vector<int> crucial; //index
vector<pii> lefed;
vector<vector<int> > dp;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int proba;
void checking()
{
    int g1=-1;
    int g2=-1;
    for(int i=1; i<=n; i++)
    {
        if(csoport[i]==1)
        {
            if(g1==-1)
            {
                g1=t[i];
            }
            else
            {
                g1=__gcd(g1, t[i]);
            }
        }
        else
        {
            if(g2==-1)
            {
                g2=t[i];
            }
            else
            {
                g2=__gcd(g2, t[i]);
            }
        }
    }
    if(g1==1 && g2==1)
    {
        cout<<"YES"<<endl;
        for(int i=1; i<=n; i++)
        {
            cout<<csoport[i]<<" ";
        }
        cout<<endl;
        exit(0);
    }
}
void bt(int x)
{
    if(x>n)
    {
        checking();
        return;
    }
    csoport[x]=1;
    bt(x+1);
    csoport[x]=2;
    bt(x+1);
}
void bruteforce()
{
    bt(1);
    cout<<"NO"<<endl;
    exit(0);
}
int randomnum(int maxi)
{
    return uniform_int_distribution<int>(0, maxi-1)(rng);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
        csoport[i]=1;
    }
    if(n<=20)
    {
        bruteforce();
        return 0;
    }
    while(1)
    {
        proba++;
        if(proba>20) break;
        int id1=randomnum(n)+1;
        int id2=randomnum(n)+1;
        csoport[id1]=1;
        csoport[id2]=2;
        while(id1==id2)
        {
            id2=randomnum(n)+1;
        }
        primes[0].clear();
        primes[1].clear();
        multpl[0].clear();
        multpl[1].clear();
        crucial.clear();
        crucial.push_back(0);
        lefed.clear();
        lefed.push_back({0, 0});
        int num1=t[id1];
        int num2=t[id2];
        for(int i=2; i*i<=num1; i++)
        {
            if(num1%i==0)
            {
                primes[0].push_back(i);
                while(num1%i==0) num1/=i;
            }
        }
        if(num1>1) primes[0].push_back(num1);
        for(int i=2; i*i<=num2; i++)
        {
            if(num2%i==0)
            {
                primes[1].push_back(i);
                while(num2%i==0) num2/=i;
            }
        }
        if(num2>1) primes[1].push_back(num2);
        int maxk=max(primes[0].size(), primes[1].size());
        multpl[0].assign(primes[0].size(), 0);
        multpl[1].assign(primes[1].size(), 0);
        for(int i=1; i<=n; i++)
        {
            if(i==id1 || i==id2) continue;
            bool valuable=false;
            int cover0=0;
            for(int j=0; j<primes[0].size(); j++)
            {
                if(t[i]%primes[0][j]!=0)
                {
                    cover0+=(1<<(j));
                    if(multpl[0][j]<2*maxk)
                    {
                        valuable=true;
                        multpl[0][j]++;
                    }
                }
            }
            int cover1=0;
            for(int j=0; j<primes[1].size(); j++)
            {
                if(t[i]%primes[1][j]!=0)
                {
                    cover1+=(1<<(j));
                    if(multpl[1][j]<2*maxk)
                    {
                        valuable=true;
                        multpl[1][j]++;
                    }
                }
            }
            if(valuable)
            {
                crucial.push_back(i);
                lefed.push_back({cover0, cover1});
            }
        }

        int C=crucial.size();
        int P0=primes[0].size();
        int P1=primes[1].size();

        /*for(int i=0; i<P0; i++)
        {
            cout<<primes[0][i]<<" : ";
        }
        cout<<endl;
        for(int i=0; i<P1; i++)
        {
            cout<<primes[1][i]<<" : ";
        }
        cout<<endl;*/
        int bitpos=(1<<(P0+P1));
        dp.assign(C, vector<int>(bitpos, 0));
        dp[0][0]=1;
        for(int i=1; i<C; i++)
        {
            for(int b=0; b<bitpos; b++)
            {
                if(dp[i-1][b-(b&lefed[i].F)]>0) dp[i][b]=1;
                else if(dp[i-1][b-(b&(lefed[i].S*(1<<(P0))))]>0) dp[i][b]=2;
            }
        }
        if(dp[C-1][bitpos-1]==0) continue; // fail
        int b=bitpos-1;
        for(int i=C-1; i>=1; i--)
        {
            if(dp[i][b]==1)
            {
                csoport[crucial[i]]=1;
                b-=(b&lefed[i].F);
            }
            else
            {
                csoport[crucial[i]]=2;
                b-=(b&(lefed[i].S*(1<<(P0))));
            }
        }
        cout<<"YES"<<endl;
        for(int i=1; i<=n; i++)
        {
            cout<<csoport[i]<<" ";
        }
        cout<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
    return 0;
}