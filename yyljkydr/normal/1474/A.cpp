#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7;

int T;

int n;

char a[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        scanf("%s",a+1);
        int last=-1;
        for(int i=1;i<=n;i++)
        {
            int x=a[i]-'0';
            if(a[i]+1!=last)
            {
                putchar('1');
                last=a[i]+1;
            }
            else
            {
                putchar('0');
                last=a[i];
            }
        }
        puts("");
    }
}