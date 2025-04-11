package list5version2;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;

public class Task9 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Task 9");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800, 600);

        String[] columns = {"ID", "Name", "Position"};
        String[][] datas = {
            {"1", "John Doe", "Software Engineer"},
            {"2", "Jane Smith", "Data Analyst"},
            {"3", "Michael Johnson", "Product Manager"},
            {"4", "Emily Davis", "UI/UX Designer"}
        };

        DefaultTableModel model = new DefaultTableModel(datas, columns);
        JTable table = new JTable(model);
        JScrollPane scrollPane = new JScrollPane(table);

        frame.add(scrollPane);
        frame.setVisible(true);
    }
}
