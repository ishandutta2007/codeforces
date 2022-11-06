#include <iostream>
#include <string>

using namespace std;

int k, x = 0;
string s;
char cis[100005];
int poc[10];

int main()
{
    cin>>k;
    cin>>s;
    for(int i = 0; i < 10; i++)
    {
        poc[i] = 0;
    }
    for(int i = 0; i < s.size(); i++)
    {
        cis[i] = s[i]-48;
        x += cis[i];
        poc[cis[i]]++;
    }
    int i = 0;
    int n = 0;
    while(x < k)
    {
        if(poc[i])
        {
            poc[i]--;
            x += 9-i;
            n++;
        }
        else
            i++;
    }
    cout<<n<<endl;
    return 0;
}