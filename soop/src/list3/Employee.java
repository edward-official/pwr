package list3;

public class Employee {
    final String defaultDepartment = "default department";
    final int defaultAnnualSalary = 100000;

    private static int setID = 0;
    private static int nEmployee = 0;
    private static int totalAnnualSalary = 0;

    private int id;
    private String department;
    private int annualSalary;

    Employee() {
        id = ++setID;
        department = defaultDepartment;
        annualSalary = defaultAnnualSalary;

        nEmployee++;
        totalAnnualSalary += annualSalary;
    }
    Employee(String department) {
        id = ++setID;
        this.department = department;
        annualSalary = defaultAnnualSalary;

        nEmployee++;
        totalAnnualSalary += annualSalary;
    }
    Employee(int annualSalary) {
        id = ++setID;
        department = defaultDepartment;
        this.annualSalary = annualSalary;

        nEmployee++;
        totalAnnualSalary += annualSalary;
    }
    Employee(String department, int annualSalary) {
        id = ++setID;
        this.department = department;
        this.annualSalary = annualSalary;

        nEmployee++;
        totalAnnualSalary += annualSalary;
    }

//    [ method to annual salary ]
    static int getTotalAnnualSalary() {return totalAnnualSalary;}
    static int getAverageAnnualSalary() {return totalAnnualSalary / nEmployee;}
    int getMonthlySalary() {return annualSalary / 12;}

//    [ print employee details ]
    void checkDetails() {
        System.out.println("[ employee details ]");
        System.out.println("ID: " + id);
        System.out.println("department: " + department);
        System.out.println("annual salary: " + annualSalary);
    }

//    [ compare salaries ]
    boolean isSalaryHigherThan(Employee target) {
        return (annualSalary > target.annualSalary);
    }
    boolean isSalarySame(Employee target) {
        return (annualSalary == target.annualSalary);
    }
}