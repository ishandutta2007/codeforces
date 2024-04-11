#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <ctype.h>

using namespace std;
char in[102];

int main()
{
    scanf("%s",&in);
    
    int sum=0;
    for(int k=1;k<strlen(in);k++) if(in[k]-'A'>=0&&in[k]-'A'<26) sum++;
    if(strlen(in)==1)
    {
        if(in[0]-'A'<0||in[0]-'A'>=26) in[0]=toupper(in[0]);
        else in[0]=tolower(in[0]);
    }
    else if(sum==strlen(in)-1)
    {
        for(int i=0;i<strlen(in);i++)
        {
            if(in[i]-'a'>=0&&in[i]-'a'<26) in[i]=toupper(in[i]);
            else in[i]=tolower(in[i]);
        }
    }
    printf("%s\n",in);
    
    return 0;
}