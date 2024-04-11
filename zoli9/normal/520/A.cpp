#include <iostream>
#include <string>
using namespace std;
char c[105];
bool v[1000];
int n;
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>c[i];
        char w=tolower(c[i]);
        v[w]=true;
    }
    for(int i='a'; i<='z'; i++)
    {
        if(!v[i])
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}