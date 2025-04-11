package list5version1;
import javax.swing.*;

public class Task2 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Button Action");
        frame.setSize(800, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JButton button = new JButton("Click Me!");
        button.addActionListener(e -> {
            System.out.println("[action listener]");
            System.out.println("Button clicked!");
        });
        frame.add(button);

        frame.setVisible(true);
    }
}