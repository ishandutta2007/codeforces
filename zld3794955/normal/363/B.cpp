#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<cstring>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<string>
#include<utility>
using namespace std;
int n,k,a[505000]={};
int main()
{   
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    int sum=0,pos=0,min_sum=0x7fffffff;
    for(int i=1;i<=k;++i)
        sum+=a[i];
    min_sum=sum;
    pos=1;
    for(int i=k+1;i<=n;++i)
    {
        sum+=a[i];
        sum-=a[i-k];
        if(sum<min_sum)
        {
            min_sum=sum;
            pos=i-k+1;
        }
    }
    printf("%d\n",pos);
    return 0;
}