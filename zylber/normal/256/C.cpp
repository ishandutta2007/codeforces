#include <iostream>
#include <string>
using namespace std;

int N;
long long a[8000];

int main()
{
    long long g[7]={3,15,81,6723,50625,2562890624,777777777778LL};
    long long n[7]={0,1,2,0,3,1,2};

    int xr=0;
    cin >> N;
    for(int i=0; i<N; i++)
    {
        long long k;
        cin >> k;
        int r=0;
        while(k>g[r])
            r++;

        xr^=n[r];
    }

    if(xr)
        cout << "Furlo" << endl;
    else
        cout << "Rublo" << endl;
}