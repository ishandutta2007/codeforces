/**
 * You can edit, run, and share this code.
 * play.kotlinlang.org
 */
import java.util.Scanner 
 
val cin = Scanner(System.`in`); 
 
val N = 100010;
var a = IntArray(N);
 
fun sol()
{
    var n = cin.nextInt();
    var cnt = 0;
    for(i in 0 until n)
        a[i] = cin.nextInt();
    for(i in 0 until n)
    {
        if(a[i] < 0)
        {
            ++cnt;
            a[i] = -a[i];
        }
    }
    var flg = true;
    for(i in 0 until n)
    {
        if(i < cnt)
            a[i] = -a[i];
        if(i > 0 && a[i] < a[i - 1])
            flg = false;
    }
    if(flg)
        println("Yes");
    else
        println("No");
}

fun main() {
    var tt = cin.nextInt();
    for(i in 0 until tt)
        sol();
}