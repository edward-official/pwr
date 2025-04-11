package list5version2;

import javax.swing.*;
import java.awt.*;

public class Task7 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Task 7");
        frame.setLayout(new FlowLayout());
        frame.setSize(800, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);


        JLabel label = new JLabel("default label");
        JCheckBox checkBox = new JCheckBox("visible");
        checkBox.setSelected(true);
        checkBox.addActionListener(e -> {
            label.setVisible(checkBox.isSelected());
        });

        frame.add(label);
        frame.add(checkBox);


        frame.setVisible(true);
    }
}
