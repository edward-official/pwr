package list5version1;
import javax.swing.*;

public class Task5 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Calculator");
        frame.setSize(800, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JTextField field1 = new JTextField(5);
        JTextField field2 = new JTextField(5);
        JButton button = new JButton("calculate");
        JLabel label = new JLabel("result: null");

        button.addActionListener(e -> {
            try {
                int sum = Integer.parseInt(field1.getText()) + Integer.parseInt(field2.getText());
                label.setText("result: " + sum);
            } catch (NumberFormatException ex) {
                label.setText("invalid operation");
            }
        });

        JPanel panel = new JPanel();
        panel.add(field1);
        panel.add(field2);
        panel.add(button);
        panel.add(label);

        frame.add(panel);
        frame.setVisible(true);
    }
}