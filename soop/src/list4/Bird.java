package list4;

final class Bird extends Animal {
    Bird(String name, int age) {
        super(name, age);
    }
    void makeSound() {System.out.println("chirp");}
    final void fly() {System.out.println("flying");}
    void getInfo() {
        System.out.println("This is bird, " + this.toString());
    }
}