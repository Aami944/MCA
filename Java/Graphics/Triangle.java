package Java.Graphics;
public class Triangle {
    int b, h;
    public Triangle(int b, int h) {
        this.b = b;
        this.h = h;
    }
    public double area() {
        return 0.5 * b * h;
    }
}
