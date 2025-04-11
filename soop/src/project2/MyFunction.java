package project2;
import java.util.ArrayList;
import java.util.Scanner;

public class MyFunction {
    private ArrayList<Term> terms;
    private ArrayList<String> operators;
    MyFunction() {
        this.terms = new ArrayList<Term>();
        this.operators = new ArrayList<String>();
    }

    boolean isValidFucntion() {
        if(terms.size()-1 == operators.size()) return true;
        else return false;
    }
    void setUp(Scanner in) {
        System.out.println("required form..");
        System.out.println("term operator term operator term..");
        System.out.println("single term is always defined by the following 3 elements: coefficient, base, exponent");
        System.out.println("coefficient must be double type");
        System.out.println("base can be either one of these: sinx, cosx, tanx, x, double");
        System.out.println("exponent should be double or x");
        System.out.println("operator must be one of them: +, -");
        System.out.println("for example..");
        System.out.println("7.0 sinx 5.0 / 6.0 5.0 x");
        System.out.print("enter the single-variable(x) function in the given form (enter complete to terminate): ");

        for(int i=0; ;i++) {
            if(i%2==0) {
                double coefficient = in.nextDouble();
                String base = in.next(), exponent = in.next();
                terms.add(new Term(coefficient, base, exponent));
                System.out.println("debug: term added");
            }
            else {
                String token = in.next();
                if(token.equals("complete")) break;
                operators.add(token);
                System.out.println("debug: operator added");
            }
        }
    }
    double getValue(double x) {
        double output = terms.get(0).getValue(x);
        int loop = operators.size();
        for(int i=0; i<loop; i++) {
            if(operators.get(i).equals("+")) {output += terms.get(i+1).getValue(x);}
            else if(operators.get(i).equals("-")) {output -= terms.get(i+1).getValue(x);}
        }
        return output;
    }
}
