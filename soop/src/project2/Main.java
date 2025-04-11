/*
7.0 sinx 5.0 + 6.0 5.0 x complete
1000
1.0 2.0

1.0 x 2.0 + 2.0 x 1.0 + 1.0 1.0 1.0 complete
1000
1.0 2.0

*/
package project2;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        MyFunction myFunction = new MyFunction();
        myFunction.setUp(in);
        Integral integral = new Integral(myFunction);
        integral.setUp(in);
        System.out.println("\n[integral details]");
        System.out.println("number of precision: " + integral.getPrecision());
        System.out.println("lower limit: " + integral.getLowerLimit());
        System.out.println("upper limit: " + integral.getUpperLimit());
        System.out.println("result: " + integral.calculateMonteCarlo());
        in.close();
    }
}
