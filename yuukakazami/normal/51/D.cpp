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
#include <cstdio>
#include <numeric>
#define REP(i,n) for(int i=0;i<n;i++)
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define FOREACH(e,x) for(typeof(x.begin()) e=x.begin();e!=x.end();e++)
#define FOR(i,a,b) for(int i=a;i<b;i++)//for i in [a,b)
#define MP make_pair
using namespace std;
typedef long long int64;
typedef pair<int,int> ipair;
typedef vector<int> vi;
const int INF=~0U>>3;
const int IMPOSSIBLE=INF+INF;
const int ANY=IMPOSSIBLE+2;

vi a;
int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
int get(int a,int b)
{
    if(a==0&&b==0)
        return ANY;
    if(a==0)
        return 0;
    if(b==0)
        return IMPOSSIBLE;
    if(a<0)a*=-1,b*=-1;
    int g=gcd(a,b);
    a/=g;b/=g;
    return a*10000+b;
}
int combine(int a,int b)
{
    if(a==ANY)return b;
    if(b==ANY)return a;
    if(a==IMPOSSIBLE||b==IMPOSSIBLE)
        return IMPOSSIBLE;
    if(a!=b) return IMPOSSIBLE;
    return a;
}
bool check(const vi&a)
{
    //if(a.size()==1)return true;
    int now=get(a[1],a[0]);
    for(int i=1;i<a.size();i++)
    {
        now=combine(now,get(a[i],a[i-1]));
        if(now==IMPOSSIBLE)
            return false;
    }
    return true;
}
bool tryDel(vi&a,int it)
{
    int tmp=a[it];
    a.erase(a.begin()+it);
    bool res=check(a);
    a.insert(a.begin()+it,tmp);
    return res;
}
int main()
{
    //freopen("in","r",stdin);
    int n,x;cin>>n;
    REP(i,n)scanf("%d",&x),a.PB(x);

    if(check(a))
    {
        cout<<0<<endl;
        return 0;
    }

    if(n<4)
    {
        for(int i=0;i<n;i++)
        {
            vi next=a;
            next.erase(next.begin()+i);
            if(check(next))
            {
                cout<<1<<endl;
                return 0;
            }
        }
        cout<<2<<endl;
        return 0;
    }
    else
    {
        for(int it=0;it<=3;it++)
        {
            if(it<3)
            {
                if(tryDel(a,it))
                {
                    cout<<1<<endl;
                    return 0;
                }
            }
            else
            {
                int x=a[0],y=a[1];
                if(x==0&&y==0)
                {
                    int zeroCnt=count(ALL(a),0);
                    if(zeroCnt>=n-1)
                    {
                        cout<<1<<endl;
                        return 0;
                    }
                    else
                    {
                        cout<<2<<endl;
                        return 0;
                    }
                }
                if(x==0&&y!=0)
                {
                    cout<<2<<endl;
                    return 0;
                }
                if(true)
                {
                    int it=get(y,x);
                    vi bad;
                    for(int i=1;i<n;i++)
                        if(combine(it,get(a[i],a[i-1]))==IMPOSSIBLE)
                            bad.PB(i);
                    if(bad.size()>2)
                    {
                        cout<<2<<endl;
                        return 0;
                    }

                    FOREACH(bIt,bad)
                    {
                        int at=*bIt;
                        if(tryDel(a,at)||tryDel(a,at-1))
                        {
                            cout<<1<<endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout<<2<<endl;
}