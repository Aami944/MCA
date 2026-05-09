package Java;
import java.awt.Frame;
import java.awt.Graphics;

public class FaceApplet extends Frame {

    int total = 350;

    public FaceApplet() {
        setSize(400, 400);
        setVisible(true);
    }

    public void paint(Graphics g) {

        double percent = (total / 500.0) * 100;

        g.drawString("Percentage = " + percent, 50, 50);

        // face
        g.drawOval(100, 100, 150, 150);

        // eyes
        g.fillOval(140, 140, 15, 15);
        g.fillOval(190, 140, 15, 15);

        // mouth
        if (percent > 50) {
            g.drawArc(140, 170, 70, 40, 180, 180); // happy
        } else {
            g.drawArc(140, 200, 70, 40, 0, -180);   // sad
        }
    }

    public static void main(String[] args) {
        new FaceApplet();
    }
}