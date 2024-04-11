#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tomi;
    cin>>tomi;
    int zsofi;
    cin>>zsofi;

    int zoli;
    zoli=1;




    while(zoli<=zsofi)
    {
        if(tomi%10==0)
        {
            tomi=tomi/10;
        }
        else
        {
            tomi=tomi-1;
        }
        zoli=zoli+1;
    }
    cout<<tomi<<endl;

}