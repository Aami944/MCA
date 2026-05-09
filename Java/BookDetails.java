package Java;

import java.util.Scanner;

class Publisher {
    String publisher;

    void getPublisher() {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Publisher Name: ");
        publisher = sc.next();
    }
}

class Book extends Publisher {
    String title;
    double price;

    void getBook() {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Title: ");
        title = sc.next();

        System.out.print("Enter Price: ");
        price = sc.nextDouble();
    }
}
class Literature extends Book {

    void display() {
        System.out.println("\nLiterature Book");
        System.out.println("Title: " + title);
        System.out.println("Price: " + price);
        System.out.println("Publisher: " + publisher);
    }
}
class Fiction extends Book {
    void display() {
        System.out.println("\nFiction Book");
        System.out.println("Title: " + title);
        System.out.println("Price: " + price);
        System.out.println("Publisher: " + publisher);
    }
}
public class BookDetails {
    public static void main(String[] args) {
        Literature l = new Literature();
        l.getPublisher();
        l.getBook();
        l.display();
        Fiction f = new Fiction();
        f.getPublisher();
        f.getBook();
        f.display();
    }
}
