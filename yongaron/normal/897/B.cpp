#include <iostream>

using namespace std;

long long k, p;
int x[9];

int main()
{
    cin>>k>>p;
    for(int i = 0; i < 9; i++)
        x[i] = 0;
    long long s = 0, a;
    int nz = 0;
    for(int i = 0; i < k; i++)
    {
        x[0]++;
        for(int j = 0; j < 9; j++)
        {
            if(x[j] == 10)
            {
                x[j] = 0;
                x[j+1]++;
                if(j+1 > nz)
                {
                    nz++;
                }
            }
        }
        a = 0;
        long long c = 1;
        for(int j = nz; j >= 0; j--)
        {
            a += c*x[j];
            c *= 10;
        }
        for(int j = 0; j <= nz; j++)
        {
            a += c*x[j];
            c *= 10;
        }
        //cout<<a<<endl;
        a %= p;
        s += a;
        s %= p;
    }
    cout<<s<<endl;
    return 0;
}