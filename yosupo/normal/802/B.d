/+ dub.sdl:
    name "B"
    dependency "dcomp" version=">=0.6.0"
+/

import std.stdio, std.algorithm, std.range, std.conv;
// import dcomp.foundation, dcomp.scanner, dcomp.array;
import std.typecons;
import std.container.rbtree;

int main() {
    auto sc = new Scanner(stdin);
    int n, k;
    int[] a;
    sc.read(n, k, a); a[] -= 1;

    int[][] l = new int[][n];
    foreach (int i, d; a) {
        l[d] ~= i;
    }
    l.each!((ref v) => v ~= n);
    auto used = new bool[n];
    int sm = 0;

    auto tr = redBlackTree!(int[2]);
    foreach (d; a) {
        int ba = l[d][0];
        l[d] = l[d][1..$];
        int nx = l[d][0];
        if (used[d]) {
            tr.removeKey([ba, d].fixed);
            tr.insert([nx, d].fixed);
            continue;
        }
        // add d
        if (tr.length == k) {
            auto u = tr.back();
            tr.removeBack();
            used[u[1]] = false;
        }
        sm++;
        tr.insert([nx, d].fixed);
        used[d] = true;
    }
    writeln(sm);
    return 0;
}
/* IMPORT /Users/yosupo/Program/dcomp/source/dcomp/array.d */
// module dcomp.array;

 
T[N] fixed(T, size_t N)(T[N] a) {return a;}

 
 

 
 
struct FastAppender(A) {
    import std.algorithm : max;
    import std.range.primitives : ElementEncodingType;
    import core.stdc.string : memcpy;

    private alias T = ElementEncodingType!A;
    private T* _data;
    private size_t len, cap;
     
    @property size_t length() {return len;}
     
    void reserve(size_t nlen) {
        import core.memory : GC;
        if (nlen <= cap) return;
        
        void* nx = GC.malloc(nlen * T.sizeof);

        cap = nlen;
        if (len) memcpy(nx, _data, len * T.sizeof);
        _data = cast(T*)(nx);
    }
     
    void opOpAssign(string op : "~")(T item) {
        if (len == cap) {
            reserve(max(4, cap*2));
        }
        _data[len++] = item;
    }
     
    void clear() {
        len = 0;
    }
     
    T[] data() {
        return (_data) ? _data[0..len] : null;
    }
}

 
/* IMPORT /Users/yosupo/Program/dcomp/source/dcomp/scanner.d */
// module dcomp.scanner;

class Scanner {
    import std.stdio : File;
    import std.conv : to;
    import std.range : front, popFront, array, ElementType;
    import std.array : split;
    import std.traits : isSomeChar, isStaticArray, isArray; 
    import std.algorithm : map;
    File f;
    this(File f) {
        this.f = f;
    }
    char[512] lineBuf;
    char[] line;
    private bool succ() {
        import std.range.primitives : empty, front, popFront;
        import std.ascii : isWhite;
        while (true) {
            while (!line.empty && line.front.isWhite) {
                line.popFront;
            }
            if (!line.empty) break;
            if (f.eof) return false;
            line = lineBuf[];
            f.readln(line);
        }
        return true;
    }

    private bool readSingle(T)(ref T x) {
        import std.algorithm : findSplitBefore;
        import std.string : strip;
        import std.conv : parse;
        if (!succ()) return false;
        static if (isArray!T) {
            alias E = ElementType!T;
            static if (isSomeChar!E) {
                 
                 
                auto r = line.findSplitBefore(" ");
                x = r[0].strip.dup;
                line = r[1];
            } else {
                auto buf = line.split.map!(to!E).array;
                static if (isStaticArray!T) {
                     
                    assert(buf.length == T.length);
                }
                x = buf;
                line.length = 0;
            }
        } else {
            x = line.parse!T;
        }
        return true;
    }
    int read(T, Args...)(ref T x, auto ref Args args) {
        if (!readSingle(x)) return 0;
        static if (args.length == 0) {
            return 1;
        } else {
            return 1 + read(args);
        }
    }
}



 

 
/* IMPORT /Users/yosupo/Program/dcomp/source/dcomp/foundation.d */
// module dcomp.foundation;
 
static if (__VERSION__ <= 2070) {
    template fold(fun...) if (fun.length >= 1) {
        auto fold(R, S...)(R r, S seed) {
            import std.algorithm : reduce;
            static if (S.length < 2) {
                return reduce!fun(seed, r);
            } else {
                import std.typecons : tuple;
                return reduce!fun(tuple(seed), r);
            }
        }
    }
     
}
version (X86) static if (__VERSION__ < 2071) {
    int bsf(ulong v) {
        foreach (i; 0..64) {
            if (v & (1UL << i)) return i;
        }
        return -1;
    }
    int bsr(ulong v) {
        foreach_reverse (i; 0..64) {
            if (v & (1UL << i)) return i;
        }
        return -1;   
    }
    int popcnt(ulong v) {
        int c = 0;
        foreach (i; 0..64) {
            if (v & (1UL << i)) c++;
        }
        return c;
    }
}