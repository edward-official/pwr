package list5version1;
import javax.swing.*;

public class Task9 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("To-Do List");
        JPanel panel = new JPanel();
        frame.setSize(800, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JTextField taskField = new JTextField(15);
            panel.add(taskField);
        JButton addButton = new JButton("Add");
            panel.add(addButton);
        JButton removeButton = new JButton("Remove");
            panel.add(removeButton);

        DefaultListModel<String> model = new DefaultListModel<>();
        JList<String> list = new JList<>(model);

        addButton.addActionListener(e -> {
            String task = taskField.getText();
            if (!task.isEmpty()) model.addElement(task);
            taskField.setText("");
        });

        removeButton.addActionListener(e -> {
            int selectedIndex = list.getSelectedIndex();
            if (selectedIndex != -1) model.remove(selectedIndex);
        });

        frame.add(panel, "North");
        frame.add(new JScrollPane(list), "Center");
        frame.setVisible(true);
    }
}