#include <bits/stdc++.h>
using namespace std;

int a[206];

int main ()
{
    int n;
    scanf("%d",&n);
    for (int i=1;2*n>=i;i++)
    {
        scanf("%d",&a[i]);
    }
    int ans=0;
    for (int i=1;2*n>=i;i+=2)
    {
        if (a[i+1] != a[i])
        {
            int j = i+1;
            for (j=i+1;2*n>=j;j++)
            {
                if (a[j] == a[i]) break;
            }
            //cout << "i = " << i << " , j = " << j <<endl;
            ans += (j-i-1);
            for (;j>i;j--)
            {
                swap(a[j],a[j-1]);
            }
        }
    }
    printf("%d\n",ans);
}