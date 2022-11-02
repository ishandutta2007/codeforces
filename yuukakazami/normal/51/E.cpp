#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <numeric>
#include <cstdio>
#include <bitset>
#define REP(i,n) for(int i=0;i<n;i++)
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define FOREACH(e,x) for(typeof(x.begin()) e=x.begin();e!=x.end();e++)
#define FOR(i,a,b) for(register int i=a;i<b;i++)//for i in [a,b)
#define MP make_pair
using namespace std;
typedef long long int64;
typedef pair<int,int> ipair;
typedef vector<int> vi;
const int V_MAX=700;
typedef int mat[V_MAX][V_MAX];
mat g={},p2;
int n,m;
int d[V_MAX]={};

bitset<V_MAX> conSet[V_MAX];
int main()
{
    //freopen("in","r",stdin);
    cin>>n>>m;
    REP(i,n)conSet[i].reset();
    REP(cur,m)
    {
        int s,t;scanf("%d%d",&s,&t);
        --s;--t;
        g[s][t]=1;g[t][s]=1;
        conSet[s][t]=true;conSet[t][s]=true;
        d[s]++;d[t]++;
    }

    REP(i,n)REP(j,i)
    {
        static bitset<V_MAX> tmpSet;
        tmpSet=conSet[i]&conSet[j];
        p2[i][j]=p2[j][i]=tmpSet.count();
    }

    int64 sum=0,take=0;
    REP(i,n)REP(j,n)if(j!=i)REP(k,j)if(k!=i)
    {
        if(g[j][k])
        {
            sum+=(p2[i][j]-g[i][k])*(p2[i][k]-g[i][j]);
            if(g[i][j]&&g[i][k])
            {
                take+=d[i]-2;
            }
        }
    }

    sum-=take;
    cout<<sum/5<<endl;
}