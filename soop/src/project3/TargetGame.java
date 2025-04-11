package project3;
import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.Random;

public class TargetGame extends JPanel {
    private static final int TARGET_RADIUS = 200;
    private static final int NUM_CIRCLES = 10;
    private static final int PANEL_WIDTH = 800;
    private static final int PANEL_HEIGHT = 600;
    private int centerX = PANEL_WIDTH / 2;
    private int centerY = PANEL_HEIGHT / 2;
    private int score = 0;
    private Color[] colors;

    private Color[] generateColors() {
        Color[] colorArray = new Color[NUM_CIRCLES];
        Random random = new Random();
        for (int i = 0; i < NUM_CIRCLES; i++) colorArray[i] = new Color(random.nextInt(256), random.nextInt(256), random.nextInt(256));
        return colorArray;
    }
    public TargetGame() {
        setPreferredSize(new Dimension(PANEL_WIDTH, PANEL_HEIGHT));
        colors = generateColors();
        addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                int dx = e.getX() - centerX;
                int dy = e.getY() - centerY;
                double distance = Math.sqrt(dx * dx + dy * dy);

                if (distance <= TARGET_RADIUS) {
                    score += NUM_CIRCLES - (int)(distance/(TARGET_RADIUS/NUM_CIRCLES));
                    System.out.println("Hit! Score: " + score);
                } else {
                    System.out.println("Miss! Score: " + score);
                }
            }
        });

        Timer timer = new Timer(2000, e -> moveTarget());
        timer.start();
    }
    private void moveTarget() {
        Random random = new Random();
        centerX = random.nextInt(PANEL_WIDTH - TARGET_RADIUS * 2) + TARGET_RADIUS;
        centerY = random.nextInt(PANEL_HEIGHT - TARGET_RADIUS * 2) + TARGET_RADIUS;
        repaint();
    }
    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        for (int i = 0; i < NUM_CIRCLES; i++) {
            int radius = TARGET_RADIUS - (i * TARGET_RADIUS/NUM_CIRCLES);
            g.setColor(colors[i]);
            g.fillOval(centerX - radius, centerY - radius, radius * 2, radius * 2);
        }
        g.setColor(Color.BLACK);
        g.drawString("Score: " + score, 20, 20);
    }
}
