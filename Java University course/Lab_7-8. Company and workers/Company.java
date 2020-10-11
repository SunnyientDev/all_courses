package com.company;
import java.util.*;

public class Company {
    private String CompanyName;
    private long CompanyIncome;

    //List with employers
    private ArrayList <Employee> Employees = new ArrayList<>();
    Vector <Integer> Employee_ID = new Vector<>();

    public Company(String companyName, long companyIncome) {
        CompanyName = companyName;
        CompanyIncome = companyIncome;
    }

    void hire(Employee OneEmployee){
        int New_ID = (int)(Math.random() * (1000000));
        //if this ID is exist, we must generate another one
        while(Employee_ID.contains(New_ID))
            New_ID = (int)(Math.random() * (1000000));

        Employee_ID.add(New_ID);

        //Set ID to our new worker
        OneEmployee.setID(New_ID);
        Employees.add(OneEmployee);
    }

    void hireAll(List<Employee> Employees){
        for(Employee Worker: Employees) hire(Worker);
    }

    void fire(int NumberOfWorkers){
        Employee OneEmployee = null;
        for(Employee Worker: Employees){
            if(NumberOfWorkers == Worker.getID()) OneEmployee = Worker;
        }
        Employees.remove(OneEmployee);
        Employee_ID.remove((Integer)NumberOfWorkers);
    }

    //Company income is depends of managers
    public double getIncome() {
        long CompanyIncome = 0;

        for(Employee Worker: Employees){
            if(Worker.getEmployeePosition() instanceof Manager)
                CompanyIncome += ((Manager) Worker.getEmployeePosition()).getIncome();
        }
        return CompanyIncome;
    }

    public void setIncome(long companyIncome) {
        CompanyIncome = companyIncome;
    }

    public ArrayList<Employee> getEmployees() {
        return Employees;
    }

    public void setEmployees(ArrayList<Employee> employees) {
        Employees = employees;
    }

    public void sortList(){
        Employees.sort(Comparator.comparing(Employee::getFixSalary).reversed());
    }

    List <Employee> getTopSalaryStaff(int count){
        if(count > 0){
            this.sortList();
            return Employees.subList(0, count);
        } else {
            System.out.println("You've entered an incorrect number of employees");
            return null;
        }
    }


    List <Employee> getLowestSalaryStaff(int count){
        if(count > 0){
            this.sortList();
            return Employees.subList(Employees.size() - count, Employees.size());
        } else {
            System.out.println("You've entered an incorrect number of employees");
            return null;
        }
    }

    public Vector<Integer> getEmployee_ID() {
        return Employee_ID;
    }
}
