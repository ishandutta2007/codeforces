#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool b = true;
int ot, n = 0;
int vyss[128], vyst[128], vys[128];
string s, t;
vector<char> a;

void vyres();

int main()
{
    cin>>s;
    cin>>t;
    vyres();
    for(int i = 0; i < a.size(); i++)
        cout<<a[i];
    cout<<endl;
    return 0;
}
void vyres()
{
    ot = 0;
    for(int i = 0; i < s.size(); i++)
        if(s[i] == '?')
            ot++;
    for(int i = 60; i < 128; i++)
        vys[i] = vyss[i] = vyst[i] = 0;
    for(int i = 0; i < s.size(); i++)
    {
        vyss[s[i]]++;
        vys[s[i]]--;
    }
    for(int i = 0; i < t.size(); i++)
        vyst[t[i]]++;
    while(b)
    {
        //for(int i = 60; i < 128; i++)
            //cout<<char(i)<<" "<<vyss[i]<<" "<<vyst[i]<<endl;
        for(int i = 60; i < 128; i++)
        {
            if(vyst[i] > vyss[i]+ot)
            {
                b = false;
                break;
            }
            if(vyst[i] <= vyss[i])
                vyss[i] -= vyst[i];
            else
            {
                ot -= vyst[i]-vyss[i];
                vyss[i] = 0;
            }
        }
        n++;
    }
    n--;
    //cout<<n<<endl;
    for(int i = 60; i < 128; i++)
        vys[i] += vyst[i]*n;
    /*for(int i = 60; i < 128; i++)
    {
        cout<<char(i)<<" "<<vys[i]<<endl;
    }*/
    bool p;
    //cout<<"~"<<endl;
    vys[127] = 99999999;
    int x = 60;
    for(int i = 0; i < s.size(); i++)
    {
        //cout<<i<<endl;
        if(s[i] != '?')
            a.push_back(s[i]);
        else
        {
            p = true;
            while(vys[x] <= 0 && p)
            {
                if(x > 125)
                {
                    a.push_back('a');
                    p = false;
                }
                else
                    x++;
            }
            if(p)
            {
                vys[x]--;
                a.push_back(x);
            }
        }
    }
    //reverse(a.begin(), a.end());
}