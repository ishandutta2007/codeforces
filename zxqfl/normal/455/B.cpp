#include <bits/stdc++.h>

#define sloop(i, s, x) for (int i = (s); i < (x); i++)
#define loop(i, x) sloop(i, 0, x)
#define rep(x) loop(COUNTER, x)
#define mp make_pair
#define pb push_back
#define INF ((int) 1e9)
#define rint(x) scanf("%d", &(x))

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

#define WIN 1
#define LOSS 2
#define CHOICE 3
#define NCHOICE 4

int N, K;

struct trie
{
	trie *child[26];
	int state;

	trie()
	{
		loop(i, 26)
			child[i] = NULL;
		state = -1;
	}

	void solve()
	{
		bool canWin = false;
		bool canLose = false;
		bool canChoice = false;
		loop(i, 26) if (child[i])
		{
			child[i]->solve();
			if (child[i]->state == LOSS)
				canWin = true;
			if (child[i]->state == WIN)
				canLose = true;
			if (child[i]->state == CHOICE)
				canChoice = true;
			if (child[i]->state == NCHOICE)
			{
				state = CHOICE;
				return;
			}
		}

		if (!(canWin || canLose || canChoice))
			state = LOSS;
		else if (canWin && canLose)
			state = CHOICE;
		else if (canWin)
			state = WIN;
		else if (canLose)
			state = LOSS;
		else
			state = NCHOICE;
	}

	trie* get(int x)
	{
		if (child[x] == NULL)
			child[x] = new trie();
		return child[x];
	}

} root;

int main()
{
	rint(N), rint(K);

	rep(N)
	{
		char buf[100001];
		scanf("%s", buf);

		trie* t = &root;
		for (int i = 0; buf[i]; i++)
		{
			t = t->get(buf[i] - 'a');
		}
	}

	root.solve();
	if (root.state == CHOICE)
		printf("First\n");
	else if (root.state == LOSS)
		printf("Second\n");
	else if (root.state == WIN)
		printf(K % 2 == 1 ? "First\n" : "Second\n");
	else
		printf("Second\n");
}