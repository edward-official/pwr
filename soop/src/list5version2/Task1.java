package list5version2;
import javax.swing.*;

public class Task1 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Task1");
        JLabel label = new JLabel("Hello, Swing!");
        frame.setSize(800, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        frame.add(label);
        frame.setVisible(true);
    }
}