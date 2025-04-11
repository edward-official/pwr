package list5version1;
import javax.swing.*;
import java.awt.*;

public class Task10 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Timer");
        JPanel panel = new JPanel();
        frame.setSize(800, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JLabel label = new JLabel("Time: 0s");
            panel.add(label);
        JButton button = new JButton("Start/Stop");
            panel.add(button);

        Timer timer;
        final boolean[] running = {false};
        final int[] time = {0};
        timer = new Timer(1000, e -> label.setText("Time: " + (++time[0]) + "s"));

        button.addActionListener(e -> {
            if (running[0]) {
                timer.stop();
                panel.setBackground(Color.white);
            }
            else {
                timer.start();
                panel.setBackground(Color.lightGray);
            }
            running[0] = !running[0];
        });

        frame.add(panel);
        frame.setVisible(true);
    }
}