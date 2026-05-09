package Java;
import java.util.Scanner;

class Employee {
    int eNo;
    String eName;
    double eSalary;

    void read(Scanner sc) {
        System.out.print("Enter Employee Number: ");
        eNo = sc.nextInt();

        System.out.print("Enter Employee Name: ");
        eName = sc.next();

        System.out.print("Enter Salary: ");
        eSalary = sc.nextDouble();
    }

    void display() {
        System.out.println(eNo + " " + eName + " " + eSalary);
    }
}

public class EmployeeDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of employees: ");
        int n = sc.nextInt();

        Employee emp[] = new Employee[n];

        for (int i = 0; i < n; i++) {
            emp[i] = new Employee();
            emp[i].read(sc);
        }

        System.out.print("Enter employee number to search: ");
        int search = sc.nextInt();
        boolean found = false;

        for (int i = 0; i < n; i++) {
            if (emp[i].eNo == search) {
                emp[i].display();
                found = true;
            }
        }

        if (!found)
            System.out.println("Employee not found");
    }
}
