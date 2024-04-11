#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[1006];

int main ()
{
    int n,m,c;
    scanf("%d %d %d",&n,&m,&c);
    memset(a,-1,sizeof(a));
    int _=1, __ = n;  //_: need to be fill
    //so is _ - __ == 1 --> that is the end
    while (m--)
    {
        int p;
        scanf("%d",&p);
        if (p <= c/2)
        {
            if (_ == 1)
            {
                printf("%d\n",_);
                fflush(stdout);
                a[_++] = p;
            }
            else
            {
                bool found = false;
                for (int i=1;_>i;i++)
                {
                    if (a[i] > p)
                    {
                        printf("%d\n",i);
                        fflush(stdout);
                        a[i] = p;
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    printf("%d\n",_);
                    fflush(stdout);
                    a[_++] = p;
                }
            }
        }
        else
        {
            if (__ == n)
            {
                printf("%d\n",__);
                fflush(stdout);
                a[__--] = p;
            }
            else
            {
                bool found = false;
                for (int i=n;i>__;i--)
                {
                    if (a[i] < p)
                    {
                        printf("%d\n",i);
                        fflush(stdout);
                        a[i] = p;
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    printf("%d\n",__);
                    fflush(stdout);
                    a[__--] = p;
                }
            }
        }
        if (_ - __ == 1 ) return 0;
    }
}