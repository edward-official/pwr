package list5version2;

import javax.swing.*;
import java.awt.*;

public class Task5 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Task 5");
        frame.setLayout(new FlowLayout());
        frame.setSize(800,600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);


        JLabel label = new JLabel("one");
        frame.add(label);

        String[] boxItems = {"one", "two", "three", "four"};
        JComboBox<String> comboBox = new JComboBox<>(boxItems);
        comboBox.addActionListener(e -> {
            label.setText((String)comboBox.getSelectedItem());
        });
        frame.add(comboBox);


        frame.setVisible(true);
    }
}
