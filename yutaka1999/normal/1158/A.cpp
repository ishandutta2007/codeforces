#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <cassert>
#include <functional>
#include <cmath>
#include <iostream>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int B[SIZE],G[SIZE];

int main()
{
	int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&B[i]);
    for(int i=0;i<m;i++) scanf("%d",&G[i]);
    int C=0;
    for(int i=0;i<n;i++) C=max(C,B[i]);
    bool up=false;
    for(int i=0;i<m;i++)
    {
        if(C>G[i])
        {
            puts("-1");
            return 0;
        }
        up|=(G[i]==C);
    }
    ll sum=0;
    for(int i=0;i<n;i++) sum+=(ll) B[i]*(ll) m;
    vector <P> vx;
    for(int i=0;i<n;i++)
    {
        if(B[i]==C&&up) vx.push_back(P(B[i],m));
        else vx.push_back(P(B[i],m-1));
    }
    sort(vx.begin(),vx.end(),greater <P>());
    int f=0;
    for(int i=0;i<m;i++)
    {
        if(G[i]==C) continue;
        while(f<vx.size()&&vx[f].second==0) f++;
        if(f==vx.size())
        {
            puts("-1");
            return 0;
        }
        sum+=G[i]-vx[f].first;
        vx[f].second--;
    }
    cout<<sum<<endl;
    return 0;
}