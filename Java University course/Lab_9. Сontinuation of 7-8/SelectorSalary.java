package com.company;

public class SelectorSalary implements SelectorEmployee{
    private double MinSalary;

    public SelectorSalary(double minSalary) {
        MinSalary = minSalary;
    }

    @Override
    public boolean isNeed(Employee OneEmployee) {
        return MinSalary > OneEmployee.getSalary();
    }
}
