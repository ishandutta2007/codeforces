#include <iostream>
#include <string>

using namespace std;

bool h, good[128];
int n, k;
string s, t[100000];

void nacti();
void vyres();

int main()
{
    nacti();
    for(k = 0; k < n; k++)
        vyres();
    return 0;
}
void nacti()
{
    cin>>s;
    for(int i = 0; i < 128; i++)
        good[i] = false;
    for(int i = 0; i < s.size(); i++)
        good[s[i]] = true;
    h = false;
    /*for(int i = 0; i < 128; i++)
        cout<<(char)i<<" "<<good[i]<<endl;*/
    cin>>s;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '*')
            h = true;
    }
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>t[i];
    }
}
void vyres()
{
    int x = 0;
    int r = t[k].size() - s.size();
    if(r < -1 || (r != 0 && !h))
    {
        cout<<"NO"<<endl;
        return;
    }
    for(int i = 0; i < s.size(); i++, x++)
    {
        if(s[i] == '?' && !good[t[k][x]])
        {
            cout<<"NO"/*<<" "<<k<<" "<<i<<" "<<x*/<<endl;
            return;
        }
        else if(s[i] == '*')
        {
            for(int j = 0; j <= r; j++, x++)
            {
                if(good[t[k][x]])
                {
                    cout<<"NO"/*<<" "<<k<<" "<<i<<" "<<x*/<<endl;
                    return;
                }
            }
            x--;
        }
        else if(s[i] != '?')
        {
            if(s[i] != t[k][x])
            {
                cout<<"NO"/*<<" "<<k<<" "<<i<<" "<<x*/<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
}
/*
abc
a*a??
5
aaaaa
adaaa
adabb
abadd
bdabb
*/