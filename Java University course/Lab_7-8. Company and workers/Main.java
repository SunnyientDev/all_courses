package com.company;
import java.util.*;

public class Main {
    public static void main(String[] args){
        //let's make a company
        Company OurCompany = new Company("MIREA", 100000000);
        List<Employee> Workers = new ArrayList<>();

        //hire 180 operators with name is equal to their number, fixSalary may be [1000; 50 000)
        for(int i = 0; i < 180; i++){
            OurCompany.hire(new Employee(
                            "Operator",
                            Integer.toString(i + 1),
                            (int)(Math.random()*50000 + 1000),
                            new Operator(OurCompany)));
        }

        //hire 80 managers with name is equal to their number, fixSalary may be [10000; 50 000)
        for(int i = 0; i < 80; i++){
            OurCompany.hire(new Employee(
                    "Manager",
                    Integer.toString(i + 1),
                    (int)(Math.random()*50000 + 10000),
                    new Manager(OurCompany)));
        }

        //hire 10 managers with name is equal to their number, fixSalary may be [50 000; 100 000)
        for(int i = 0; i < 10; i++){
            OurCompany.hire(new Employee(
                    "Top Manager",
                    Integer.toString(i + 1),
                    (int)(Math.random()*100000 + 50000),
                    new TopManager(OurCompany)));
        }

        //Sort tasks
        Workers = OurCompany.getTopSalaryStaff(10);
        System.out.println("Sorted by Top salary: ");
        for(Employee index: Workers){
            System.out.println((int) index.getFixSalary() + " rubles");
        }

        System.out.println();
        Workers = OurCompany.getLowestSalaryStaff(30);
        System.out.println("Sorted by Lowest salary: ");
        for(Employee index: Workers){
            System.out.println((int) index.getFixSalary() + " rubles");
        }

        System.out.println();
        //Fire task
        for (int i = 0; i < OurCompany.getEmployee_ID().size()/2; i++) {
            OurCompany.fire((int)Math.random()*10);
        }

        //Sort tasks
        Workers = OurCompany.getTopSalaryStaff(10);
        System.out.println("Sorted by Top salary: ");
        for(Employee index: Workers){
            System.out.println((int) index.getFixSalary() + " rubles");
        }

        System.out.println();
        Workers = OurCompany.getLowestSalaryStaff(30);
        System.out.println("Sorted by Lowest salary: ");
        for(Employee index: Workers){
            System.out.println((int) index.getFixSalary() + " rubles");
        }
    }
}
