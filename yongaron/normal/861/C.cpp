#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s;
string v;

void write(int x)
{
    if(x+1 > v.size())
        return;
    if(x == v.size()-1)
        cout<<v[x];
    else
    {
        if(v[x] != v[x+1])
        {
            cout<<v[x]<<v[x+1];
            if(x+2 < v.size())
                cout<<" ";
            write(x+2);
        }
        else
        {
            while(x != v.size()-1 && v[x] == v[x+1])
            {
                cout<<v[x];
                x++;
            }
            cout<<v[x];
            if(x+1 < v.size())
                cout<<" ";
            write(x+1);
        }
    }
}

int main()
{
    cin>>s;
    v.push_back('c');
    v.clear();
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            write(0);
            cout<<s[i];
            v.clear();
        }
        else
        {
            v.push_back(s[i]);
        }
    }
    write(0);
    cout<<endl;
    return 0;
}