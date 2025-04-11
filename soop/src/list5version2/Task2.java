package list5version2;
import javax.swing.*;

public class Task2 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Task2");
        JButton button = new JButton("press");
        frame.setSize(800, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        button.addActionListener(e -> {
            System.out.println("button clicked");
        });

        frame.add(button);
        frame.setVisible(true);
    }
}