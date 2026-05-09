package Java;
import java.awt.*;
import java.awt.event.*;

public class Calculator extends Frame implements ActionListener {

    TextField t1, t2, result;
    Button add, sub, mul, div;

    Calculator() {
        setLayout(new FlowLayout());

        t1 = new TextField(10);
        t2 = new TextField(10);
        result = new TextField(10);

        add = new Button("+");
        sub = new Button("-");
        mul = new Button("*");
        div = new Button("/");

        add(t1);
        add(t2);
        add(add);
        add(sub);
        add(mul);
        add(div);
        add(result);

        add.addActionListener(this);
        sub.addActionListener(this);
        mul.addActionListener(this);
        div.addActionListener(this);

        setSize(300, 300);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {

        int a = Integer.parseInt(t1.getText());
        int b = Integer.parseInt(t2.getText());
        int res = 0;

        if (e.getSource() == add)
            res = a + b;
        if (e.getSource() == sub)
            res = a - b;
        if (e.getSource() == mul)
            res = a * b;
        if (e.getSource() == div)
            res = a / b;

        result.setText(String.valueOf(res));
    }

    public static void main(String[] args) {
        new Calculator();
    }
}
