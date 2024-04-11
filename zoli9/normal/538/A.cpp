#include <iostream>
#include <string>
using namespace std;
string s;
int h;
int main()
{
    cin>>s;
    h=s.length();
    for(int i=0; i<h; i++)
    {
        for(int j=i; j<h; j++)
        {
            if(i==0 and j!=h-1)
            {


            string x=s.substr(j+1, h-j-1);
            if(x=="CODEFORCES")
            {
                cout<<"YES";
                return 0;
            }
            }
            else if(i!=0 and j==h-1)
            {


            string x=s.substr(0, i);
            if(x=="CODEFORCES")
            {
                cout<<"YES";
                return 0;
            }
            }
            else if(i!=0 and j!=h-1)
            {


            string x=s.substr(0, i)+s.substr(j+1, h-j-1);
            if(x=="CODEFORCES")
            {
                cout<<"YES";
                return 0;
            }
            }
        }
    }
    cout<<"NO";
    return 0;
}