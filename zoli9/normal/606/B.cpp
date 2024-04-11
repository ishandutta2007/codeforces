#include <bits/stdc++.h>
using namespace std;
long long x, y, xx, yy;
long long ossz;
long long aktx, akty;
bool be[509][509];
string s;
int main()
{
    ossz=1;
    cin>>x>>y>>xx>>yy;
    cin>>s;
    cout<<1;
    aktx=xx;
    akty=yy;
    be[xx][yy]=true;
    for(int i=0; i<s.size(); i++)
    {
        if(i==s.size()-1)
         {
             cout<<" "<<x*y-ossz;
             break;
         }
        if(s[i]=='U')
        {
            if(aktx==1)
            {
                cout<<" "<<0;
                continue;
            }
            aktx--;
            if(!be[aktx][akty])
            {
                cout<<" "<<1;
                ossz++;
            }
            else
            {
                cout<<" "<<0;
            }
            be[aktx][akty]=true;
        }
         else if(s[i]=='D')
         {
             if(aktx==x)
             {
                 cout<<" "<<0;
                 continue;
             }
             aktx++;
             if(!be[aktx][akty])
            {
                cout<<" "<<1;
                ossz++;
            }
            else
            {
                cout<<" "<<0;
            }
            be[aktx][akty]=true;
         }
         else if(s[i]=='L')
         {
             if(akty==1)
             {
                 cout<<" "<<0;
                 continue;
             }
             akty--;
             if(!be[aktx][akty])
            {
                cout<<" "<<1;
                ossz++;
            }
            else
            {
                cout<<" "<<0;
            }
            be[aktx][akty]=true;
         }
         else
         {
             if(akty==y)
             {
                 cout<<" "<<0;
                 continue;
             }
             akty++;
             if(!be[aktx][akty])
            {
                cout<<" "<<1;
                ossz++;
            }
            else
            {
                cout<<" "<<0;
            }
            be[aktx][akty]=true;
         }


    }

    return 0;
}