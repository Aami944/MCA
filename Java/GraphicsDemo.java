package Java;

import Java.Graphics.Circle;
import Java.Graphics.Rectangle;
import Java.Graphics.Square;
import Java.Graphics.Triangle;

public class GraphicsDemo {
    public static void main(String args[]) {
        Rectangle r = new Rectangle(4, 5);
        Triangle t = new Triangle(4, 6);
        Square s = new Square(5);
        Circle c = new Circle(3);
        System.out.println("Rectangle Area: " + r.area());
        System.out.println("Triangle Area: " + t.area());
        System.out.println("Square Area: " + s.area());
        System.out.println("Circle Area: " + c.area());
    }
}

