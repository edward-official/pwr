package list6;
import java.util.*;

public class Task8 {

    public static void main(String[] args) {
        ArrayList<Integer> numbers = new ArrayList<>(Arrays.asList(4, 1, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5));
        ArrayList<Integer> topThree = findTopThreeFrequentElements(numbers);
        System.out.println("Top three most frequent elements: " + topThree);
    }

    public static ArrayList<Integer> findTopThreeFrequentElements(List<Integer> numbers) {
        HashMap<Integer, Integer> frequencyMap = new HashMap<>();
        for (int num : numbers) {
            frequencyMap.put(num, frequencyMap.getOrDefault(num, 0) + 1);
        }

        PriorityQueue<Map.Entry<Integer, Integer>> minHeap = new PriorityQueue<>(
                Comparator.comparing(Map.Entry<Integer, Integer>::getValue)
                        .thenComparing(Map.Entry<Integer, Integer>::getKey)
        );

        for (Map.Entry<Integer, Integer> entry : frequencyMap.entrySet()) {
            minHeap.offer(entry);
            if (minHeap.size() > 3) {
                minHeap.poll();
            }
        }

        ArrayList<Integer> result = new ArrayList<>();
        while (!minHeap.isEmpty()) {
            result.add(minHeap.poll().getKey());
        }

        Collections.reverse(result);
        return result;
    }
}
