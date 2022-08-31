#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 105

using namespace std;

char str[SIZE];

int main()
{
    scanf("%s",&str);
    int len=strlen(str);
    if(len<5)
    {
        puts("Too weak");
    }
    else
    {
        bool a=false,b=false,c=false;
        for(int i=0;i<len;i++)
        {
            if('A'<=str[i]&&str[i]<='Z') a=true;
            if('a'<=str[i]&&str[i]<='z') b=true;
            if('1'<=str[i]&&str[i]<='9') c=true;
        }
        if(a&&b&&c)
        {
            puts("Correct");
        }
        else
        {
            puts("Too weak");
        }
    }
    return 0;
}