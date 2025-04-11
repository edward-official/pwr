package list5version2;

import javax.swing.*;
import java.awt.*;

public class Task4 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Task 4");
        frame.setSize(800, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new BorderLayout());

        frame.add(new JButton("center"), BorderLayout.CENTER);
        frame.add(new JButton("east"), BorderLayout.EAST);
        frame.add(new JButton("west"), BorderLayout.WEST);
        frame.add(new JButton("south"), BorderLayout.SOUTH);
        frame.add(new JButton("north"), BorderLayout.NORTH);

        frame.setVisible(true);
    }
}