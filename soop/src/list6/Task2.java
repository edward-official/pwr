package list6;
import java.util.Scanner;
import java.util.TreeMap;


class Library {
    private TreeMap<String, String> books;
    public Library() {
        books = new TreeMap<>();
    }

    public void addBook(String isbn, String title) {books.put(isbn, title);}
    public String searchBook(String isbn) {return books.getOrDefault(isbn, "Book not found");}
    public void displayAllBooks() {
        if (books.isEmpty()) {
            System.out.println("No books available.");
            return;
        }
        for (var entry : books.entrySet()) {
            System.out.println("ISBN: " + entry.getKey() + ", Title: " + entry.getValue());
        }
    }
}


public class Task2 {
    public static void main(String[] args) {
        Library library = new Library();
        Scanner scanner = new Scanner(System.in);

        System.out.println("Library System");
        System.out.println("1. Add a Book");
        System.out.println("2. Search for a Book by ISBN");
        System.out.println("3. Display All Books");
        System.out.println("4. Exit");
        int operation;

        do {
            System.out.print("\n\nselect operation: ");
            operation = scanner.nextInt();
            scanner.nextLine();

            switch (operation) {
                case 1:
                    System.out.print("Enter ISBN: ");
                    String isbn = scanner.nextLine();
                    System.out.print("Enter Book Title: ");
                    String title = scanner.nextLine();
                    library.addBook(isbn, title);
                    System.out.println("Book added successfully!");
                    break;
                case 2:
                    System.out.print("Enter ISBN to search: ");
                    String searchIsbn = scanner.nextLine();
                    System.out.println("Result: " + library.searchBook(searchIsbn));
                    break;
                case 3:
                    System.out.println("Books in Library:");
                    library.displayAllBooks();
                    break;
                case 4:
                    System.out.println("Exiting system...");
                    break;
                default:
                    System.out.println("Invalid choice. Try again.");
            }
        } while (operation != 4);

        scanner.close();
    }
}