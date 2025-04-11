package list4;
class Vehicle {
    String owner;
    int number;
    Vehicle(String owner, int number) {
        this.owner = owner;
        this.number = number;
    }
}
class Car extends Vehicle {
    Car(String owner, int number) {super(owner, number);}
    void honk() {System.out.println("honk");}
}
class Truck extends Vehicle {
    Truck(String owner, int number) {super(owner, number);}
    void load() {System.out.println("load");}
}
public class Lee {
    public static void main(String[] args) {

    }
}