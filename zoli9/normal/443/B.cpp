#include <iostream>
using namespace std;
string s;
int k;
bool v;
int maxi=0;
int main()
{
    cin>>s;
    cin>>k;
    if(s.size()>=k)
    {
         maxi=2*k;
    }
    else
    {
         maxi=s.size()+k;
         if(maxi%2)
         {
             maxi--;
         }
    }
    for(int i=0; i+k<s.size(); i++)
    {
        for(int j=i+1; j<s.size(); j++)
        {
            v=true;
            int x=i;
            int y=j;
            while(x<j)
            {
                if(y>=s.size()+k)
                {
                    v=false;
                }
                else if(y>=s.size())
                {

                }
                else
                {
                    if(s[x]!=s[y])
                    {
                        v=false;
                    }
                }
                x++;
                y++;
            }
            if(v)
            {
                maxi=max(maxi, (j-i)*2);
            }
        }
    }
    cout<<maxi;
    return 0;
}