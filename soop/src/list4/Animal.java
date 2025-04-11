package list4;
import java.util.*;

abstract class Animal {
    static int intstanceCount = 0;
    private String name;
    private int age;
    private int weight;
    private int height;
    private boolean isFoodLeft;
    Animal(String name, int age) {
        intstanceCount += 1;
        this.name = name;
        this.age = age;
        weight = -1;
        height = -1;
        isFoodLeft = false;
    }
//    [getter, setter]
    static int getIntstanceCount() {return intstanceCount;}
    void setWeight(int weight) {this.weight = weight;}
    void setHeight(int height) {this.height = height;}
    int getWeight() {return weight;}
    int getHeight() {return height;}

//    void makeSound() {System.out.println("making sound");}
    abstract void makeSound();
    public String toString() {return ("name: " + name + ", age: " + age);}
    public boolean equals(Object obj) {
        if (obj == null) return false;
        else if(name != ((Animal) obj).name || age != ((Animal) obj).age) return false;
        return true;
    }
    public int hashCode() {return Objects.hash(name, age);}
    void getInfo() {System.out.println("This is animal instance.");}
    void eat() {
        try {
            if (!isFoodLeft) throw new FoodNotAvailableException("no food left");
            System.out.println("eating...");
        } catch (FoodNotAvailableException exception) {
            System.out.println(exception.getMessage());
        }
    }
    static void doAction(Animal animal) {
        if(animal instanceof Dog) {((Dog) animal).bark();}
        else if(animal instanceof Cat) {((Cat) animal).meow();}
        else if(animal instanceof Bird) {((Bird) animal).fly();}
    }
}