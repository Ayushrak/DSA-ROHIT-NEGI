import javax.swing.*;

public class swing extends JFrame{
    JButton button;

    public swing(){
        button = new JButton("PROGRAMMING IN JAVA");
        add(button);
        setSize(300,200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public static void main(String[] args) {
        new swing();
    }
}