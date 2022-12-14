package com.company;

public class Operator implements EmployeePosition{
    private Company OneCompany;

    public Operator(Company oneCompany) {
        OneCompany = oneCompany;
    }

    @Override
    public double calcSalary(double baseSalary) {
        return baseSalary;
    }

    @Override
    public String getJobTitle() {
        return "Operator";
    }
}
