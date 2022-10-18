//In the name of allah
#include <iostream>
using namespace std;
int main()
{
    int p1,p2,p3,p4,a,b,ans = 0;
    cin >> p1 >> p2 >> p3 >> p4 >> a >> b;
    for (int i = a;i<b+1;i++)if (i < p1 && i < p2 && i < p3 && i < p4 )ans++;
    cout << ans;
}