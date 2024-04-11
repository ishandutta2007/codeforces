#include <iostream>
#include <vector>
using namespace std;
long long a, b, n;
vector<int> v;
int main()
{
    cin>>a>>b>>n;
    bool asd=false;
    for(int i=0; i<=9; i++)
    {
        if((a*10+i)%b==0)
        {
            cout<<a;
            cout<<i;
            for(int j=2; j<=n; j++)
            {
                cout<<0;
            }
            return 0;
        }
    }

        cout<<-1;
        return 0;

    return 0;
}