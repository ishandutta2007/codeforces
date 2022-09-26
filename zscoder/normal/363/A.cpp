#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<map>
#include<ctime>
#include<set>
#include<queue>
#include<cmath>
#include<vector>
#include<bitset>
#include<functional>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define REP(i,l,r) for((i)=(l);(i)<=(r);++(i))
#define REP2(i,l,r) for((i)=(l);(i)!=(r);++(i))
using namespace std;

typedef long long LL;
typedef double ld;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    int n;
    cin>>n;
    if(n==0)
    {
        printf("O-|-OOOO\n");
        return 0;
    }
    else
    {
        for(;n;n/=10)
        {
            int k=n%10;
            if(k>=5)
            {
                k-=5;
                printf("-O|");
            }
            else printf("O-|");
            int i;
            REP2(i,0,k)
                cout<<"O";
            cout<<"-";
            REP2(i,k,4)
                cout<<"O";
            cout<<endl;
        }
    }
    return 0;
}