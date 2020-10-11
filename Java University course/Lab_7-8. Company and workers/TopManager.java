package com.company;

public class TopManager implements EmployeePosition {
    private Company OneCompany;

    public TopManager(Company oneCompany) {
        OneCompany = oneCompany;
    }

    @Override
    public String getJobTitle() {
        return "Top Manager";
    }

    @Override
    public double calcSalary(double baseSalary) {
        if(OneCompany.getIncome() > 10000000) return 2.5*baseSalary;
        else return baseSalary;
    }
}
