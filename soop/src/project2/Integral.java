package project2;
import java.util.Scanner;
import java.util.function.Function;

public class Integral {
    private double lowerLimit;
    private double upperLimit;
    private int precision;
    private MyFunction myFunction;
    Integral(MyFunction myFunction) {this.myFunction = myFunction;}
    void setUp(Scanner in) {
        System.out.print("enter the number of precision: ");
        precision = in.nextInt();
        if(precision<=0) {
            System.err.println("number of precision have to be positive integer");
            return;
        }
        System.out.print("enter the limit for example 1.0 2.0: ");
        lowerLimit = in.nextDouble();
        upperLimit = in.nextDouble();
    }
    double calculateMonteCarlo() {
        if (precision <= 0) throw new IllegalArgumentException("Number of precision must be positive.");
        double stepSize = (upperLimit - lowerLimit) / precision;
        double result = 0.0;
        for (int i = 0; i < precision; i++) {
            double x1 = lowerLimit + i * stepSize;
            double x2 = x1 + stepSize;
            result += 0.5 * (myFunction.getValue(x1) + myFunction.getValue(x2)) * stepSize;
        }
        return result;
    }
    double getLowerLimit() {return lowerLimit;}
    double getUpperLimit() {return upperLimit;}
    int getPrecision() {return precision;}
}
