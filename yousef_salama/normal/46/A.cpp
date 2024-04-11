//In the name of allah
#include <iostream>
using namespace std;
int main()
{
    int p = 2,n,t=1;
    cin >> n;
    int w[n-1];
    for (int i =0;i<n-1;i++){
        if (p == 0)p = n;
        w[i] = p;
        t++;
        p += t;
        p %= n;
    }
    for (int i =0;i<n-1;i++)cout << w[i] << ' ';
}