package list6;

import java.util.HashMap;
import java.util.Map;

public class Task7 {
    public static void main(String[] args) {
        HashMap<String, Integer> map1 = new HashMap<>();
        map1.put("a", 10);
        map1.put("b", 20);
        map1.put("c", 30);

        HashMap<String, Integer> map2 = new HashMap<>();
        map2.put("b", 15);
        map2.put("c", 25);
        map2.put("d", 35);

        HashMap<String, Integer> mergedMap = mergeHashMaps(map1, map2);
        for (Map.Entry<String, Integer> entry : mergedMap.entrySet()) {
            System.out.println(entry.getKey() + " : " + entry.getValue());
        }
    }

    public static HashMap<String, Integer> mergeHashMaps(HashMap<String, Integer> map1, HashMap<String, Integer> map2) {
        HashMap<String, Integer> mergedMap = new HashMap<>(map1);

        for (Map.Entry<String, Integer> item2 : map2.entrySet()) {
            mergedMap.merge(item2.getKey(), item2.getValue(), (t, u) -> t + u);
        }

        return mergedMap;
    }
}
