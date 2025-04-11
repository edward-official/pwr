package list4;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Dog pixel = new Dog("pixel", 4);
        pixel.makeSound();
        Cat nala = new Cat("nala", 4);
        nala.makeSound();

        System.out.println();
        Zoo zoo = new Zoo();
        zoo.visitAnimal(pixel);
        zoo.visitAnimal(nala);

        System.out.println();
        pixel.play();pixel.feed();pixel.groom();
        nala.play();nala.feed();nala.groom();

        System.out.println();
        Animal upcastedDog = new Dog("upcasted dog", 4);
        Dog downcastedDog = (Dog)upcastedDog;
        downcastedDog.bark();

        System.out.println();
        System.out.println(pixel.toString());
        Dog copiedPixel = new Dog("pixel", 4);
        System.out.println(pixel.equals(copiedPixel));
        System.out.println(pixel.hashCode()==copiedPixel.hashCode());

        System.out.println();
        System.out.println("total count: " + Animal.getIntstanceCount());
        pixel.getInfo();
        nala.getInfo();
        Bird book = new Bird("book", 4);
        book.getInfo();

        System.out.println();
        ArrayList<Animal> animalList = new ArrayList<Animal>();
        Animal tDog = new Dog("upcasted dog", 0); animalList.add(tDog);
        Animal tCat = new Cat("upcasted cat", 0); animalList.add(tCat);
        Animal tBird = new Bird("upcated bird", 0); animalList.add(tBird);
        for(Animal target : animalList) {target.makeSound();}

        System.out.println();
        pixel.eat();

        System.out.println();
        Animal.doAction(pixel);
        Animal.doAction(nala);
        Animal.doAction(book);
    }
}