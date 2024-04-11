#include <iostream>
#include <string>

using namespace std;

string a, b;

int main()
{
    cin>>a>>b;
    cout<<a[0];
    for(int i = 1; i < a.size(); i++)
    {
        if(a[i]<b[0])
            cout<<a[i];
        else
            break;
    }
    cout<<b[0]<<endl;
    return 0;
}