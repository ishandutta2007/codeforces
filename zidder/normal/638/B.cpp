#include <iostream>
#include <cstring>
using namespace std;
char s[30],prev[200],next[200];
int mark[200],n,i,m,j,used[200];
int main()
{
    cin>>n;
    for (j=0; j<n; j++)
    {
        cin>>s;
        m=strlen(s);
        used[s[0]]=1;
        for (i=1; i<m; i++)
        {
            prev[s[i]]=s[i-1];
            next[s[i-1]]=s[i];
            used[s[i]]=1;
        }
    }
    for (i=0; i<190; i++)
    {
        if (mark[i]==1) continue;
        if (prev[i]!=0) continue;
        if (next[i]==0) continue;
        j=i;
        cout<<(char) j;
        while (next[j]!=0)
        {
            mark[j]=1;
            mark[next[j]]=1;
            cout<<next[j];
            j=next[j];
        }
    }
    for (i=0; i<190; i++)
    {
        if ((mark[i]==0) && (used[i]==1))
            cout<<(char) i;
    }
    cout<<endl;
    return 0;
}