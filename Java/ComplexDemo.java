package Java;
import java.util.Scanner;

class Complex {
    int real, imag;
    void read(Scanner sc) {
        System.out.print("Enter real part: ");
        real = sc.nextInt();
        System.out.print("Enter imaginary part: ");
        imag = sc.nextInt();
    }
    void add(Complex c1, Complex c2) {
        real = c1.real + c2.real;
        imag = c1.imag + c2.imag;
    }
    void display() {
        System.out.println(real + " + " + imag + "i");
    }
}
public class ComplexDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Complex c1 = new Complex();
        Complex c2 = new Complex();
        Complex result = new Complex();

        c1.read(sc);
        c2.read(sc);

        result.add(c1, c2);
        System.out.println("Sum:");
        result.display();
    }
}

