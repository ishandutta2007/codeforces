# include <iostream>
# include <sstream>
# include <string>
# include <vector>
# include <cstdlib>
using namespace std;
stringstream output;
void error()
{
	cout << "Error occurred\n";
	exit(0);
}
vector <string> :: iterator solve(vector <string> :: iterator start, vector <string> :: iterator end)
{
// 	for (auto x = start; x < end; ++x)
// 		cout << *x << ' ';
// 	cout << endl;
	if (start >= end)
		error();
	if (*start == "pair")
	{
// 		cout << "call 2" << endl;
		output << "pair<";
		auto next = solve(start + 1, end);
		output << ",";
		auto ret = solve(next, end);
		output << ">";
		return ret;
	}
	else
	{
// 		cout << "terminate" << endl;
		output << *start;
		return start + 1;
	}
}
int main()
{
	vector <string> input;
	int n;
	cin >> n;
	while (!cin.eof())
	{
		string a;
		cin >> a;
		if (a != "")
			input.push_back(a);
		cin.ignore();
	}
// 	cout << input.size() << endl;
	auto end = solve(input.begin(), input.end());
// 	cout << "left with" << endl;
// 	for (auto x = end; x != input.end(); ++x)
// 		cout << *x;
// 	cout << input.end() - end << endl;
// 	cout << endl;
// 	cout << "still ok" << endl;
	if (end != input.end())
		error();
	cout << output.str() << "\n";
}