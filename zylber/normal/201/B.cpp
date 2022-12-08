#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

long long c[1024][1024];
long long sumcol[1024];
long long sumfila[1024];

/*long long abs(long long j)
{
    return j<0?-j:j;
}*/

int main()
{
    int n, m;
    cin >> n >> m;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> c[i][j];

    memset(sumcol,0,sizeof(sumcol));
    memset(sumfila,0,sizeof(sumfila));
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            sumcol[i]+=c[i][j];
            sumfila[j]+=c[i][j];
        }
        
        
    long long bestcol=1000000000000000000LL, besti=-4;
    for(long long i=0; i<=4*n; i+=4)
    {
        long long sum=0;
        for(int j=0; j<n; j++)
        {
            long long act=4*j+2;
            sum+=abs(i-act)*abs(i-act)*sumcol[j];
        }
        if(bestcol>sum)
        {
            bestcol=sum;
            besti=i;
        }
    }
    
    long long bestfila=1000000000000000000LL, bestj=-4;
    for(long long i=0; i<=4*m; i+=4)
    {
        long long sum=0;
        for(int j=0; j<m; j++)
        {
            long long act=4*j+2;
            sum+=abs(i-act)*abs(i-act)*sumfila[j];
        }
        
        if(bestfila>sum)
        {
            bestfila=sum;
            bestj=i;
        }
    }
    
    cout << (bestfila+bestcol) << endl;
    cout << besti/4 << " " << bestj/4 << endl;
}