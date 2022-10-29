#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n,a,b,c;
    scanf("%d %d %d %d",&a,&b,&c,&n);
    for (int i=1;n>=i;i++)
    {
        int fail = i;
        int success = n-i;
        if (a-c >=0 && b-c >= 0 && success == c + (a-c) + (b-c))
        {
            cout << fail << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}