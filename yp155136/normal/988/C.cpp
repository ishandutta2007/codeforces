#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

int a[223456];

int main ()
{
    int n;
    scanf("%d",&n);
    map<int,pii> mp;
    for (int i=1;n>=i;i++)
    {
        int m;
        scanf("%d",&m);
        int sum=0;
        for (int j=1;m>=j;j++)
        {
            scanf("%d",&a[j]);
            sum += a[j];
        }
        for (int j=1;m>=j;j++)
        {
            if (mp.find(sum-a[j]) != mp.end())
            {
                puts("YES");
                pii p = mp[sum-a[j]];
                printf("%d %d\n",p.F,p.S);
                printf("%d %d\n",i,j);
                return 0;
            }
        }
        for (int j=1;m>=j;j++)
        {
            mp[ sum-a[j] ] = make_pair(i,j);
        }
    }
    puts("NO");
}