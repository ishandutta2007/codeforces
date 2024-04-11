#include <iostream>
using namespace std;

long long n;
long long x;
int a[11];
int b[11];
int t;
bool v;

void nov()
{
    for(int j=1; j<=10; j++)
    {
        if(a[j]==9)
        {
            a[j]=0;
        }
        else
        {
            a[j]++;
            break;
        }
    }
}
void csok()
{
    for(int j=1; j<=10; j++)
    {
        if(a[j]==0)
        {
            a[j]=9;
        }
        else
        {
            a[j]--;
            break;
        }
    }
}

void havan()
{
    for(int j=1; j<=10; j++)
    {
        if(a[j]==8)
        {
            v=true;
        }
    }
}

int main()
{
    cin>>n;
    t=0;
    x=n;
    if(x<0)
    {
        a[0]=0;
        x=x*(-1);
    }
    else
    {
        a[0]=1;
    }
    for(int i=1; i<=10; i++)
    {
        a[i]=x%10;
        x=(x-a[i])/10;
    }

    for(int i=0; i<=10; i++)
    {
        b[i]=a[i];
    }


    if(n==-1)
    {
        cout<<9;
        return 0;
    }

    if(n==-2)
    {
        cout<<10;
        return 0;
    }
    if(n==-3)
    {
        cout<<11;
        return 0;
    }
    if(n==-4)
    {
        cout<<12;
        return 0;
    }
    if(n==-5)
    {
        cout<<13;
        return 0;
    }
    if(n==-6)
    {
        cout<<14;
        return 0;
    }
    if(n==-7)
    {
        cout<<15;
        return 0;
    }
    if(n==-8)
    {
        cout<<16;
        return 0;
    }
    if(n==-9)
    {
        cout<<1;
        return 0;
    }
    if(n==-10)
    {
        cout<<2;
        return 0;
    }

    if(a[0]==1)
    {
        for(int i=1; i<=10; i++)
        {
            nov();
            v=false;
            havan();
            if(v)
            {
                cout<<i;
                return 0;
            }
        }
    }
    else
    {
        for(int i=1; i<=10; i++)
        {
            csok();
            v=false;
            havan();
            if(v)
            {
                cout<<i;
                return 0;
            }
        }
    }



    return 0;
}