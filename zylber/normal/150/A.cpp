#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    
    long long k=n, cd=0, move[2];
    for(long long i=2; i*i<=k; i++)
    {
        while(k%i==0)
        {
            if(cd<2)
                move[cd]=i;
            cd++;
            k/=i;
        }
    }
    if(k!=1)
    {
            if(cd<2)
                move[cd]=k;
            cd++;
    }
    
    if(cd>2)
    {
        cout << 1 << endl << move[0]*move[1] << endl;
    }
    
    if(cd==2)
    {
        cout << 2 << endl;
    }
    
    if(cd<2)
    {
        cout << 1 << endl << 0 << endl;
    }
}