#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 4006;
int s[N];

bool hhave[1000006];

int main ()
{
    int n;
    scanf("%d",&n);
    int tmp=0;
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&s[i]);
        tmp = __gcd(s[i],tmp);
    }
    if (tmp != s[1])
    {
        puts("-1");
        return 0;
    }
    vector<int> ans;
    for (int i=1;n>=i;i++)
    {
        ans.push_back(s[1]);
        ans.push_back(s[i]);
    }
    printf("%d\n",(int)ans.size());
    for (int i:ans) cout <<i <<' ';
    cout<<endl;
}