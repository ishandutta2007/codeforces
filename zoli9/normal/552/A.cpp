#include <iostream>
using namespace std;
int n;
long long v=0;
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int x1, x2, y1, y2;
        cin>>x1>>y1>>x2>>y2;
        v+=(x2-x1+1)*(y2-y1+1);
    }
    cout<<v;
    return 0;
}