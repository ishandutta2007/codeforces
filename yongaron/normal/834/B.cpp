#include <iostream>
#include <string>

using namespace std;

int n, k, p;
string s;
int posledni[128];
bool dvere[128];

int main()
{
    cin>>n;
    cin>>k;
    cin>>s;
    for(int i = 0; i < 128; i++)
    {
        dvere[i] = false;
        posledni[i] = 0;
    }
    for(int i = 0; i < n; i++)
    {
        posledni[s[i]] = i;
    }
    p = 0;
    for(int i = 0; i < n; i++)
    {
        if(!dvere[s[i]])
        {
            p++;
            dvere[s[i]] = true;
        }
        if(p > k)
        {
            cout<<"YES"<<endl;
            return 0;
        }
        if(i == posledni[s[i]])
            p--;
    }
    cout<<"NO"<<endl;
    return 0;
}