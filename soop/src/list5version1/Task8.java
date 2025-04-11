package list5version1;
import javax.swing.*;
import java.awt.event.*;

public class Task8 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Login");
        JPanel panel = new JPanel();
        frame.setSize(800, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        panel.add(new JLabel("Username:"));
            JTextField username = new JTextField(10);
            panel.add(username);
        panel.add(new JLabel("Password:"));
            JPasswordField password = new JPasswordField(10);
            panel.add(password);
        JButton loginButton = new JButton("Login");
            panel.add(loginButton);
        JLabel message = new JLabel();
            panel.add(message);

        loginButton.addActionListener(e -> {
            String id = username.getText();
            String pw = new String(password.getPassword());
            if (id.equals("admin") && pw.equals("1234")) {
                message.setText("Login Successful!");
            } else {
                message.setText("Login Failed!");
            }
        });

        frame.add(panel);
        frame.setVisible(true);
    }
}