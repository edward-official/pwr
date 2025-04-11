package list5version2;

import javax.swing.*;
import java.awt.*;

public class Task6 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Task 6");
        frame.setLayout(new FlowLayout());
        frame.setSize(800, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);


        JTextField textField1 = new JTextField(10);
        JTextField textField2 = new JTextField(10);
        String[] comboItems = {"+", "-", "*", "/"};
        JComboBox<String> comboBox = new JComboBox<>(comboItems);
        JButton button = new JButton("calculate");
        JLabel label = new JLabel("result");

        button.addActionListener(e -> {
            try {
                int a = Integer.parseInt(textField1.getText()), b = Integer.parseInt(textField2.getText());
                if(((String)comboBox.getSelectedItem()).equals("+")) label.setText(Integer.toString(a+b));
                else if(((String)comboBox.getSelectedItem()).equals("-")) label.setText(Integer.toString(a-b));
                else if(((String)comboBox.getSelectedItem()).equals("*")) label.setText(Integer.toString(a*b));
                else if(((String)comboBox.getSelectedItem()).equals("/")) label.setText(Integer.toString(a/b));
            }
            catch (Exception exception) {
                label.setText("wrong input");
            }
        });

        frame.add(textField1);
        frame.add(textField2);
        frame.add(comboBox);
        frame.add(button);
        frame.add(label);


        frame.setVisible(true);
    }
}
