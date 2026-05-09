package Java;
import java.awt.Frame;
import java.awt.Graphics;

public class ShapeApplet extends Frame {

    public ShapeApplet() {
        setSize(400, 400);
        setVisible(true);
    }

    public void paint(Graphics g) {
        g.drawOval(50, 50, 100, 100);
        g.drawRect(200, 50, 120, 80);
        g.drawLine(50, 200, 300, 200);
    }

    public static void main(String[] args) {
        new ShapeApplet();
    }
}
