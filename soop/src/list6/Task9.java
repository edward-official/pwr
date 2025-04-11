package list6;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

class Employee {
    private String name;
    private int age;
    private String department;

    public Employee(String name, int age, String department) {
        this.name = name;
        this.age = age;
        this.department = department;
    }

    @Override
    public String toString() {
        return "name: " + name + "\nage: " + age + "\ndepartment: " + department + "\n";
    }
}

public class Task9 {
    public static void main(String[] args) {
        String csvFile = "/Users/antinori/Desktop/Engineer/soop/src/list6/employee.csv";
        List<Employee> employees = parseCsvFile(csvFile);

        for (Employee employee : employees) {
            System.out.println(employee);
        }
    }

    private static ArrayList<Employee> parseCsvFile(String filePath) {
        ArrayList<Employee> toreturn = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] values = line.split(",");
                if (values.length == 3) {
                    String name = values[0];
                    int age = Integer.parseInt(values[1]);
                    String department = values[2];
                    toreturn.add(new Employee(name, age, department));
                }
            }
        } catch (IOException e) {
            System.err.println("Error reading the CSV file: " + e.getMessage());
        } catch (NumberFormatException e) {
            System.err.println("Error parsing age in the CSV file: " + e.getMessage());
        }
        return toreturn;
    }
}
