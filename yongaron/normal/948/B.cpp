#include <iostream>

using namespace std;

int x2;
bool nop[1000005];
int mdiv[1000005], mi[1000005];

void erat()
{
    for(int i = 2; i < 1000005; i++)
    {
        if(nop[i])
            continue;
        for(int j = 2; i*j<1000005; j++)
        {
            nop[i*j] = true;
            mdiv[i*j] = i;
        }
        mdiv[i] = 1;
    }
}

int main()
{
    cin>>x2;
    erat();
    for(int i = 2; i < 1000005; i++)
        mi[i] = i-mdiv[i]+1;
    int x = x2;
    for(int i = mi[x2]; i <= x2; i++)
    {
        if(mi[i] < x)
            x = mi[i];
    }
    cout<<x<<endl;
    return 0;
}