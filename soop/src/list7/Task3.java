package list7;
import java.io.*;
import java.util.*;

public class Task3 {

    public static void main(String[] args) {
//        String inputFilePath = "/Users/antinori/Desktop/Engineer/soop/src/list7/liczby.txt";
        String inputFilePath = "/Users/antinori/Desktop/Engineer/soop/src/list7/liczby_przyklad.txt";
        String outputFilePath = "/Users/antinori/Desktop/Engineer/soop/src/list7/wyniki3.txt";

        try {
            ArrayList<Integer> numbers = readNumbersFromFile(inputFilePath);
            Result result = analyze(numbers);
            writeResultsToFile(outputFilePath, result);
        } catch (IOException e) {
            System.err.println("An error occurred: " + e.getMessage());
        }
    }

    private static ArrayList<Integer> readNumbersFromFile(String filePath) throws IOException {
        ArrayList<Integer> numbers = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = br.readLine()) != null) {
                numbers.add(Integer.parseInt(line));
            }
        }
        return numbers;
    }

    private static Result analyze(ArrayList<Integer> numbers) {
        int countSmaller = 0;
        int countBigger = 0;
        int countEqual = 0;
        ArrayList<Integer> equalNumbers = new ArrayList<>();

        for (int number : numbers) {
            int difference = calculateDifference(number);

            if (difference < number) {
                countSmaller++;
            } else if (difference > number) {
                countBigger++;
            } else {
                countEqual++;
                equalNumbers.add(number);
            }
        }

        return new Result(countSmaller, countBigger, countEqual, equalNumbers);
    }

    private static int calculateDifference(int number) {
        char[] digits = String.valueOf(number).toCharArray();
        Arrays.sort(digits);

        String smallest = new String(digits);
        String largest = new StringBuilder(smallest).reverse().toString();

        int largestNum = Integer.parseInt(largest);
        int smallestNum = Integer.parseInt(smallest);

        return largestNum - smallestNum;
    }

    private static void writeResultsToFile(String filePath, Result result) throws IOException {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(filePath))) {
            bw.write("Task 3\n");
            bw.write("Less than the number: " + result.countSmaller + "\n");
            bw.write("Greater than the number: " + result.countBigger + "\n");
            bw.write("Equal to the number: " + result.countEqual + "\n");
            bw.write("Numbers equal to their difference: " + result.equalNumbers + "\n");
        }
    }

    private static class Result {
        int countSmaller;
        int countBigger;
        int countEqual;
        ArrayList<Integer> equalNumbers;

        Result(int countSmaller, int countBigger, int countEqual, ArrayList<Integer> equalNumbers) {
            this.countSmaller = countSmaller;
            this.countBigger = countBigger;
            this.countEqual = countEqual;
            this.equalNumbers = equalNumbers;
        }
    }
}
