#include <iostream>

using namespace std;

int n, x;


int main()
{
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>x;
        if(x != 1 && x != 2 && x != 4 && x != 5 && x!= 8 && x!= 11)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}