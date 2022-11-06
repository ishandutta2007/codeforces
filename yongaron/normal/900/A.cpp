#include <iostream>

using namespace std;

int n;

int main()
{
    cin>>n;
    int k = 0;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin>>x>>y;
        if(x > 0)
            k++;
    }
    if(k >= n-1)
        cout<<"Yes"<<endl;
    else if(k <= 1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}