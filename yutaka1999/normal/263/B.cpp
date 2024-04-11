#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <functional>

using namespace std;

int in[55];

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    if(n<k) printf("%d\n",-1);
    else
    {
        for(int i=0;i<n;i++) scanf("%d",&in[i]);
        sort(in,in+n,greater <int>());
        printf("%d %d\n",in[k-1],in[k-1]);
    }
    return 0;
}