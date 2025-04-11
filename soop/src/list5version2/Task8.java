package list5version2;

import javax.swing.*;

public class Task8 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Task 8");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800, 600);

        JMenuBar menuBar = new JMenuBar();
        JMenu fileMenu = new JMenu("File");

        JMenuItem openItem = new JMenuItem("Open");
        JMenuItem saveItem = new JMenuItem("Save");
        JMenuItem exitItem = new JMenuItem("Exit");

        openItem.addActionListener(e -> {
            System.out.println("Open selected");
        });

        saveItem.addActionListener(e -> {
            System.out.println("Save selected");
        });

        exitItem.addActionListener(e -> {
            System.out.println("Exit selected");
        });

        fileMenu.add(openItem);
        fileMenu.add(saveItem);
        fileMenu.add(exitItem);

        menuBar.add(fileMenu);
        frame.setJMenuBar(menuBar);
        frame.setVisible(true);
    }
}
