package list6;

import java.util.*;

public class Task5 {
    public static void main(String[] args) {
        List<String> strings = Arrays.asList("apple", "apricot", "banana", "blueberry", "cherry", "cranberry", "avocado");

        Map<Character, List<String>> groupedStrings = groupStringsByFirstCharacter(strings);

        groupedStrings.forEach((key, value) -> {
            System.out.println(key + ": " + value);
        });
    }

    public static Map<Character, List<String>> groupStringsByFirstCharacter(List<String> strings) {
        Map<Character, List<String>> groupedMap = new HashMap<>();

        for (String item : strings) {
            if (item == null || item.isEmpty()) continue;

            char firstChar = item.charAt(0);
            if(!groupedMap.containsKey(firstChar)) groupedMap.put(firstChar, new ArrayList<String>());
            groupedMap.get(firstChar).add(item);
        }

        return groupedMap;
    }
}
