package list3;

public class Main {
    static void task1() {
        System.out.println("Encapsulation refers to bundling data along with the methods that operate on that data into a single unit (e.g., a class) and restricting direct access to some of an object's components to maintain data integrity.");
        System.out.println("Abstraction involves exposing only the essential features of an object while hiding unnecessary details, simplifying complex systems and making programs easier to understand and modify.");
        System.out.println("Inheritance allows a class (child class or derived class) to inherit the properties and behaviors of another class (parent class or base class), enhancing code reusability and reducing redundancy.");
        System.out.println("Finally, polymorphism enables objects of different classes to be treated as instances of a common base class.");
    }
    /*
    static void main0() {
//        [method overloading]
        person4.printDetails("name");
        person4.printDetails();

//        [static member]
        System.out.println("[ number of person instance created ]\n" + Person.getCounter() + "\n");

//        [return string]
        System.out.println(person4.getDescription() + "\n");

//        [using constant for input validation]
        person4.setAge(201);

//        + Employee +
        Employee employee1 = new Employee("human resource", 150000);
        Employee employee2 = new Employee("software development", 200000);

        System.out.println(Employee.getTotalAnnualSalary());
        System.out.println(Employee.getAverageAnnualSalary());
        System.out.println(employee1.getMonthlySalary());

        employee1.checkDetails();
        employee2.checkDetails();

        System.out.println(employee1.isSalaryHigherThan(employee2));
        System.out.println(employee1.isSalarySame(employee2));
        System.out.println(employee2.isSalaryHigherThan(employee1));

    }
    */
    static void main1() {
        Person person1 = new Person("person 1", 24); // task 3
        Person person2 = new Person("person 2", 22); // task 3

        person1.setHeight(175); // task 4
        person1.setWeight(70); // task 4
        person2.setHeight(165); // task 4
        person2.setWeight(50); // task 4

        person1.printDetails(); // task 5
        person2.printDetails(); // task 5

        System.out.println("count: " + Person.getCounter() + "\n"); // task 11

        System.out.println(person1.getDescription()); // task 12
        System.out.println(person2.getDescription()); // task 12
    }
    static void main2() {
        Person person = new Person();
        person.printDetails();
    } // task 7: null, 0

    public static void main(String[] args) {
        main1();
    }
}
