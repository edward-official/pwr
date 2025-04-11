package list2;
import java.io.*;
import java.util.*;

public class Main {
    static int task1(int a, int b) {
        // 1. Sum Two Numbers
        // Write a program that takes two integers as input and prints their sum.
        // https://www.w3schools.com/java/java_operators.asp

        System.out.println(a+b);
        return a+b;
    }
    static boolean task2(int a) {
        // 2. Check Even or Odd
        // Write a program that checks whether a number is even or odd.
        // https://www.geeksforgeeks.org/operators-in-java/

        if(a % 2 == 0) {
            System.out.println("even number");
            return true;
        }
        else {
            System.out.println("odd number");
            return false;
        }
    }
    static int task3(BufferedReader in) throws IOException {
        // 3. Find Maximum of Three Numbers
        // Write a program to find the largest of three numbers entered by the user.
        // https://www.w3schools.com/java/ref_math_max.asp

        System.out.print("Enter 3 integers with space deliminator: ");
        StringTokenizer stringTokenizer = new StringTokenizer(in.readLine(), " ");
        int[] numbers = {Integer.parseInt(stringTokenizer.nextToken()), Integer.parseInt(stringTokenizer.nextToken()), Integer.parseInt(stringTokenizer.nextToken())};
        int result = numbers[0];
        for(int i=1; i<numbers.length; i++) {
            if(result < numbers[i]) result = numbers[i];
        }
        System.out.println(result);
        return result;
    }
    static int task4(BufferedReader in) throws IOException {
        // 4. Simple Calculator
        // Write a program that performs basic arithmetic operations (addition, subtraction, multiplication, division) based on user input.
        // https://www.geeksforgeeks.org/switch-statement-in-java/

        System.out.print("Enter the operation you want to execute (addition-1, subtraction-2, multiplication-3, division-4): ");
        StringTokenizer stringTokenizer = new StringTokenizer(in.readLine(), " ");
        int iOperation = Integer.parseInt(stringTokenizer.nextToken());

        System.out.print("Enter two integers you want to input with space deliminator: ");
        stringTokenizer = new StringTokenizer(in.readLine(), " ");
        int a = Integer.parseInt(stringTokenizer.nextToken()), b = Integer.parseInt(stringTokenizer.nextToken());

        if(iOperation==1) {
            System.out.println(a+b);
            return a+b;
        }
        else if(iOperation==2) {
            System.out.println(a-b);
            return a-b;
        }
        else if(iOperation==3) {
            System.out.println(a*b);
            return a*b;
        }
        else if(iOperation==4) {
            if(b==0) {
                System.out.println("cannot divide by zero");
                return -1;
            }
            System.out.println(a/b);
            return a/b;
        }
        else {
            System.out.println("wrong operator");
            return 0;
        }
    }
    static int task5(int n) {
        // 5. Factorial Calculation
        // Write a program to calculate the factorial of a number.
        // https://www.javatpoint.com/java-for-loop

        if(n<=0) {
            System.out.println("input integer should be greater than zero");
            return -1;
        }
        int result = 1;
        for(int i=2; i<=n; i++) {
            result *= i;
        }
        System.out.println(result);
        return result;
    }
    static boolean task6(int n) {
        // 6. Prime Number Checker
        // Write a program that checks if a number is prime or not.
        // https://www.programiz.com/java-programming/examples/prime-number

        if(n<=1) {
            System.out.println("Enter integer greater than 1");
            return false;
        }
        else if(n==2 || n==3) {
            System.out.println("prime number");
            return true;
        }
        for(int i=2; i<=n/2; i++) {
            if(n%i==0) {
                System.out.println("not prime number");
                return false;
            }
        }
        System.out.println("prime number");
        return true;
    }
    static int task7(int n) {
        // 7. Fibonacci Sequence
        // Write a program that generates the first n Fibonacci numbers.
        // https://www.w3schools.com/java/java_for_loop.asp

        if(n<=0) {
            System.out.println("Enter positive integer");
            return -1;
        }
        else if(n==1 || n==2) {
            System.out.println(1);
            return 1;
        }
        int left = 1, right = 1;
        for(int i=3; i<=n; i++) {
            int t = left + right;
            left = right;
            right = t;
        }
        System.out.println(right);
        return right;
    }
    static int task8(int[] array) {
        // 8. Sum of Array Elements
        // Write a program that takes an array of integers and prints the sum of all elements.
        // www.javatpoint.com/java-array

        int result = 0;
        for(int i=0; i<array.length; i++) {
            result+=array[i];
        }
        System.out.println(result);
        return result;
    }
    static String task9(String s) {
        // 9. Reverse a String
        // Write a program that takes a string as input and prints the reversed string.
        // https://www.geeksforgeeks.org/reverse-a-string-in-java/

        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(s).reverse();
        System.out.println(stringBuilder.toString());
        return stringBuilder.toString();
    }
    static int task10(int[] array) {
        // 10. Find Largest Element in Array
        // Write a program to find the largest element in an array of integers.
        // https://www.programiz.com/java-programming/examples/largest-element-array

        int result = array[0];
        for(int i=1; i<array.length; i++) {
            if(result < array[i]) result = array[i];
        }
        System.out.println(result);
        return result;
    }
    static boolean task11(String s) {
        // 11. Palindrome Checker
        // Write a program to check if a given string is a palindrome.
        // https://www.geeksforgeeks.org/java-program-to-check-whether-a-string-is-a-palindrome/

        for(int i=0; i<s.length()/2; i++) {
            if(s.charAt(i) != s.charAt(s.length()-1-i)) {
                System.out.println("not palindrome");
                return false;
            }
        }
        System.out.println("palindrome");
        return true;
    }
    static int task12(int n) {
        // 12. Sum of Digits
        // Write a program to calculate the sum of digits of a given number.
        // https://www.programiz.com/java-programming/examples/sum-digit

        if(n<=0) {
            System.out.println("Enter a positive integer");
            return -1;
        }
        int result = 0;
        while(n!=0) {
            result += n % 10;
            n /= 10;
        }
        System.out.println(result);
        return result;
    }
    static void task13(String s) {
        // 13. Count Vowels and Consonants
        // Write a program to count the number of vowels and consonants in a given string.
        // https://www.javatpoint.com/count-vowels-in-java

        int iConsonant = 0, iVowel = 0;
        for(int i=0; i<s.length(); i++) {
            if(s.charAt(i)=='a' || s.charAt(i)=='e' || s.charAt(i)=='i' || s.charAt(i)=='o' || s.charAt(i)=='u') iVowel++;
            else if(s.charAt(i)=='q'
                    || s.charAt(i)=='w'
                    || s.charAt(i)=='r'
                    || s.charAt(i)=='t'
                    || s.charAt(i)=='y'
                    || s.charAt(i)=='p'
                    || s.charAt(i)=='s'
                    || s.charAt(i)=='d'
                    || s.charAt(i)=='f'
                    || s.charAt(i)=='g'
                    || s.charAt(i)=='h'
                    || s.charAt(i)=='j'
                    || s.charAt(i)=='k'
                    || s.charAt(i)=='l'
                    || s.charAt(i)=='z'
                    || s.charAt(i)=='x'
                    || s.charAt(i)=='c'
                    || s.charAt(i)=='v'
                    || s.charAt(i)=='b'
                    || s.charAt(i)=='n'
                    || s.charAt(i)=='m') iConsonant++;
        }
        System.out.println("consonant: " + iConsonant);
        System.out.println("vowel: " + iVowel);
    }
    static boolean task14(int n) {
        // 14. Check Armstrong Number
        // Write a program to check if a given number is an Armstrong number.
        // https://www.geeksforgeeks.org/java-program-to-check-armstrong-number/

        final int nFinal = n;
        int digitNumber = 0;
        while(n!=0) {
            digitNumber+=1;
            n/=10;
        }
        if(nFinal<0 && digitNumber%2==0) {
            System.out.println("not armstrong number");
            return false;
        }

        int armstrong = 0;
        for(int i=0; i<digitNumber; i++) {
            armstrong += (int)Math.pow((nFinal / (int)Math.pow(10, i) % 10), digitNumber);
        }
        if(nFinal == armstrong) {
            System.out.println("armstrong number");
            return true;
        }
        System.out.println("not armstrong number");
        return false;
    }
    static void task15(int[] array) {
        // 15. Sort an Array
        // Write a program that sorts an array of integers in ascending order.
        // https://www.w3schools.com/java/java_arrays.asp

        for(int i=0; i<array.length-1; i++) {
            for(int j=i+1; j<array.length; j++) {
                if(array[i]>array[j]) {
                    int t = array[i];
                    array[i] = array[j];
                    array[j] = t;
                }
            }
        }
        for(int item: array) System.out.println(item);
    }
    static void task16(BufferedReader in) throws IOException {
        // 16. Number Guessing Game
        // Write a program that generates a random number and asks the user to guess it, giving feedback on whether the guess is too high or too low.
        // https://www.geeksforgeeks.org/java-math-random-method-examples/

        int answer = (int)(Math.random()*10);

        while(true) {
            System.out.print("\nguess number between 0 and 10: ");
            StringTokenizer stringTokenizer = new StringTokenizer(in.readLine(), " ");
            int input = Integer.parseInt(stringTokenizer.nextToken());

            if(answer==input) {
                System.out.println("right answer");
                break;
            }
            else if(answer>input) System.out.println("input is smaller than the answer");
            else System.out.println("input is bigger than the answer");
        }
    }
    static void task17(int n) {
        // 17. Print Multiplication Table
        // Write a program that prints the multiplication table of a given number.
        // https://www.javatpoint.com/java-program-to-display-multiplication-table

        for(int i=0; i<10; i++) {
            System.out.println(n + " * " + i + " = " + n*i);
        }
    }
    static void task18() {
        // 18. Swap Two Numbers
        // Write a program to swap two numbers without using a temporary variable.
        // https://www.programiz.com/java-programming/examples/swapping

        int a = 7, b = 4;
        System.out.println("before: " + a + ", " + b);
        a = a + b;
        b = a - b;
        a = a - b;
        System.out.println("after: " + a + ", " + b);
    }
    static int task19(int a, int b) {
        // 19. Find GCD of Two Numbers
        // Write a program to calculate the greatest common divisor (GCD) of two numbers.
        // https://www.geeksforgeeks.org/java-program-to-find-gcd-of-two-numbers/

        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }

        System.out.println(a);
        return a;
    }
    static void task20(boolean isCelsius, double temperature) {
        // 20.Temperature Conversion
        // Write a program to convert temperature from Celsius to Fahrenheit and vice versa.
        // https://www.w3schools.com/java/java_variables.asp

        if(isCelsius) {
            System.out.println("celsius: " + temperature);
            System.out.println("fahrenheit: " + (temperature * 9 / 5 + 32));
        }
        else {
            System.out.println("celsius: " + (temperature-32) * 5 / 9);
            System.out.println("fahrenheit: " + temperature);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
//        int[] array = {5, 1, 9, 7};
        task20(false, 77);
        in.close();
    }
}