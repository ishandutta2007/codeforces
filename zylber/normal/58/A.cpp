#include <iostream>
#include <cstring>
using namespace std;

int DP[128][8];
string hola="hello";


int main()
{
    string s;
    cin >> s;
    string tmp="a";
    tmp+=s;
    s=tmp;
    int ss=s.size();
    
    memset(DP,0,sizeof(DP));
    
    for(int i=0; i<ss; i++)
        DP[i][0]=1;
    for(int j=0; j<5; j++)
        for(int i=1; i<ss; i++)
        {
            DP[i][j+1]|=DP[i-1][j+1];
            if(hola[j]==s[i]) DP[i][j+1]|=DP[i-1][j];
        }
    
    if(DP[ss-1][5]) cout << "YES" << endl; else cout << "NO" << endl;
}