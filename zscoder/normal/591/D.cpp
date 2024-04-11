#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <set>
#include <utility>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define INF 1000000000;
/*A
int main()
{
	int l;
	cin >> l;
	int p, q;
	cin >> p >> q;
	float ans = p * l;
	ans /= (p + q);
	cout << ans << endl;
	return 0;
}
*/
/*B
int main()
{
	int m, n;
	string name;
	cin >> n >> m;
	cin >> name;
	char x, y;
	string ori = "abcdefghijklmnopqrstuvwxyz";
	for(int i = 0; i < m; i++)
	{
		cin >> x >> y;
		for(int j = 0; j < 26; j++)
		{
			if(ori.at(j) == x)
			{
				ori.at(j) = y;
			}
			else if(ori.at(j) == y)
			{
				ori.at(j) = x;
			}
		}
	}
	//cout << ori << endl;
	for(int i = 0; i < n; i++)
	{
		name.at(i) = ori.at(name.at(i) - 97); 
	}
	cout << name << endl;
	return 0;
}*/
/*C
int arr[5000010];

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i + 1];
	}
	arr[0] = arr[1];
	arr[n + 1] = arr[n];
	int ans = 0;
	bool strange = false;
	int start = -1;
	int left = -1;
	int end = -1;
	int right = -1;
	int mid = -1;
	int length = end - start + 1;
	for(int i = 1; i <= n; i++)
	{
		if(arr[i - 1] != arr[i] && arr[i + 1] != arr[i])
		{
			if(!strange)
			{
				strange = true;
				start = i;
				left = arr[i - 1];
			}
		}
		else
		{
			if(strange)
			{
				end = i - 1;
				right = arr[i];
				length = end - start + 1;
				ans = max(ans, ((length + 1)/2));
				mid = length/2 + start - 1;
				for(int j = start; j <= mid; j++)
				{
					arr[j] = left;
				}
				for(int j = mid + 1; j <= end; j++)
				{
					arr[j] = right;
				}
				strange = false;
			}
		}
	}
	cout << ans << endl;
	for(int i = 1; i <= n - 1; i++)
	{
		cout << arr[i] << " ";
	}
	cout << arr[n] << endl;
	return 0;
}*/
double root(double a, double b, double c, double threshold)
{
	if(a != 0)
	{
		double determinant = b*b - 4*a*c;
		double x1 = (-b + sqrt(determinant)) / (2*a);
		double x2 = (-b - sqrt(determinant)) / (2*a);
		if(x2 <= threshold || x2 < 0)
		{
			return x1;
		}
		else
		{
			return x2;
		}
	}
	else
	{
		double answer = -c/b;
		return answer;
	}
}
int main()
{
	double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	double v, t;
	cin >> v >> t;
	double b_x, b_y, l_x, l_y;
	cin >> b_x >> b_y;
	cin >> l_x >> l_y;
	double first_a = v*v - b_x*b_x - b_y*b_y;
	double first_b = (x1 - x2)*b_x + (y1 - y2)*b_y;
	first_b *= -2;
	double first_c = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
	first_c = -first_c;
	//cout << first_a << " " << first_b << " " << first_c << endl;
	double ans_1 = root(first_a, first_b, first_c, -1);
	if(ans_1 == -0)
	{
		ans_1 = 0;
	}
	if(ans_1 <= t)
	{
		cout << setprecision(20) << ans_1 << endl;
		return 0;
	}
	double second_a = v*v - l_x*l_x - l_y*l_y;
	double second_b = l_x*(t*(b_x - l_x) + x1 - x2) + l_y*(t*(b_y - l_y) + y1 - y2);
	second_b *= -2;
	double second_c = (t*(b_x - l_x) + x1 - x2)*(t*(b_x - l_x) + x1 - x2) + (t*(b_y - l_y) + y1 - y2)*(t*(b_y - l_y) + y1 - y2);
	second_c = -second_c;
	double ans_2 = root(second_a, second_b, second_c, t);
	if(ans_2 == -0)
	{
		ans_2 = 0;
	}
	cout << setprecision(20) << ans_2 << endl;
	return 0;
}