#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 100005

using namespace std;
typedef pair <int,int> P;

P fir[SIZE],sec[SIZE];
int cnt[SIZE];

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        fir[i]=P(b,a);
    }
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        sec[i]=P(b,a);
    }
    sort(fir,fir+n);
    sort(sec,sec+m);
    int now=0;
    int l=0,r=0;
    for(int i=0;i<n;)
    {
        memset(cnt,0,sizeof(cnt));
        int s=i,sum=0;
        for(;now<m&&sec[now].first<=fir[s].first;now++)
        {
            if(sec[now].first<fir[s].first) continue;
            cnt[sec[now].second]++;
            sum++;
        }
        for(;fir[i].first==fir[s].first;i++)
        {
            if(cnt[fir[i].second]>0)
            {
                r++;
                cnt[fir[i].second]--;
            }
            if(sum>0)
            {
                l++;
                sum--;
            }
        }
    }
    printf("%d %d\n",l,r);
    return 0;
}