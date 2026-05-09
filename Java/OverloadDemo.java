package Java;
class Area {
    double area(double r) {
        return 3.14 * r * r;
    }
    int area(int l, int b) {
        return l * b;
    }
    double area(double b, double h) {
        return 0.5 * b * h;
    }
}
public class OverloadDemo {
    public static void main(String[] args) {

        Area a = new Area();

        System.out.println("Circle Area: " + a.area(5.0));
        System.out.println("Rectangle Area: " + a.area(4, 6));
        System.out.println("Triangle Area: " + a.area(4.0, 8.0));
    }
}
