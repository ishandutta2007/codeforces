#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
int c[9][9];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll test;
	cin>>test;
	while(test--)
	{
		for(int i=0; i<9; i++)
    {
      for(int j=0; j<9; j++)
      {
        char ccc;
        cin>>ccc;
        c[i][j]=(ccc-'1');
      }
    }
    c[0][0]=(c[0][0]+1)%9;
    c[1][3]=(c[1][3]+1)%9;
    c[2][6]=(c[2][6]+1)%9;
    c[3][1]=(c[3][1]+1)%9;
    c[4][4]=(c[4][4]+1)%9;
    c[5][7]=(c[5][7]+1)%9;
    c[6][2]=(c[6][2]+1)%9;
    c[7][5]=(c[7][5]+1)%9;
    c[8][8]=(c[8][8]+1)%9;
    for(int i=0; i<9; i++)
    {
      for(int j=0; j<9; j++)
      {
        cout<<c[i][j]+1;
      }
      cout<<'\n';
    }
	}
	return 0;
}