package list5version1;
import javax.swing.*;

public class Task4 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Click Counter");
        frame.setSize(800, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel = new JPanel();
        JLabel label = new JLabel("Count: 0");
        panel.add(label);
        JButton button = new JButton("Click Me!");
        final int singleArrayLength = 1;
        int[] count = new int[singleArrayLength]; count[0]=0;
        button.addActionListener(e -> {
            System.out.println("[action listener]");
            label.setText("Count: " + (++count[0]));
        });
        panel.add(button);
        frame.add(panel);

        frame.setVisible(true);
    }
}