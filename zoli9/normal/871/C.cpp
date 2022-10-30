#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
long long MOD=1000000007;
long long modinvers(long long a, long long p)
{
    long long ans=1;
    long long hat=a;
    long long kell=p-2;
    while(kell>0)
    {
        if(kell%2)
        {
            ans*=hat;
            ans%=p;
        }
        kell/=2;
        hat*=hat;
        hat%=p;
    }
    return ans;
}
long long fakt[200009];
long long faktinv[200009];
vector<int> G[200009];
map<pair<long long, long long>, int> ma;
vector<pair<long long, long long> > v1, v2;
pair<long long, long long> pontok[200009];
int n;
int kompcnt=0;
long long answer=1;
vector<int> komp[200009];
bool bejar[200009];
void dfs(int x)
{
    bejar[x]=true;
    komp[kompcnt].push_back(x);
    for(int sz: G[x])
    {
        if(!bejar[sz]) dfs(sz);
    }
}
long long esetek[200009];
long long osszegez(int X, int Y)
{
    long long answ=0;
    for(int i=0; i<=Y; i++)
    {
        long long curr=fakt[X];
        curr*=(faktinv[i]);
        curr%=MOD;
        curr*=(faktinv[X-i]);
        curr%=MOD;
        answ+=curr;
        answ%=MOD;
    }
    return answ;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    fakt[0]=1;
    faktinv[0]=1;
    fakt[1]=1;
    faktinv[1]=1;
    for(long long i=2; i<=2*n+2; i++)
    {
        fakt[i]=fakt[i-1]*i;
        fakt[i]%=MOD;
        faktinv[i]=faktinv[i-1]*modinvers(i, MOD);
        faktinv[i]%=MOD;
    }
    for(int i=1; i<=n; i++)
    {
        cin>>pontok[i].F>>pontok[i].S;
        ma[pontok[i]]=i;
        v1.push_back({pontok[i].F, pontok[i].S});
        v2.push_back({pontok[i].S, pontok[i].F});
    }
    sort(v1.begin(), v1.end());
    for(int i=1; i<v1.size(); i++)
    {
        if(v1[i].F==v1[i-1].F)
        {
            int i1=ma[v1[i-1]];
            int i2=ma[v1[i]];
            G[i1].push_back(i2);
            G[i2].push_back(i1);
        }
    }
    sort(v2.begin(), v2.end());
    for(int i=1; i<v2.size(); i++)
    {
        if(v2[i].F==v2[i-1].F)
        {
            pair<long long, long long> r1, r2;
            r1.F=v2[i-1].S;
            r1.S=v2[i-1].F;
            r2.F=v2[i].S;
            r2.S=v2[i].F;
            int i1=ma[r1];
            int i2=ma[r2];
            G[i1].push_back(i2);
            G[i2].push_back(i1);
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(!bejar[i])
        {
            kompcnt++;
            dfs(i);
        }
    }
    for(int i=1; i<=kompcnt; i++)
    {
        unordered_set<long long> sx, sy;
        for(int j=0; j<komp[i].size(); j++)
        {
            sx.insert(pontok[komp[i][j]].F);
            sy.insert(pontok[komp[i][j]].S);
        }
        int egyenesek=sx.size()+sy.size();
        int csucsok=komp[i].size();
        esetek[i]=osszegez(egyenesek, csucsok);
    }
    for(int i=1; i<=kompcnt; i++)
    {
        answer*=esetek[i];
        answer%=MOD;
    }
    cout<<answer<<endl;
    return 0;
}