package Java;

import java.util.Scanner;
class Product {
    int pcode;
    String pname;
    double price;

    void getData(Scanner sc) {
        System.out.print("Enter Product Code: ");
        pcode = sc.nextInt();

        System.out.print("Enter Product Name: ");
        pname = sc.next();

        System.out.print("Enter Price: ");
        price = sc.nextDouble();
    }
    void display() {
        System.out.println(pcode + " " + pname + " " + price);
    }
}
public class ProductDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Product p1 = new Product();
        Product p2 = new Product();
        Product p3 = new Product();

        p1.getData(sc);
        p2.getData(sc);
        p3.getData(sc);
        Product lowest = p1;
        if (p2.price < lowest.price)
            lowest = p2;
        if (p3.price < lowest.price)
            lowest = p3;
        System.out.println("Product with lowest price:");
        lowest.display();
    }
}
