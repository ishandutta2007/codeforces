#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    FILE *fin,*fout;
    fin=fopen("input.txt","r");
    fout=fopen("output.txt","w");
    
    int n,m;
    fscanf(fin,"%d %d",&n,&m);
    
    if(n>m)
    {
        for(int i=0;i<m;i++) fprintf(fout,"BG");
        for(int i=0;i<n-m;i++) fprintf(fout,"B");
        fprintf(fout,"\n");
    }
    else
    {
        for(int i=0;i<n;i++) fprintf(fout,"GB");
        for(int i=0;i<m-n;i++) fprintf(fout,"G");
        fprintf(fout,"\n");
    }
    fclose(fin);
    fclose(fout);
    return 0;
}