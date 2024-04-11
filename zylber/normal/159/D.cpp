#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

long long pstart[2010];
long long pend[2010];

int main()
{
    //freopen("D2.in","r",stdin);

    string word;
    cin >> word;
    int s=word.size();

    for(int i=0; i<s; i++)
    for(int j=0; i>=j && i+j<s && word[i-j]==word[i+j]; j++)
    {
        pstart[i-j]++;
        pend[i+j]++;
    }

    for(int i=0; i<s; i++)
    for(int j=0; i>=j && i+j+1<s && word[i-j]==word[i+j+1]; j++)
    {
        pstart[i-j]++;
        pend[i+j+1]++;
    }

    long long ans=0;
    for(int i=0; i<s; i++)
    for(int j=i+1; j<s; j++)
    ans+=pstart[j]*pend[i];

    cout << ans << endl;
}