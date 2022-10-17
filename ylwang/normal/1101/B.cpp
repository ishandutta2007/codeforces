#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int i,j,k,l,len,ans;
char c[500010];         // 

int main()
{
    gets(c);
    len = strlen(c);    //

    for(i=0;c[i]!='['&&i<len;i++);  // 

    for(j=len-1;c[j]!=']'&&j>=0;j--);   // 

    for(k=i+1;c[k]!=':'&&k<len-1;k++);  // 

    for(l=j-1;c[l]!=':'&&l>k;l--);  // 

    if(i>=j||l<=k)      // -1 
        printf("-1\n");
    else
    {
        for(int x=k+1;x<l;x++)  //
            if(c[x]=='|') ans++;  // 

        printf("%d\n",ans+4);    // 
    }
    return 0;
}