#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>

using namespace std;

int in[105];
char check[105][100005];

int main()
{
    FILE *fin,*fout;
    fin=fopen("input.txt","r");
    fout=fopen("output.txt","w");
    
    int n;
    fscanf(fin,"%d",&n);
    
    for(int i=0;i<n;i++) fscanf(fin,"%d",&in[i]);
    
    int x1,y1,x2,y2;
    fscanf(fin,"%d%d%d%d",&x1,&y1,&x2,&y2);
    x1--;y1--;x2--;y2--;
    
    queue <int> qx,qy;
    queue <int> que;
    qx.push(x1);
    qy.push(y1);
    que.push(0);
    
    while(!qx.empty())
    {
        int x=qx.front();qx.pop();
        int y=qy.front();qy.pop();
        int tok=que.front();que.pop();
        
        if(x==x2&&y==y2)
        {
            fprintf(fout,"%d\n",tok);
            fclose(fin);
            fclose(fout);
            return 0;
        }
        else
        {
            int a=min(y,in[x-1]),b=min(y,in[x+1]);
            
            if(x!=0&&check[x-1][a]==0)
            {
                qx.push(x-1);
                qy.push(a);
                que.push(tok+1);
                check[x-1][a]=1;
            }
            if(x!=n-1&&check[x+1][b]==0)
            {
                qx.push(x+1);
                qy.push(b);
                que.push(tok+1);
                check[x+1][b]=1;
            }
            if(y!=0&&check[x][y-1]==0)
            {
                qx.push(x);
                qy.push(y-1);
                que.push(tok+1);
                check[x][y-1]=1;
            }
            if(y!=in[x]-1&&check[x][y+1]==0)
            {
                qx.push(x);
                qy.push(y+1);
                que.push(tok+1);
                check[x][y+1]=1;
            }
        }
    }
}