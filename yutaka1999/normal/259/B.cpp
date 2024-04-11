#include <cstdio>
#include <cstdlib>

using namespace std;

int in[5][5];

int main()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++) scanf("%d",&in[i][j]);
    }
    
    in[1][1]=(in[0][1]+in[2][1])/2;
    in[0][0]=(in[1][2]+in[2][1])/2;
    in[2][2]=in[1][1]*2-in[0][0];
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(j==0) printf("%d",in[i][j]);
            else printf(" %d",in[i][j]);
        }
        printf("\n");
    }
    return 0;
}