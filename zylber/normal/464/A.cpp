#include <iostream>
#include <cstring>
using namespace std;

int DP[1024][32][32];
int n, p;
string s;

int calcdp(int i, int l1, int l2)
{
    int &ans=DP[i][l1][l2];
    if(ans!=-1) return ans;
    
    
    if(i==n){ ans=1; return ans; }
    for(int j=0; j<p; j++)
    {
        if(j!=l1 && j!=l2 && calcdp(i+1, j, l1)){ans=1; return ans;}
    }
    
    ans=0;
    return ans;
}

string rec(int i, int j)
{
    s[i]=j+'a';
    
    for(int k=i+1; k<=n; k++)
    {
        for(int r=p-1; r>=0; r--)
            if(s[k-1]!=r+'a' && s[k-2]!=r+'a' && calcdp(k, r, s[k-1]-'a'))
            {
                s[k]=r+'a';

            }
    }
    return s;
}

string finds()
{
    for(int i=n; i>0; i--)
    {
        for(int j=s[i]-'a'+1; j<p; j++)
        {
            if((i<2 || s[i-2]!=j+'a') && s[i-1]!=j+'a')
            {
                if(calcdp(i, j, s[i-1]-'a'))
                {
                    //cout << i << " " << j << endl;
                    return rec(i, j);
                }
            }
        }
    }
    
    return "NO";
}

int main()
{
    memset(DP,-1,sizeof(DP));
    
    cin >> n >> p;
    string r;
    cin >> r;
    s="A";
    s[0]=30;
    s+=r;
    
    string res=finds();
    if(res[0]!='N')
    {
        for(int i=1; i<=n; i++) cout << res[i];
        cout << endl;
    }
    else
        cout << res << endl;
}