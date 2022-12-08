#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string names[100010][2];
int ord[100010];

int main()
{
#ifdef ACMTUYO
	freopen("C.in","r",stdin);
#endif

	int n;
	cin >> n;
	
	for(int i=0; i<n; i++)
	{
		cin >> names[i][0] >> names[i][1];
		if(names[i][0]>names[i][1]) swap(names[i][0], names[i][1]);
		//cout << names[i][0] << " " << names[i][1] << endl;
	}
	
	for(int i=0; i<n; i++)
	{
		cin >> ord[i];
		ord[i]--;
	}
	string now=names[ord[0]][0];
	
	for(int i=1; i<n; i++)
	{
		//cout << now << endl;
		if(names[ord[i]][0]>now) now=names[ord[i]][0];
		else
		{
			if(names[ord[i]][1]>now) now=names[ord[i]][1];
			else
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}