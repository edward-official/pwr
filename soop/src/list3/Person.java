package list3;

public class Person {
    static final String DEFAULT_NAME = "default name";
    static final int DEFAULT_AGE = 0;
    static final int DEFAULT_HEIGHT = 0;
    static final int DEFAULT_WEIGHT = 0;
    static final int MAX_AGE = 200;

    private static int counter = 0; // task 11
    static int getCounter() {return counter;} // task 11

    private String name; // task 2, task 8
    private int age; // task 2, task 8
    private int height; // task 4
    private int weight; // task 4

    Person() {
        counter++;
        this.name = DEFAULT_NAME;
        this.age = DEFAULT_AGE;
        this.height = DEFAULT_HEIGHT;
        this.weight = DEFAULT_WEIGHT;
    } // task 10
    Person(String name, int age) {
        if(age > MAX_AGE) {
            System.out.println("🔥 error 🔥\nentered age exceeded possible range.\n");
            return;
        }
        counter++;
        this.name = name;
        this.age = age;
        this.height = DEFAULT_HEIGHT;
        this.weight = DEFAULT_WEIGHT;
    } // task 6, task 10, // task 13

    public void setName(String name) {this.name = name;}
    public void setAge(int age) {
        if(age > MAX_AGE) {
            System.out.println("🔥 error 🔥\nentered age exceeded possible range.\n");
            return;
        }
        this.age = age;
    } // task 13
    public void setHeight(int height) {this.height = height;}
    public void setWeight(int weight) {this.weight = weight;}

    public String getName() {return name;} // task 8
    public int getAge() {return age;} // task 8
    public int getHeight() {return height;} // task 8
    public int getWeight() {return weight;} // task 8
    
    public void printDetails() {
//        [ 14: criteria? ]
        System.out.println("[ detail ]");
        System.out.println("Name: " + name); // task 5
        System.out.println("Age: " + age); // task 5
        System.out.println("Height: " + height);
        System.out.println("Weight: " + weight + "\n");
    } // task 5, task 14
    public void printDetails(String name) {
//        [ 14: criteria? ]
        System.out.println("[ detail ]");
        System.out.println("Name: " + this.name + "\n");
    } // task 9

    public String getDescription() {
        return ("[ description ] " + "name: " + name + ", age: " + age + ", height: " + height + ", weight: " + weight);
    } // task 12
}
