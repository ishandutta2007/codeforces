#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1000006;

int p[N];

int main ()
{
    for (int i=2;N>i;i++)
    {
        if (!p[i])
        {
            p[i] = i;
            for (int j=i;N>j;j+=i)
            {
                p[j] = i;
            }
        }
    }
    int x2;
    cin >> x2;
    int ans = x2;
    for (int i=x2 - p[x2]+1;x2>=i;i++)
    {
        //cout << "i = "<<i<<" , p = "<<p[i]<<endl;
        if (p[i] == i) continue;
        ans = min(ans, i - p[i] + 1 );
    }
    cout << ans << endl;
}