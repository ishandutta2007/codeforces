#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int n, k;
    cin >> n;
    cin >> k;

    if(k==1 || n/k<3)
        cout << -1 << endl;
    else
    {
        for(int i=1; i<=k; i++)
        {
            if(i>1)
            printf(" ");
            printf("%i",i);

        }
        for(int i=1; i<=k; i++)
        {
            printf(" %i",i);
            printf(" %i",i);
        }

        for(int j=3*k; j<n; j++)
            printf(" 1");
    }
    cout << endl;
}