package list7;

import java.io.*;
import java.util.*;

public class Task1 {
    public static void main(String[] args) {
//        String inputFile = "/Users/antinori/Desktop/Engineer/soop/src/list7/liczby.txt";
        String inputFile = "/Users/antinori/Desktop/Engineer/soop/src/list7/liczby_przyklad.txt";
        String outputFile = "/Users/antinori/Desktop/Engineer/soop/src/list7/wyniki3.txt";

        try {
            ArrayList<Integer> numbers = readNumbersFromFile(inputFile);
            task1(numbers, outputFile);
        } catch (IOException e) {
            System.err.println("Error: " + e.getMessage());
        }
    }

    private static ArrayList<Integer> readNumbersFromFile(String filename) throws IOException {
        ArrayList<Integer> newArray = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = br.readLine()) != null) {
                newArray.add(Integer.parseInt(line));
            }
        }
        return newArray;
    }

    private static void task1(ArrayList<Integer> numbers, String outputFile) throws IOException {
        ArrayList<Integer> perfectSquares = new ArrayList<>();

        for (int number : numbers) {
            int sqrt = (int) Math.sqrt(number);
            if (sqrt * sqrt == number) {
                perfectSquares.add(number);
            }
        }

        int nPerfectSquares = perfectSquares.size();
        int firstPerfectSquare = perfectSquares.isEmpty() ? -1 : perfectSquares.get(0);

        try (BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile))) {
            writer.write("Task 1\n");
            writer.write("Number of perfect squares: " + nPerfectSquares + "\n");
            if (firstPerfectSquare != -1) {
                writer.write("First perfect square: " + firstPerfectSquare + "\n");
            } else {
                writer.write("No perfect squares found.\n");
            }
            writer.write("\n");
        }
    }
}
