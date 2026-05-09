package Java;
interface Shape {
    void area();
    void perimeter();
}
class Circle implements Shape {
    double r;
    Circle(double r) {
        this.r = r;
    }
    public void area() {
        System.out.println("Area: " + 3.14 * r * r);
    }
    public void perimeter() {
        System.out.println("Perimeter: " + 2 * 3.14 * r);
    }
}
class Rectangle implements Shape {
    int l, b;

    Rectangle(int l, int b) {
        this.l = l;
        this.b = b;
    }
    public void area() {
        System.out.println("Area: " + l * b);
    }

    public void perimeter() {
        System.out.println("Perimeter: " + 2 * (l + b));
    }
}
public class ShapeDemo {
    public static void main(String[] args) {

        Circle c = new Circle(5);
        Rectangle r = new Rectangle(4, 6);

        c.area();
        c.perimeter();

        r.area();
        r.perimeter();
    }
}
