#include<cstdio>
#include<algorithm>
using namespace std;
bool b1[1000001];
char op[2];
int main()
{
    int n,a=0,b=0,c,o=0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s%d",op,&c);
        if(op[0]=='+')b1[c]=1,a=max(a,++b);
        else if(b1[c])b1[c]=0,--b;
        else ++o,--b;
    }
    printf("%d\n",o+a);
}