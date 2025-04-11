package list6;
import java.util.PriorityQueue;

class Task implements Comparable<Task> {
    private String description;
    private int priority;

    public Task(String description, int priority) {
        this.description = description;
        this.priority = priority;
    }

    public String getDescription() {return description;}

    @Override
    public int compareTo(Task other) {
        return Integer.compare(other.priority, this.priority);
    }
}

public class Task4 {
    public static void main(String[] args) {
        PriorityQueue<Task> taskQueue = new PriorityQueue<>();

        taskQueue.add(new Task("Complete report", 3));
        taskQueue.add(new Task("Respond to emails", 1));
        taskQueue.add(new Task("Prepare presentation", 2));

        while (!taskQueue.isEmpty()) System.out.println("Processing task: " + taskQueue.poll().getDescription());
    }
}
