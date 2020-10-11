package com.company;
import java.time.LocalDate;

public class Employee {
    private String Name, Surname, Residence, PhoneNumber;
    private int Salary;
    private LocalDate Birthday;

    public Employee(String name, String surname, String residence, String phoneNumber, int salary, LocalDate birthday) {
        Name = name;
        Surname = surname;
        Residence = residence;
        PhoneNumber = phoneNumber;
        Salary = salary;
        Birthday = birthday;
    }

    public String getName() {
        return Name;
    }

    public void setName(String name) {
        Name = name;
    }

    public String getSurname() {
        return Surname;
    }

    public void setSurname(String surname) {
        Surname = surname;
    }

    public String getResidence() {
        return Residence;
    }

    public void setResidence(String residence) {
        Residence = residence;
    }

    public String getPhoneNumber() {
        return PhoneNumber;
    }

    public void setPhoneNumber(String phoneNumber) {
        PhoneNumber = phoneNumber;
    }

    public int getSalary() {
        return Salary;
    }

    public void setSalary(int salary) {
        Salary = salary;
    }

    public LocalDate getBirthday() {
        return Birthday;
    }

    public void setBirthday(LocalDate birthday) {
        Birthday = birthday;
    }

    @Override
    public String toString() {
        return "Employee{" +
                "Name='" + Name + '\'' +
                ", Surname='" + Surname + '\'' +
                ", Residence='" + Residence + '\'' +
                ", PhoneNumber='" + PhoneNumber + '\'' +
                ", Salary=" + Salary +
                ", Birthday=" + Birthday +
                '}';
    }
}
