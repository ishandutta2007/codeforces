#include <iostream>
#include <string>

using namespace std;

string s[5] = {"Danil", "Olya", "Slava", "Ann", "Nikita"}, a;

int main()
{
    int n = 0;
    cin>>a;
    for(int i = 0; i < a.size(); i++)
    {
        for(int ss = 0; ss < 5; ss++)
        {
            bool x = true;
            for(int j = 0; j < s[ss].size(); j++)
            {
                /*if(i == 0)
                    cout<<s[ss][j]<<" "<<a[i+j]<<endl;*/
                if(i+j >= a.size() || s[ss][j] != a[i+j])
                    x = false;
            }
            if(x)
                n++;
        }
    }
    if(n == 1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}