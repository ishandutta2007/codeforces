#include <iostream>
using namespace std;
int main()
{
    int a, b, c, d, e;
    cin>>a>>b>>c>>d>>e;
    if((a+b+c+d+e)%5==0)
    {
        if(a==0 && b==0 && c==0 && d==0 && e==0)
        {
            cout<<-1;
            return 0;
        }
        cout<<(a+b+c+d+e)/5;
        return 0;
    }
    cout<<-1;
    return 0;



    return 0;
}