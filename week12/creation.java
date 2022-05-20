import java.math.BigInteger;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.StringTokenizer;

class BinomialCoefficient {

    static BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tokens = new StringTokenizer("");
    static PrintStream out = new PrintStream(new BufferedOutputStream(System.out), false);

    static boolean hasNext() throws IOException {
        while (!tokens.hasMoreTokens()) {
            String line = r.readLine();
            if (line == null)
                return false;
            tokens = new StringTokenizer(line);
        }
        return true;
    }

    static String next() throws IOException {
        hasNext();
        return tokens.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    // Returns value of Binomial Coefficient C(n, k)
    static String binomialCoeff(BigInteger n, BigInteger k) {
        BigInteger res = BigInteger.ONE;

        // Since C(n, k) = C(n, n-k)
        if (k.compareTo(n.subtract(k)) > 0)
            k = n.subtract(k);

        // Calculate value of
        // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
        for (BigInteger i = new BigInteger("0"); i.compareTo(k) < 0; i = i.add(BigInteger.ONE)) {
            res = res.multiply(n.subtract(i));
            res = res.divide(i.add(BigInteger.ONE));
        }

        return res.mod(new BigInteger("1000000007")).toString();
    }

    /* Driver program to test above function */
    public static void main(String[] args) {
        try {
            int cases = nextInt();
            for (int i = 0; i < cases; i++) {
                long low = nextInt();
                long upp = nextInt();
                long r = nextInt();

                if (r == 2) {
                    System.out.println("1");
                    continue;
                }

                long n = upp - low + 1;
                long k = r - 2;

                System.out.println(binomialCoeff(BigInteger.valueOf(n + k - 1), BigInteger.valueOf(k)));

            }
        } catch (IOException e) {
        }
    }

}