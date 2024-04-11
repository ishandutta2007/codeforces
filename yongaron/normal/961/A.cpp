#include <iostream>

using namespace std;

int n, s[1005], b;

int main()
{
    cin>>n>>b;
    for(int i = 0; i < b; i++)
    {
        int x;
        cin>>x;
        s[x]++;
    }
    int mi = 999999999;
    for(int i = 1; i <= n; i++)
        mi = min(mi, s[i]);
    cout<<mi<<endl;
    return 0;
}