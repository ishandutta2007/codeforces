#include <stdio.h>
#include <stdlib.h>
#define max 20000000

int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
int n,m,i,j,nx,ny,nd,x,y;
int zlx[max+5],zly[max+5],h,t;
int f[1005][1005][4];
char zld[max+5];
char str[1005][1005];

int main()
{
    scanf("%d %d\n",&n,&m);
    for(i=1;i<=n;i++)
    	gets(str[i]+1);
    for(i=1;i<=n;i++)
    	for(j=1;j<=m;j++)
    		f[i][j][0]=f[i][j][1]=f[i][j][2]=f[i][j][3]=16161616;
    f[n][m][0]=0;
    zlx[1]=n,zly[1]=m,zld[1]=0;
    for(h=0,t=1;h!=t;)
    {
		h++;
		if (h>max) h-=max;
		nx=zlx[h],ny=zly[h],nd=zld[h];
		x=nx+dx[nd],y=ny+dy[nd];
		if (x>0 && x<=n && y>0 && y<=m)
		{
			if (f[nx][ny][nd]<f[x][y][nd])
			{
				f[x][y][nd]=f[nx][ny][nd];
				t++;
				if (t>max) t-=max;
				zlx[t]=x,zly[t]=y,zld[t]=nd;
			}
		}
		if (str[nx][ny]=='#')
		{
			for(i=0;i<4;i++)
			{
				if (i==nd) continue;
				if (f[nx][ny][nd]+1<f[nx][ny][i])
				{
					f[nx][ny][i]=f[nx][ny][nd]+1;
					t++;
					if (t>max) t-=max;
					zlx[t]=nx,zly[t]=ny,zld[t]=i;
				}
			}
		}
	}
	if (f[1][1][0]==16161616) printf("-1\n");
	else printf("%d\n",f[1][1][0]);
    return 0;
}