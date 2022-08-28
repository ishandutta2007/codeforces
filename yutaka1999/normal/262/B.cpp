#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int in[100005];

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",&in[i]);
    sort(in,in+n);
    int pos=0;
    while(pos<n&&k>0)
    {
        if(in[pos]<=0)
        {
            in[pos]*=-1;
            k--;
            pos++;
        }
        else break;
    }
    sort(in,in+n);
    if(k%2==1) in[0]*=-1;
    int ret=0;
    for(int i=0;i<n;i++) ret+=in[i];
    printf("%d\n",ret);
    return 0;
}