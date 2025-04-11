package list4;

public class Dog extends Animal implements Playable, Pet {
    Dog(String name, int age) {
        super(name, age);
        setWeight(0);
        setHeight(0);
//        weight = 0;
//        height = 0;
    }
    Dog(String name, int age, int weight, int height) {
        this(name, age);
        setWeight(weight);
        setHeight(height);
    }
    void bark() {System.out.println("barking");}
    void makeSound() {System.out.println("woof");}
    public void play() {System.out.println("dog's play behavior");}
    public void feed() {System.out.println("feeding dog");}
    public void groom() {System.out.println("grooming dog");}
    void getInfo() {
        System.out.println("This is dog, " + this.toString());
    }
}