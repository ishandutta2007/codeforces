#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int in[100005];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&in[i]);
    int ret=0;
    int pos=0;
    for(int i=0;i<n;i++)
    {
        ret+=abs(in[i]-pos)+1;
        pos=in[i];
        ret++;
    }
    printf("%d\n",ret-1);
    return 0;
}