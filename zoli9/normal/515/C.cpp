#include <iostream>
#include <cstdio>
#include <stdlib.h>
using namespace std;
int n;
char c[20];
int jegy[20];
int db[15];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>c[i];
    }
    for(int i=1; i<=n; i++)
    {
        jegy[i]=c[i]-'0';
    }
    for(int i=0; i<=9; i++)
    {
        db[i]=0;
    }
    for(int i=1; i<=n; i++)
    {
        if(jegy[i]==0)
        {

        }
        else if(jegy[i]==1)
        {

        }
        else if(jegy[i]==2)
        {
            db[2]++;
        }
        else if(jegy[i]==3)
        {
            db[3]++;
        }
        else if(jegy[i]==4)
        {
            db[3]++;
            db[2]+=2;
        }
        else if(jegy[i]==5)
        {
            db[5]++;
        }
        else if(jegy[i]==6)
        {
            db[5]++;
            db[3]++;
        }
        else if(jegy[i]==7)
        {
            db[7]++;
        }
        else if(jegy[i]==8)
        {
            db[7]++;
            db[2]+=3;
        }
        else if(jegy[i]==9)
        {
            db[7]++;
            db[3]+=2;
            db[2]++;
        }
    }
    for(int i=9; i>=0; i--)
    {
        for(int j=1; j<=db[i]; j++)
        {
            cout<<i;
        }
    }

    return 0;
}