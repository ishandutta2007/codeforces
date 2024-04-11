#include <iostream>
using namespace std;
int tab[6][6];
int t[6];
long long maxi=0;
long long asd()
{
    long long o=0;
    o+=tab[t[1]][t[2]];
    o+=tab[t[2]][t[1]];

    o+=tab[t[2]][t[3]];
    o+=tab[t[3]][t[2]];

    o+=2*tab[t[3]][t[4]];
    o+=2*tab[t[4]][t[3]];

    o+=2*tab[t[4]][t[5]];
    o+=2*tab[t[5]][t[4]];

    return o;
}
int main()
{
    for(int i=1; i<=5; i++)
    {
        for(int j=1; j<=5; j++)
        {
            cin>>tab[i][j];
        }
    }
    for(int a1=1; a1<=5; a1++)
    {
        for(int a2=1; a2<=5; a2++)
    {
        for(int a3=1; a3<=5; a3++)
    {
        for(int a4=1; a4<=5; a4++)
    {
        for(int a5=1; a5<=5; a5++)
    {
        if(a1!=a2 and a1!=a3 and a1!=a4 and a1!=a5 and a3!=a2 and a4!=a2 and a5!=a2 and a4!=a3 and a3!=a5 and a4!=a5)
        {
            t[1]=a1;
            t[2]=a2;
            t[3]=a3;
            t[4]=a4;
            t[5]=a5;
            if(asd()>maxi)
            {
                maxi=asd();
            }
        }
    }
    }
    }
    }
    }
    cout<<maxi;
    return 0;
}