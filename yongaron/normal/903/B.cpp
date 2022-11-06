#include <iostream>
#include <vector>

using namespace std;

int a1, h1, c1, a2, h2;

vector<char> v;

int main()
{
    cin>>h1>>a1>>c1>>h2>>a2;
    while(1)
    {
        if(h1 > a2 || a1 >= h2)
        {
            v.push_back('s');
            h2 -= a1;
        }
        else
        {
            v.push_back('h');
            h1 += c1;
        }
        if(h2 <= 0)
            break;
        h1 -= a2;
    }
    cout<<v.size()<<endl;
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] == 's')
            cout<<"STRIKE"<<endl;
        else
            cout<<"HEAL"<<endl;
    }
    return 0;
}