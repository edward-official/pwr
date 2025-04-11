package project2;

public class Term {
    private double coefficient;
    private String base, exponent;
    private static boolean isDouble(String expression) {
        if (expression == null || expression.isEmpty()) {return false;}
        try {
            Double.parseDouble(expression);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }
    Term(double coefficient, String base, String exponent) {
        this.coefficient = coefficient;
        this.base = base;
        this.exponent = exponent;
    }

    double getValue(double x) {
        double output = 1.0;
        if(base.equals("sinx")) {output *= Math.sin(x);}
        else if(base.equals(("cosx"))) {output *= Math.cos(x);}
        else if(base.equals("tanx")) {output *= Math.tan(x);}
        else if(base.equals("x")) {output *= x;}
        else if(isDouble(base)) {output *= Double.parseDouble(base);}
        else {System.err.println("wrong input, please try again");}

        if(exponent.equals("x")) {output = Math.pow(output, x);}
        else if(isDouble(exponent)) {output = Math.pow(output, Double.parseDouble(exponent));}
        else {System.err.println("wrong input, please try again");}

        output *= coefficient;
        return output;
    }
}
