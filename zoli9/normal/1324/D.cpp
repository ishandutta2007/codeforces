//testing code for zsbalazs

#include <bits/stdc++.h>
using namespace std;

vector<int> teacher, student, pos, neg;
//vector<int> a(n, 0);
int main() {
	int n;
  cin >> n;

  long long positive = 0;
  long long negative = 0;
  long long zero = 0;

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;

    teacher.push_back(temp);
  }

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;

    student.push_back(temp);
  }

  for (int i = 0; i < n; i++) {
    int temp;
    temp = teacher[i] - student[i];

    if (temp > 0) {
      positive++;
      pos.push_back(temp);
    } else if (temp < 0) {
      negative++;
      neg.push_back(temp);
    } else {
      zero++;
    }
  }

  long long howMany = 0;
  howMany += positive * (positive-1) /2;
  howMany += zero * positive;

  sort(pos.begin(), pos.end());

  for (int i = 0; i < negative; i++) {
    int low = 0;
    int hi = positive - 1;

    while (low <= hi) {
      int mid= (hi + low)/2;
      if (neg[i] + pos[mid] > 0) {
        hi = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    howMany += positive - low;

  }

  cout << howMany << endl;

	return 0;
}