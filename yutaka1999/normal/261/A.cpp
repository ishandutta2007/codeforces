#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <functional>
#define INF 1000000

using namespace std;

int in[100005];

int main()
{
    int m;
    scanf("%d",&m);
    int mini=INF;
    for(int i=0;i<m;i++)
    {
        int a;
        scanf("%d",&a);
        mini=min(mini,a);
    }
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&in[i]);
    sort(in,in+n,greater<int>());
    int ret=0;
    int pos=0;;
    while(pos+mini<=n)
    {
        for(int i=pos;i<pos+mini;i++) ret+=in[i];
        pos+=mini+2;
    }
    for(int i=pos;i<n;i++) ret+=in[i];
    printf("%d\n",ret);
    return 0;
}