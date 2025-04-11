package list6;
import java.util.HashSet;

public class Task3 {
    public static void main(String[] args) {
        int[] array = {1, 2, 3, 4, 5, 6, 2};
        if(isContainingDuplicates(array)) System.out.println("array has duplicates");
        else System.out.println("array doesn't have duplicates");
    }

    public static boolean isContainingDuplicates(int[] array) {
        HashSet<Integer> seen = new HashSet<>();
        for (int value : array) {
            if (!seen.add(value)) return true;
        }
        return false;
    }
}
