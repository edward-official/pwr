package list5version2;

import javax.swing.*;
import java.awt.*;

class Panel10 extends JPanel {

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);

        Graphics2D g2d = (Graphics2D) g;

//        g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

        g2d.fillRect(100, 200, 200, 200);
        g2d.fillOval(500, 200, 100, 200);
    }
}


public class Task10 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Custom JPanel Example");
        frame.setSize(800, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Panel10 panel = new Panel10();
        frame.add(panel);

        frame.setVisible(true);
    }
}
