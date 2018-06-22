import java.math.*;
import java.util.Scanner;

public class BigintCF305B
{
    public static void main(String args[]) throws Exception
    {
            Scanner sc = new Scanner(System.in);
            BigInteger p = sc.nextBigInteger();
            BigInteger q = sc.nextBigInteger();
            Integer n = sc.nextInt();
            BigInteger a[] = new BigInteger[n];
            for(int i = 0; i < n; i++)
            a[i] = sc.nextBigInteger();
         BigInteger g=p.gcd(q),num,deno,tmp;
        p=p.divide(g);q=q.divide(g);
        num=new BigInteger("1");
        deno=a[n-1];
        for (int i=n-2;i>=0 ;--i ) 
        {
            tmp=deno;
            g=num.gcd(deno);
            deno=(deno.multiply(a[i]));
            deno= (deno.add(num));
            num=tmp;
            g=num.gcd(deno);
            num=num.divide(g);deno=deno.divide(g);
        }
        if(num.compareTo(q)==0 && deno.compareTo(p)==0)
        System.out.println("YES");
        else 
        System.out.println("NO");

    }
}