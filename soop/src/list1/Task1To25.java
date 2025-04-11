package list1;

public class Task1To25 {
    static void task1() {
        int data = 0;
        System.out.println("data: " + data);
    }
    static void task2() {
        double data = 5.5;
        System.out.println("data: " + data);
    }
    static void task3() {
        boolean isPolish = false;
        if(isPolish) System.out.println("polish");
        else System.out.println("not polish");
    }
    static void task4() {
        char grade = 'A';
        System.out.println("grade: " + grade);
    }
    static void task5() {
        int i1 = 15, i2 = 20;
        int result = i1 + i2;
        System.out.println("result: " + result);
    }
    static void task6() {
        double data1 = 10.5, data2 = 3.2;
        double result = data1 - data2;
        System.out.println("result: " + result);
    }
    static void task7() {
        int i1 = 7, i2 = 3, result;
        result = i1 % i2;
        System.out.println("result: " + result);
    }
    static void task8() {
        int scoreScience = 70, scoreMath = 50;
        boolean isScienceBetterThanMath = scoreScience > scoreMath;
        if(isScienceBetterThanMath) System.out.println("science score is better than math");
        else System.out.println("math score is better than science");
    }
    static void task9() {
        double ratingArsenal = 7.7, ratingDresden = 4.6;
        boolean isArsenalBetterThanDresden = ratingArsenal > ratingDresden;
        if(isArsenalBetterThanDresden) System.out.println("arsenal is better than dresden");
        else System.out.println("dresden is better than arsenal");
    }
    static void task10() {
        boolean isPlayer = true, isNumber7 = true;
        if(isPlayer && isNumber7) System.out.println("this player is bukayo saka");
        else System.out.println("cannot identify the player");
    }
    static void task11() {
        boolean isOver18 = true, isHealthy = true;
        if(isOver18 && isHealthy) System.out.println("you can drink");
        else System.out.println("you cannot drink");
    }
    static void task12() {
        int data = 7;
        if(data > 0) System.out.println("data is positive");
        else System.out.println("data is non-positive");
    }
    static void task13() {
        int data = 7;
        if(data%2 == 0) System.out.println("data is even");
        else System.out.println("data is odd");
    }
    static void task14() {
        int caseNumber = 10;
        switch (caseNumber) {
            case 10:
                System.out.println("case 10");
                break;
            case 15:
                System.out.println("case 15");
                break;
            default:
                System.out.println("case default");
        }
    }
    static void task15() {
        int loop = 10;
        for(int i=1; i<=loop; i++) System.out.println(i);
    }
    static void task16() {
        int counter = 10;
        while (counter >= 1) System.out.println(counter--);
    }
    static void task17() {
        int counter = 0;
        do {
            System.out.println("Hello, World!");
            counter++;
        } while (counter < 5);
    }
    static void task18To19() {
        int[] numbers = {1, 2, 3, 4, 5};
        for(int item: numbers) System.out.println(item);
    }
    static void task20To21() {
        String firstName = "bukayo", surname = "saka";
        String fullName = firstName + " " + surname;
        System.out.println(fullName);
    }
    static void task22() {
        String name = "bukayo";
        if(name.equals("bukayo")) System.out.println("equal");
        else System.out.println("not equal");
    }
    static void task23() {
        int result = 1, loop = 5;
        for(int i=2; i<=loop; i++) result *= i;
        System.out.println(result);
    }
    static void task24() {
        int[] array = {1, 2, 3, 4, 5};
        int max = array[0];
        for(int i=1; i<array.length; i++) {
            if(max < array[i]) max = array[i];
        }
        System.out.println(max);
    }
    static void task25() {
        String name = "bukayo", nameReversed = "";
        for(int i=0; i<name.length(); i++) nameReversed += name.charAt(name.length()-1-i);
        System.out.println(nameReversed);
    }
}