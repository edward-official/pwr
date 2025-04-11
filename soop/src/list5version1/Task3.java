package list5version1;
import javax.swing.*;

public class Task3 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Text Field Example");
        JPanel panel = new JPanel();
        frame.setSize(800, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JTextField textField = new JTextField(20);
            textField.addActionListener(e -> {

            });
            panel.add(textField);
        JButton button = new JButton("Print");
            button.addActionListener(e -> System.out.println(textField.getText()));
            panel.add(button);

        frame.add(panel);
        frame.setVisible(true);
    }
}