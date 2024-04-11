#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    int mn_ans = 2*n + 2;
    for (int i=1;n>=i;i++)
    {
        int j=n/i;
        if (i*j < n) j++;
        mn_ans = min(mn_ans,i+j+i+j);
    }
    cout << mn_ans << endl;
}