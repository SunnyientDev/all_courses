package com.company;

public class Employee {
    private String Surname, Name;
    private double FixSalary;
    private int ID;
    EmployeePosition OnePosition;

    public Employee(String surname, String name, int fixSalary, EmployeePosition onePosition) {
        Surname = surname;
        Name = name;
        FixSalary = fixSalary;
        OnePosition = onePosition;
    }

    public String getSurname() { return Surname; }
    public void setSurname(String surname) { Surname = surname; }

    public String getName() { return Name; }
    public void setName(String name) { Name = name; }

    public double getFixSalary() { return OnePosition.calcSalary(FixSalary); }
    public void setFixSalary(double fixSalary) { FixSalary = fixSalary; }

    public EmployeePosition getEmployeePosition() { return OnePosition; }
    public void setEmployeePosition(EmployeePosition onePosition) {
        OnePosition = onePosition;
    }

    public int getID() { return ID; }
    public void setID(int ID) { this.ID = ID; }

    @Override
    public String toString() {
        return "Employee{" +
                "Surname = " + Surname + '\'' +
                ", Name = " + Name + '\'' +
                ", FixSalary = " + FixSalary +
                ", ID = " + ID +
                ", OnePosition = " + OnePosition +
                '}';
    }
}
