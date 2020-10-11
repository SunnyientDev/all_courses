package com.company;
import java.util.ArrayList;

public class Company {
    private ArrayList<Employee> Employeers = new ArrayList<>();

    public void fire(int ObjectIndex){
        Employeers.remove(ObjectIndex);
    }

    public void hire(Employee OneEmployee){
        Employeers.add(OneEmployee);
    }

    public void DoAnything(SelectorEmployee OneSelector, HandlerEmployee OneHandler){
        int Count = 0;
        for(Employee Worker: Employeers){
            if(OneSelector.isNeed(Worker)){
                OneHandler.Handler(Worker);
                System.out.println(Worker.toString());
                Count++;
            }
        }
    }

    @Override
    public String toString() {
        return "Company{" +
                "Employeers =" + Employeers +
                '}';
    }
}
