#include <bits/stdc++.h>
using namespace std;

int l[106],r[106];

int main ()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1;n>=i;i++)
    {
        scanf("%d %d",&l[i],&r[i]);
    }
    vector<int> ans;
    for (int i=1;m>=i;i++)
    {
        bool can = true;
        for (int j=1;n>=j;j++)
        {
            if (l[j] <= i && i <= r[j])
            {
                can = false;
                break;
            }
        }
        if (can) ans.push_back(i);
    }
    printf("%d\n",(int)ans.size());
    for (int i:ans) printf("%d ",i);
    puts("");
}