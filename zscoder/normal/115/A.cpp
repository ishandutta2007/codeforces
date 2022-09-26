#include <iostream>
#include <stack>
#include <utility>
#include <queue>
#include <vector>
#define max(a, b)(a > b ? a : b)

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int arr[2001];
	vector<int> big_bosses, subordinates[2001];
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if(arr[i] != -1)
		{
			arr[i]--;
			subordinates[arr[i]].push_back(i);
		}
		else
		{
			big_bosses.push_back(i);
		}
	}
	
	int lengths[2001], max_length = 1;
	queue<int> to_visit;
	
	for(int i = 0; i < big_bosses.size(); i++)
	{
		to_visit.push(big_bosses.at(i));
		while(!to_visit.empty())
		{
			int current_node = to_visit.front();
			to_visit.pop();
			int manager = arr[current_node];
			
			if(manager == -1)
			{
				lengths[current_node] = 1;
			}
			else
			{
				lengths[current_node] = lengths[manager] + 1;
			}
			
			for(int j = 0; j < subordinates[current_node].size(); j++)
			{
				to_visit.push(subordinates[current_node].at(j));
			}
			max_length = max(max_length, lengths[current_node]);
		}
	}
	
	cout << max_length << endl;
	/*O(n^2) solution : 30ms
	int longest_length = 1;
	for(int i = 0; i < n; i++)
	{
		int current_length = 0;
		int current_node = i;
		while(current_node != -2)
		{
			current_node = arr[current_node] - 1;
			current_length++;
			//cout << current_node << endl;
		}
		longest_length = max(longest_length, current_length);
	}
	cout << longest_length;*/
	return 0;
}