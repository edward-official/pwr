package list7;

import java.io.*;
import java.util.*;

public class Task2 {
    public static void main(String[] args) {
        String inputFilePath = "/Users/antinori/Desktop/Engineer/soop/src/list7/liczby_przyklad.txt";
//        String inputFilePath = "/Users/antinori/Desktop/Engineer/soop/src/list7/liczby.txt";
        String outputFilePath = "/Users/antinori/Desktop/Engineer/soop/src/list7/wyniki3.txt";

        try {
            List<Integer> numbers = readNumbersFromFile(inputFilePath);
            List<Integer> result = findNumbersWithFiveDistinctPrimeDivisors(numbers);
            writeResultsToFile(outputFilePath, result);
        } catch (IOException e) {
            System.err.println("An error occurred: " + e.getMessage());
        }
    }

    private static List<Integer> readNumbersFromFile(String filePath) throws IOException {
        List<Integer> numbers = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = br.readLine()) != null) {
                numbers.add(Integer.parseInt(line));
            }
        }
        return numbers;
    }

    private static List<Integer> findNumbersWithFiveDistinctPrimeDivisors(List<Integer> numbers) {
        List<Integer> result = new ArrayList<>();
        for (int number : numbers) {
            if (countDistinctPrimeDivisors(number) >= 5) {
                result.add(number);
            }
        }
        return result;
    }

    private static int countDistinctPrimeDivisors(int number) {
        HashSet<Integer> primeDivisors = new HashSet<>();
        for (int i = 2; i * i <= number; i++) {
            while (number % i == 0) {
                primeDivisors.add(i);
                number /= i;
            }
        }
        if (number > 1) {
            primeDivisors.add(number);
        }
        return primeDivisors.size();
    }

    private static void writeResultsToFile(String filePath, List<Integer> results) throws IOException {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(filePath))) {
            bw.write("Task 2\n");
            for (int number : results) {
                bw.write(number + "\n");
            }
        }
    }
}
