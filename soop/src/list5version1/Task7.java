package list5version1;
import javax.swing.*;
import java.awt.*;

public class Task7 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Dropdown List");
        frame.setSize(800, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel = new JPanel();
        panel.setBackground(Color.red);

        String[] colors = {"Red", "Green", "Blue"};
        JComboBox<String> dropdown = new JComboBox<>(colors);
        dropdown.addActionListener(e -> {
            String selected = (String) dropdown.getSelectedItem();
            if (selected.equals("Red")) panel.setBackground(Color.RED);
            else if (selected.equals("Green")) panel.setBackground(Color.GREEN);
            else if (selected.equals("Blue")) panel.setBackground(Color.BLUE);
        });
        panel.add(dropdown);

        frame.add(panel);
        frame.setVisible(true);
    }
}