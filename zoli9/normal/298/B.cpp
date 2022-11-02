#include <iostream>
using namespace std;
long long n, sx, sy, ex, ey;
string s;
long long f, v;
long long hany[4];
int main()
{
    cin>>n>>sx>>sy>>ex>>ey;
    cin>>s;
    v=ex-sx;
    f=ey-sy;
    if(v==0 and f==0)
    {
        cout<<0;
        return 0;
    }
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='N')
        {
            hany[0]++;
        }
        else if(s[i]=='S')
        {
            hany[1]++;
        }
        else if(s[i]=='E')
        {
            hany[2]++;
        }
        else
        {
            hany[3]++;
        }
        bool egyik=true, masik=true;
        if(v<0)
        {
            if(hany[3]+v<0) egyik=false;
        }
        else
        {
            if(hany[2]-v<0) egyik=false;
        }

        if(f<0)
        {
            if(hany[1]+f<0) masik=false;
        }
        else
        {
            if(hany[0]-f<0) masik=false;
        }

        if(egyik && masik)
        {
            cout<<i+1;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}