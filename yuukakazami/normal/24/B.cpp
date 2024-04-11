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
#define tr(e,x) for(map<string,vector<int> >::iterator e=x.begin();e!=x.end();e++)
#define printTime cout<<"Time:"<<pre-clock()<<endl;pre=clock();
const int inf=~0U>>1;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int A[100]={25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
map<string,vector<int> > M;
map<string,vector<int> > T;
map<string,int> S;
int cnt=0;
int main()
{
    //freopen("in","r",stdin);
    int t;cin>>t;
    rep(j,t)
    {
        int n;cin>>n;string tmp;
        rep(i,n)
        {
            cin>>tmp;
            M[tmp].pb(i);
            S[tmp]+=A[i];
        }
    }
    tr(e,M)
    {
        T[e->first]=vector<int>(100,0);
        rep(i,e->second.size())
            T[e->first][e->second[i]]++;
    }
    //First
    string name=M.begin()->first;
    tr(e,M)
    {
        if(S[e->first]>S[name])
        {
            name=e->first;
            continue;
        }
        if(S[e->first]==S[name])
        {
            if(T[e->first]>T[name])
            {
                name=e->first;
                continue;
            }
        }
    }
    cout<<name<<endl;
    name=M.begin()->first;
    tr(e,M)
    {
        string tmp=e->first;
        if(T[tmp][0]>T[name][0])
        {
            name=tmp;
            continue;
        }
        if(T[tmp][0]==T[name][0])
        {
            if(S[tmp]>S[name])
            {
                name=tmp;
                continue;
            }
            if(S[tmp]==S[name])
            {
                if(T[tmp]>T[name])
                {
                    name=tmp;
                    continue;
                }
            }
        }
    }
    cout<<name<<endl;
}