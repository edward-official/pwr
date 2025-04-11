package list6;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;

public class Task1 {
    public static void main(String[] args) {
        String filePath = "src/list6/text1.txt";
        HashMap<String, Integer> countMap = new HashMap<>();

        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] words = line.split("\\W+");
                for (String word : words) {
                    if (!word.isEmpty()) {
                        word = word.toLowerCase();
                        countMap.put(word, countMap.getOrDefault(word, 0) + 1);
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        for (String word : countMap.keySet()) {
            System.out.println(word + ": " + countMap.get(word));
        }
    }
}
