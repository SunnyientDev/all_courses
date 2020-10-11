package com.company;
import java.time.LocalDate;

public class Main {
    public static void main(String[] args){
        Company OneCompany = new Company();

        for(int i = 0; i < 5; i++){
            OneCompany.hire(new Employee(
                    "FirstName",
                    "SecondName",
                    "Country, City",
                    "654-645-234",
                    (int)(Math.random()*1000),
                    LocalDate.of(2000, 1, i + 1)));
        }

        OneCompany.DoAnything(new SelectorEmployee() {
            @Override
            public boolean isNeed(Employee OneEmployee) {
                return OneEmployee.getSalary() < 6_000;
            }
        },OneEmployee -> OneEmployee.getSalary());
        OneCompany.DoAnything(new SelectorSalary(4000), OneEmployee -> OneEmployee.getSalary());
    }
}
