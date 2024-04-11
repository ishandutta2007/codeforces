#include <iostream>

using namespace std;

int main()
{
	int p[4];
	cin>>p[0]>>p[1]>>p[2]>>p[3];
	
	int i,j,ans=0;
	for(i=0;i<3;i++)
	{
		if(p[i]==0) continue;
		for(j=i+1;j<4;j++)
		{
			if(p[i]==p[j])
			{
				p[j]=0;
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}