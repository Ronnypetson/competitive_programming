import java.util.Scanner;
import java.math.BigInteger;

public class Main{
    public static char[] convert(int a){
        char[] ca = new char[2];
        ca[0] = (char)((int)'0'+a/10);
        ca[1] = (char)((int)'0'+a%10);
        return ca;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        BigInteger secs = BigInteger.valueOf(86400);
        BigInteger two = BigInteger.valueOf(2);
        BigInteger one = BigInteger.valueOf(1);
        BigInteger x = sc.nextBigInteger(), t;
        t = two.modPow(x,secs).subtract(one);
        int t_ = t.intValue(),h,m,s;
        h = t_/3600;
        m = (t_-h*3600)/60;
        s = t_-h*3600-m*60;
        char[] ch = convert(h);
        char[] cm = convert(m);
        char[] cs = convert(s);
        System.out.println(ch[0]+""+ch[1]+":"+cm[0]+""+cm[1]+":"+cs[0]+""+cs[1]);
    }
}

