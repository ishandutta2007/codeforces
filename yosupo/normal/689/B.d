import std.stdio, std.conv;
import std.algorithm, std.range, std.random;
import std.string, std.array, std.container, std.bigint;
import std.exception;


int main() {
    int n = readln.strip.to!int;;
    int[] a = readln.split.map!(a => a.to!int - 1).array;
    struct Edge(C) {
        int to;
        C cost;
    }
    alias E = Edge!int;
    E[][] e = new E[][](n);
    foreach (i; 0..n) {
        if (i < n-1) {
            e[i] ~= E(i+1, 1);
        }
        if (0 < i) {
            e[i] ~= E(i-1, 1);
        }
        e[i] ~= E(a[i], 1);
    }
    writeln(dijkstra(e, 0).map!(to!string).join(" "));
	return 0;
}


C[] dijkstra(E, C = typeof(E.cost))(in E[][] graph, int s) {
    import std.typecons : Tuple;
    import std.container : Array, BinaryHeap;
    alias Q = Tuple!(int, "to", C, "cost");

    size_t n = graph.length;
    C[] dist = new C[graph.length]; dist[] = E.cost.max;
    bool[] used = new bool[n];
    auto que = BinaryHeap!(Array!Q, "a.cost > b.cost")();
    dist[s] = 0;
    que.insert(Q(s, 0));
    while (!que.empty) {
        auto p = que.front.to; que.popFront;
        if (used[p]) continue;
        used[p] = true;
        foreach (E e; graph[p]) {
            if (dist[e.to] > dist[p] + e.cost) {
                dist[e.to] = dist[p] + e.cost;
                que.insert(Q(e.to, dist[e.to]));
            }
        }
    }
    return dist;
}


string readToken() {
    import std.stdio : readln;
    import std.string : split;
    static size_t pos;
    static string[] tokens;
    while (!(pos < tokens.length)) {
        pos = 0;
        tokens = readln.split;
    }
    return tokens[pos++];
}
T read(T)() {
    import std.conv : to;
    return readToken.to!T;
}