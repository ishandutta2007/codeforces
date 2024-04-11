#include<stdio.h>
#include<cstring>
#include<map>
using namespace std;
map<char,int>a;
char c[100005];
int l,r,i,j,k,s;
int main()
{
    a['A']=a['H']=a['I']=a['M']=a['O']=a['T']=a['U']=1;
    a['U']=a['V']=a['W']=a['X']=a['Y']=1;
    scanf("%s",&c);
    r=strlen(c);
    r--;
    l=0;
    while (l<=r)
    {
        if (c[l]!=c[r])
        {
            printf("NO");
            return 0;
        }
        else
        if (!a[c[l]]||!a[c[r]])
        {
            printf("NO");
            return 0;
        }
        l++;
        r--;
    }
    printf("YES");
}