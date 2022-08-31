import std.stdio, std.range, std.string, std.algorithm, std.conv;

void main() {
    int n; double m;
    readf("%d\n%f\n", &n, &m);
    double[] a = readln.strip.split.map!(to!double).array;
    double[] b = readln.strip.split.map!(to!double).array;    
    bool check(double fuel) {
        foreach (p; zip(a, b)) {
            double now_a = p[0], now_b = p[1];
            fuel -= (m + fuel) / now_a;
            if (fuel < 0) return false;
            fuel -= (m + fuel) / now_b;
            if (fuel < 0) return false;
        }
        return true;
    }
    if (!check(1e10)) {
        writeln(-1);
        return;
    }
    double min_x = 0, max_x = 1e9;
    foreach (phase; 0..200) {
        double mid = (min_x + max_x) / 2;
        if (!check(mid)) min_x = mid;
        else max_x = mid;
    }
    writefln("%.20f", max_x);
}