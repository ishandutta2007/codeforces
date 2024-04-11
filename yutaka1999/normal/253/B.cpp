#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define INF 10000

using namespace std;
int in[100005];

int main()
{
    FILE *fin,*fout;
    fin=fopen("input.txt","r");
    fout=fopen("output.txt","w");
    
    int n;
    fscanf(fin,"%d",&n);
    
    for(int i=0;i<n;i++) fscanf(fin,"%d",&in[i]);
    sort(in,in+n);
    in[n]=INF;
    
    int mini=-1;
    for(int i=0;i<n;i++)
    {
        int a=upper_bound(in,in+n+1,in[i]*2)-in;
        int b=(n-a)+i;
        if(mini==-1||mini>b) mini=b;
    }
    
    fprintf(fout,"%d\n",mini);
    
    fclose(fin);
    fclose(fout);
    return 0;
}