package list5version2;
import javax.swing.*;

public class Task3 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Task3");
        frame.setSize(800, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel = new JPanel();
        JTextField textField = new JTextField(20);
            panel.add(textField);
        JLabel label = new JLabel("null");
            panel.add(label);

        textField.addActionListener(e -> {
            label.setText(textField.getText());
            textField.setText("");
        });

        frame.add(panel);
        frame.setVisible(true);
    }
}
