import std.stdio, std.string, std.conv, std.algorithm, std.container;

int main() {
	int n;
	auto u = new RedBlackTree!(long);
	readf("%d\n", &n);
	string[] input = readln().split();
	foreach (s; input) {
		long a = to!long(s);
		while (a in u) {
			u.removeKey(a);
			a++;
		}
		u.stableInsert(a);
	}
	writeln(u.back() + 1 - u.length());
    return 0;
}