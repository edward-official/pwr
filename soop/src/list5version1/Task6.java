package list5version1;
import javax.swing.*;
import java.awt.*;

public class Task6 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Background Color");
        JPanel panel = new JPanel();
        frame.setSize(800, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JButton buttonRed = new JButton("Red");
            buttonRed.addActionListener(e -> panel.setBackground(Color.RED));
            panel.add(buttonRed);
        JButton buttonGreen = new JButton("Green");
            buttonGreen.addActionListener(e -> panel.setBackground(Color.GREEN));
            panel.add(buttonGreen);
        JButton buttonBlue = new JButton("Blue");
            buttonBlue.addActionListener(e -> panel.setBackground(Color.BLUE));
            panel.add(buttonBlue);

        frame.add(panel);
        frame.setVisible(true);
    }
}