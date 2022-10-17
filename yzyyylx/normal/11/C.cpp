#include<bits/stdc++.h>
#define ll long long
#define N 260
using namespace std;

int a[N][N],T,TT,m,n,ttp;
bool ttp2;
string x;

bool ss(int u,int v)
{
	int i,j,an=0,an2=0;
	an=a[u][v+1]+a[u][v-1]+a[u+1][v]+a[u-1][v];
	an2=a[u+1][v+1]+a[u+1][v-1]+a[u-1][v+1]+a[u-1][v-1];
	if(an==2&&an2<=2||an2==2&&an==0)
	return true;
	return false;
}

int ss2(int u,int v)
{
	int i,j,an=0;
	for(i=u-1;i<=u+1;i++)
	{
		for(j=v-1;j<=v+1;j++)
		{
			an+=a[i][j];
		}
	}
	return an;
}

void zh(int u,int v)
{
	int i,j;
	for(i=u-1;i<=u+1;i++)
	{
		for(j=v-1;j<=v+1;j++)
		{
			if(a[i][j]==1)
			{
				a[i][j]=2;
				zh(i,j);
			}
		}
	}
}

int main()
{
	int i,j,k,l,p,q;
	cin>>T;
	while(T--)
	{
		scanf("%d%d",&m,&n);
		memset(a,0,sizeof(a));
		int ans=0;
		for(i=1;i<=m;i++)
		{
			cin>>x;
			for(j=0;j<n;j++)
			{
				a[i][j+1]=x[j]-48;
			}
		}
//		cout<<ss(2,1);
		/*
		cout<<endl;
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				cout<<a[i][j];
			}
			cout<<endl;
		}
		//*/
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(a[i][j]==1)
				{
//					cout<<ss2(i,j)<<" ";
					p=ss(i,j);
					if(p==true) continue;
//					cout<<p<<" ";
					a[i][j]=2;
					zh(i,j);
				}
			}
		}
		
		/*
		cout<<endl;
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				cout<<a[i][j];
			}
			cout<<endl;
		}
		//*/
		
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(a[i][j]==1)
				{
					int bc=1;
					k=i;
					while(a[k+1][j]==1)
					{
						k++;
						bc++;
					}
//					cout<<bc<<" ";
					
					if(bc!=1)
					{
						bool z;
						z=true;
						for(k=1;k<=bc;k++)
						{
//							cout<<a[i+k-1][j]<<a[i+k-1][j+bc-1]<<a[i+bc-1][j+k-1]<<a[i][j+k-1]<<endl;
							if(a[i+k-1][j]!=1||a[i+k-1][j+bc-1]!=1||a[i+bc-1][j+k-1]!=1||a[i][j+k-1]!=1)
							{
//								a[i+k-1][j]=a[i+k-1][j+bc-1]=a[i+bc-1][j+k-1]=a[i][j+k-1]=0;
								z=false;
								break;
							}
						}
//						cout<<z<<" ";
						if(z==true)
						{
//							zh(i,j);
//							return 0;
							ans++;
							for(k=1;k<=bc;k++)
							{
								a[i+k-1][j]=a[i+k-1][j+bc-1]=a[i+bc-1][j+k-1]=a[i][j+k-1]=10;
							}
							
							/*
							cout<<endl;
							for(k=1;k<=m;k++)
							{
								for(l=1;l<=n;l++)
								{
									cout<<a[k][l]<<" ";
								}
								cout<<endl;
							}
							//*/
//							k=1;
//							cout<<i+k-1<<" "<<j<<" "<<i+k-1<<" "<<j+bc-1<<" "<<i+bc-1<<" "<<j+k-1<<" "<<i<<" "<<j+k-1<<endl;
//							cout<<ss2(i+k-1,j)<<" "<<ss2(i+k-1,j+bc-1)<<" "<<ss2(i+bc-1,j+k-1)<<" "<<ss2(i,j+k-1)<<endl;
							for(k=1;k<=bc;k++)
							{
								if(ss2(i+k-1,j)%10!=0||ss2(i+k-1,j+bc-1)%10!=0||ss2(i+bc-1,j+k-1)%10!=0||ss2(i,j+k-1)%10!=0)
								{
									ans--;
									break;
								}
							}
							for(k=1;k<=bc;k++)
							{
								a[i+k-1][j]=a[i+k-1][j+bc-1]=a[i+bc-1][j+k-1]=a[i][j+k-1]=1;
							}
							zh(i,j);
//							return 0;
						}
					}
					else
					{
						bool z;
						z=true;
						k=i;
						l=j;
						while(a[k+1][l-1]==1)
						{
							k++;
							l--;
							bc++;
						}
//						cout<<bc<<" ";
						if(bc==1) continue;
//						cout<<endl<<i<<" "<<j<<":"<<endl;
						for(k=1;k<=bc;k++)
						{
//							cout<<a[i+k-1][j+k-1]<<a[i+bc+k-2][j+k-bc]<<a[i+k-1][j-k+1]<<a[i+bc+k-2][j+bc-k]<<endl;
//							cout<<i+k-1<<" "<<j+k-1<<" "<<i+bc+k-2<<" "<<j+bc-k<<endl;
							if(a[i+k-1][j+k-1]!=1||a[i+bc+k-2][j+k-bc]!=1||a[i+k-1][j-k+1]!=1||a[i+bc+k-2][j+bc-k]!=1)
							{
								z=false;
								break;
							}
						}
						if(z==true)
						{
							ans++;
							for(k=1;k<=bc;k++)
							{
								a[i+k-1][j+k-1]=a[i+bc+k-2][j+k-bc]=a[i+k-1][j-k+1]=a[i+bc+k-2][j+bc-k]=0;
							}
							
							for(k=1;k<=bc;k++)
							{
								if(ss(i+k-1,j+k-1)%10!=0||ss(i+k+bc-2,j+k-bc)%10!=0||ss(i+k-1,j-k+1)%10!=0||ss(i+bc+k-2,j+bc-k)%10!=0)
								{
									ans--;
									break;
								}
							}
							
							for(k=1;k<=bc;k++)
							{
								a[i+k-1][j+k-1]=a[i+bc+k-2][j+k-bc]=a[i+k-1][j-k+1]=a[i+bc+k-2][j+bc-k]=1;
							}
							zh(i,j);
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}