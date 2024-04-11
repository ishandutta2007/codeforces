#include <cstdio>

int main()
{
    char input[101]; int n;
    for(n=0;n<=100;n++)
    {
        scanf("%c",input+n);
        if(input[n]==10) break;
    }
    bool flag=true;
    for(int i=0;i<n;i++)
    {
        if(input[i]=='a'||input[i]=='e'||input[i]=='i'||input[i]=='o'||input[i]=='u'||input[i]=='n'||input[i+1]=='a'||input[i+1]=='e'||input[i+1]=='i'||input[i+1]=='o'||input[i+1]=='u') continue;
        flag=false; break;
    }
    if(flag) printf("YES"); else printf("NO");
    return 0;
}