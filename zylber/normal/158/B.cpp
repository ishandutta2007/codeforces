#include <iostream>
using namespace std;

int c[5];

int main()
{
    for(int i=1; i<=4; i++)
    c[i]=0;

    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        c[a]++;
    }

    int taxis=0;
    while(c[1]+c[2]+c[3]+c[4]>0)
    {
        int p=0;
        for(int k=4; k>=1; k--)
        while(p+k<=4 && c[k]>0)
        {
            c[k]--;
            p+=k;
        }
        taxis++;
    }

    cout << taxis << endl;
}