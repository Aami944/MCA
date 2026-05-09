package Java;
import java.awt.*;
import java.awt.event.*;

public class HouseApplet extends Frame implements MouseListener {

    Color doorColor = Color.blue;

    public HouseApplet() {
        setSize(400, 400);
        setVisible(true);
        addMouseListener(this);
    }

    public void paint(Graphics g) {

        // house body
        g.drawRect(100, 100, 200, 150);

        // roof
        int x[] = {100, 200, 300};
        int y[] = {100, 30, 100};
        g.drawPolygon(x, y, 3);

        // door
        g.setColor(doorColor);
        g.fillRect(170, 170, 50, 80);
    }

    public void mouseClicked(MouseEvent e) {
        doorColor = Color.red;
        repaint();
    }

    public void mousePressed(MouseEvent e) {}
    public void mouseReleased(MouseEvent e) {}
    public void mouseEntered(MouseEvent e) {}
    public void mouseExited(MouseEvent e) {}

    public static void main(String[] args) {
        new HouseApplet();
    }
}