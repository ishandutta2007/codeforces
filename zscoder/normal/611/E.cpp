#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define DEBUG(x) cout << "> " << #x << ": " << x << endl; //Debug

const ll INF = 1000000000;
const ll MOD = 1000000007;

/*bool compare(ii a, ii b)
{
	if(a.first < b.first)
	{
		return true;
	}
	else if(a.first > b.first)
	{
		return false;
	}
	else
	{
		if(a.second > b.second)
		{
			return false;
		}
		return true;
	}
}*/

//freopen("input.txt", "r", stdin);
/*A
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	cin >> s;
	if(s.at(0) == 'm')
	{
		if(n <= 29)
		{
			cout << 12;
		}
		else if(n == 30)
		{
			cout << 11;
		}
		else
		{
			cout << 7;
		}
	}
	else
	{
		if(n <= 4)
		{
			cout << 52;
		}
		else if(n == 7)
		{
			cout << 52;
		}
		else
		{
			cout << 53;
		}
	}
	return 0;
}*/
/*B
vi binary(ll a)
{
	vi vec;
	while(a > 0)
	{
		vec.push_back(a%2);
		a /= 2;
	}
	reverse(vec.begin(), vec.end());
	return vec;
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll a, b;
	cin >> a >> b;
	vi x, y;
	x = binary(a);
	y = binary(b);
	ll sum = 0;
	int counter = x.size();
	int counter2 = y.size();
	int count = 0;
	int count2 = 0;
	for(int i = 0; i < x.size(); i++)
	{
		if(x.at(i) == 0)
		{
			if(count == 0)
			{
				counter = i;
			}
			count++;
		}
	}
	for(int i = 0; i < y.size(); i++)
	{
		if(y.at(i) == 0)
		{
			if(count2 == 0)
			{
				counter2 = i;
			}
			count2++;
		}
	}
	//cout << counter << " " << counter2 << endl;
	if(x.size() == y.size())
	{
		sum = counter2 - counter;
		if(count2 == 1)
		{
			sum++;
		}
	}
	else
	{
		sum += counter2 - 1;
		sum += x.size() - counter;
		for(int i = x.size() + 1; i < y.size(); i++)
		{
			sum += i-1;
		}
		if(count2 == 1)
		{
			sum++;
		}
	}
	cout << sum;
	return 0;
}
*/
/*
char board[501][501];
int query[100001][4];
int rightdomino[510][510];
int up[510][510];
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	int h, w;
	cin >> h >> w;
	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < w; j++)
		{
			cin >> board[i][j];
		}
	}
	for(int i = 0; i < 510; i++)
	{
		for(int j = 0; j < 510; j++)
		{
			rightdomino[i][j] = 0;
			up[i][j] = 0;
		}
	}
	int q;
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		cin >> query[i][0] >> query[i][1] >> query[i][2] >> query[i][3];
	}
	for(int i = 1; i <= h; i++)
	{
		for(int j = 1; j <= w; j++)
		{
			if(j > 1)
			{
				rightdomino[i][j] = rightdomino[i][j-1];
				if(i > 1)
				{
					rightdomino[i][j] += rightdomino[i-1][j];
					rightdomino[i][j] -= rightdomino[i-1][j-1];
				}
				//cout << i << " " << j << " " << rightdomino[i][j] << " ";
				if(board[i-1][j-1] == '.' && board[i-1][j-2] == '.')
				{
					rightdomino[i][j]++;
				}
			}
			//cout << rightdomino[i][j] << " ";
		}
		//cout << endl;
	}
	//cout << endl;
	for(int j = 1; j <= w; j++)
	{
		for(int i = 1; i <= h; i++)
		{
			if(i > 1)
			{
				up[i][j] = up[i-1][j]; 
				if(j > 1)
				{
					up[i][j] += up[i][j-1];
					up[i][j] -= up[i-1][j-1];
				}
				if(board[i-1][j-1] == '.' && board[i-2][j-1] == '.')
				{
					up[i][j]++;
				}
			}
			//cout << up[i][j] << " ";
		}
		//cout << endl;
	}
	//cout << endl;
	int ans = 0;
	int x1, y1, x2, y2;
	for(int i = 0; i < q; i++)
	{
		ans = 0;
		x1 = query[i][0];
		y1 = query[i][1];
		x2 = query[i][2];
		y2 = query[i][3];
		if(x1 > 1 && y1 > 1)
		{
			ans += rightdomino[x2][y2] - rightdomino[x1-1][y2] - rightdomino[x2][y1] + rightdomino[x1-1][y1];
		}
		else if(x1 > 1)
		{
			ans += rightdomino[x2][y2] - rightdomino[x1-1][y2];
		}
		else if(y1 > 1)
		{
			ans += rightdomino[x2][y2] - rightdomino[x2][y1];
		}
		else
		{
			ans += rightdomino[x2][y2];
		}
		//cout << ans << " ";
		if(x1 > 1 && y1 > 1)
		{
			ans += up[x2][y2] - up[x1][y2] - up[x2][y1-1] + up[x1][y1-1];
		}
		else if(x1 > 1)
		{
			ans += up[x2][y2] - up[x1][y2];
		}
		else if(y1 > 1)
		{
			ans += up[x2][y2] - up[x2][y1-1];
		}
		else
		{
			ans += up[x2][y2];
		}
		cout << ans << endl;
	}
	return 0;
}
*/
/*D
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	string x;
	cin >> x;
	
	return 0;
}*/
ll maximum(ll a, ll b)
{
	if(a > b)
	{
		return a;
	}
	return b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	vi vec;
	int x;
	for(int i = 0; i < 3; i++)
	{
		cin >> x;
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end());
	ll a, b, c;
	a = vec.at(0);
	b = vec.at(1);
	c = vec.at(2);
	
	vi crime;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		crime.push_back(x);
	}
	//sort(crime.begin(), crime.end());
	//reverse(crime.begin(), crime.end());
	ll arr[7];
	arr[0] = a;
	arr[1] = b;
	arr[2] = min(a+b, c);
	arr[3] = maximum(a+b, c);
	arr[4] = a+c;
	arr[5] = b+c;
	arr[6] = a+b+c;
	ll count[7];
	for(int i = 0; i < 7; i++)
	{
		count[i] = 0;
	}
	for(int i = 0; i < crime.size(); i++)
	{
		if(crime.at(i) > arr[6])
		{
			cout << -1;
			return 0;
		}
		else if(crime.at(i) > arr[5])
		{
			count[6]++;
		}
		else if(crime.at(i) > arr[4])
		{
			count[5]++;
		}
		else if(crime.at(i) > arr[3])
		{
			count[4]++;
		}
		else if(crime.at(i) > arr[2])
		{
			count[3]++;
		}
		else if(crime.at(i) > arr[1])
		{
			count[2]++;
		}
		else if(crime.at(i) > arr[0])
		{
			count[1]++;
		}
		else
		{
			count[0]++;
		}
	}
	/*for(int i = 0; i < 7; i++)
	{
		cout << count[i] << " ";
	}
	cout << endl;*/
	
	
	ll sum = 0;
	sum += count[6];
	while(count[5] > 0)
	{
		sum++;
		if(count[0] > 0)
		{
			count[0]--;
		}
		count[5]--;
	}
	while(count[4] > 0)
	{
		sum++;
		if(count[1] > 0)
		{
			count[1]--;
		}
		else if(count[0] > 0)
		{
			count[0]--;
		}
		count[4]--;
	}
	
	if(a + b > c)
	{
		while(count[3] > 0)
		{
			sum++;
			count[3]--;
			if(count[2] > 0)
			{
				count[2]--;
			}
			else if(count[1] > 0)
			{
				count[1]--;
			}
			else if(count[0] > 0)
			{
				count[0]--;
			}
		}
		while(count[2] > 0)
		{
			sum++;
			count[2]--;
			if(count[1] > 0 && count[0] > 0)
			{
				count[1]--;
				count[0]--;
			}
			
			else if(count[0] > 1)
			{
				if(count[0] > 1)
				{
					count[0] -= 2;
				}
				else
				{
					count[0]--;
				}
			}
			else if(count[2] > 0)
			{
				count[2]--;
			}
			else if(count[1] > 0)
			{
				count[1]--;
			}
			else if(count[0] == 1)
			{
				count[0]--;
			}
		}
	}
	else
	{
		while(count[3] > 0)
		{
			sum++;
			count[3]--;
			if(count[0] > 0 && count[1] > 0)
			{
				count[0]--;
				count[1]--;
			}
			else if(count[0] > 0)
			{
				count[0] = max(ll(0), count[0]-2);
			}
			else if(count[2] > 0)
			{
				count[2]--;
			}
			else if(count[1] > 0)
			{
				count[1]--;
			}
			
		}
		while(count[2] > 0)
		{
			sum++;
			count[2]--;
			if(count[1] > 0 && count[0] > 0)
			{
				count[0]--;
				count[1]--;
			}
			else if(count[0] > 0)
			{
				count[0] = max(ll(0), count[0]-2);
			}
			else if(count[2] > 0)
			{
				count[2]--;
			}
			else if(count[1] > 0)
			{
				count[1]--;
			}
		}
	}
	
	while(count[1] > 0)
	{
		sum++;
		if(count[0] > 0)
		{
			if(count[1] > 1)
			{
				count[1] -= 2;
				count[0]--;
			}
			else
			{
				count[1]--;
				count[0] = maximum(ll(0), count[0]-2);
			}
		}
		else
		{
			count[1] = maximum(ll(0), count[1]-2);
		}
	}
	while(count[0] > 0)
	{
		count[0] -= 3;
		sum++;
	}
	cout << sum;
	return 0;
}
/*F
int main()
{
	ios_base::sync_with_stdio(false);
	return 0;
}*/
/*G
int main()
{
	ios_base::sync_with_stdio(false);
	return 0;
}*/
/*H
int main()
{
	ios_base::sync_with_stdio(false);
	return 0;
}*/