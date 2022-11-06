#include <iostream>

using namespace std;

int bal[128];

int n, k;

int main()
{
    cin>>n;
    cin>>k;
    for(int i = 0; i < 128; i++)
        bal[i] = 0;
    char c;
    for(int i = 0; i < n; i++)
    {
        cin>>c;
        bal[c]++;
        if(bal[c] > k)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}