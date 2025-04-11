package project5;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

class TextFileAnalyzer {
    public static Map<Character, Double> parametrizationOfTextFile(String fileName) {
        StringBuilder data = new StringBuilder();
        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = br.readLine()) != null) data.append(line.toLowerCase());
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Initialize alphabet frequency map
        int totalLetters = 0;
        Map<Character, Double> frequencyMap = new HashMap<>();
        for (char c = 'a'; c <= 'z'; c++) frequencyMap.put(c, 0.0);
        for (char c : data.toString().toCharArray()) {
            if (Character.isLetter(c) && c >= 'a' && c <= 'z') {
                frequencyMap.put(c, frequencyMap.get(c) + 1);
                totalLetters++;
            }
        }
        if (totalLetters > 0) for (char c = 'a'; c <= 'z'; c++) frequencyMap.put(c, frequencyMap.get(c) / totalLetters);

        return frequencyMap;
    }

    public static double distance(Map<Character, Double> known, Map<Character, Double> unknown) {
        double result = 0.0;
        for (char c = 'a'; c <= 'z'; c++) result += Math.pow(known.getOrDefault(c, 0.0) - unknown.getOrDefault(c, 0.0), 2);
        return Math.sqrt(result);
    }
}

public class Main {
    public static void main(String[] args) {
        Map<Character, Double> textPL = TextFileAnalyzer.parametrizationOfTextFile("/Users/antinori/Desktop/Engineer/soop/src/project5/EN.txt");
        Map<Character, Double> textEN = TextFileAnalyzer.parametrizationOfTextFile("/Users/antinori/Desktop/Engineer/soop/src/project5/EN.txt");
        Map<Character, Double> textES = TextFileAnalyzer.parametrizationOfTextFile("/Users/antinori/Desktop/Engineer/soop/src/project5/ES.txt");
        Map<Character, Double> UNKNOWN = TextFileAnalyzer.parametrizationOfTextFile("/Users/antinori/Desktop/Engineer/soop/src/project5/unknown.txt");

        double distancePL = TextFileAnalyzer.distance(textPL, UNKNOWN);
        double distanceEN = TextFileAnalyzer.distance(textEN, UNKNOWN);
        double distanceES = TextFileAnalyzer.distance(textES, UNKNOWN);

        System.out.println("Distance to Polish: " + distancePL);
        System.out.println("Distance to English: " + distanceEN);
        System.out.println("Distance to Spanish: " + distanceES);

        // Determine the closest language
        if (distancePL < distanceEN && distancePL < distanceES) System.out.println("The text is most likely in Polish.");
        else if (distanceEN < distancePL && distanceEN < distanceES) System.out.println("The text is most likely in English.");
        else System.out.println("The text is most likely in Spanish.");
    }
}
