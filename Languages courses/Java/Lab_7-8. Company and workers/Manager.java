package com.company;

public class Manager implements EmployeePosition{
    private Company OneCompany;
    private int Income;

    public Manager(Company oneCompany) {
        OneCompany = oneCompany;
        Income = (int)((Math.random() * ((140000 - 115000) + 1)) + 115000);
    }

    @Override
    public String getJobTitle() {
        return "Manager";
    }

    @Override
    public double calcSalary(double baseSalary) {
        return baseSalary + 0.05*Income;
    }

    public int getIncome() {
        return Income;
    }

    public void setIncome(int income) {
        Income = income;
    }
}
