#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;
int so[1002];
int to[1002];
int poi[1002];
int dra[1002];

int main()
{
    int s,n;
    scanf("%d %d",&s,&n);
    
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        dra[i]=a;
        to[i]=b;
        so[i]=dra[i];
    }
    
    sort(dra,dra+n);
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dra[i]==so[j])
            {
                poi[i]=to[j];
                so[j]=-1;
                break;
            }
        }
    }
    
    int i;
    for(i=0;i<n;i++)
    {
        //printf("%d %d\n",dra[i],poi[i]);
        if(s<=dra[i]) break;
        s+=poi[i];
    }
    if(i==n) printf("YES\n");
    else printf("NO\n");
    return 0;
}