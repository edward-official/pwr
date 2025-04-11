package list4;

public class Cat extends Animal implements Playable {
    Cat(String name, int age) {super(name, age);}
    void meow() {System.out.println("meowing");}
    void makeSound() {System.out.println("meow");}
    public void play() {System.out.println("cat's play behavior");}
    public void feed() {System.out.println("feeding cat");}
    public void groom() {System.out.println("grooming cat");}
    void getInfo() {
        System.out.println("This is cat, " + this.toString());
    }
}