#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#define SIZE 300005

using namespace std;
typedef pair <int,int> P;

P pos[SIZE];
int ans[SIZE];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        pos[i]=P(a,i);
    }
    sort(pos,pos+n);
    int mx=-1;
    for(int i=0;i<n;i++)
    {
        pos[i].first=max(pos[i].first,mx+1);
        mx=pos[i].first;
        ans[pos[i].second]=mx;
    }
    for(int i=0;i<n;i++)
    {
        if(i!=0) printf(" ");
        printf("%d",ans[i]);
    }puts("");
    return 0;
}