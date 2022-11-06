#include <iostream>

using namespace std;

int s, t1, t2, v1, v2;

int main()
{
    cin>>s;
    cin>>v1;
    cin>>v2;
    cin>>t1;
    cin>>t2;
    int x = 2*t1+s*v1;
    int y = 2*t2+s*v2;
    if(x < y)
        cout<<"First"<<endl;
    else if(x > y)
        cout<<"Second"<<endl;
    else
        cout<<"Friendship"<<endl;
    return 0;
}