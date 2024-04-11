#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 1000005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

char str[SIZE];
bool ok[SIZE];
int KMP[SIZE];
int imos[SIZE];

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    scanf("%s",&str);
    int L=strlen(str);
    for(int i=0;i<L;i++)
    {
        if(i==0) KMP[i]=-1;
        else
        {
            int now=KMP[i-1];
            while(1)
            {
                if(str[now+1]==str[i])
                {
                    KMP[i]=now+1;
                    break;
                }
                if(now==-1)
                {
                    KMP[i]=-1;
                    break;
                }
                now=KMP[now];
            }
        }
    }
    for(int i=L-1;i>=0;i=KMP[i]) ok[i]=true;
    int bef=-1;
    for(int i=0;i<m;i++)
    {
        int p;
        scanf("%d",&p);p--;
        imos[p]++;imos[p+L]--;
        if(bef!=-1&&p-bef<L)
        {
            if(!ok[L-(p-bef)-1])
            {
                puts("0");
                return 0;
            }
        }
        bef=p;
    }
    ll ret=1;
    for(int i=0;i<n;i++)
    {
        imos[i+1]+=imos[i];
        if(imos[i]==0)
        {
            ret*=26;
            ret%=MOD;
        }
    }
    printf("%I64d\n",ret);
    return 0;
}