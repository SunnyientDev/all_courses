package java_practice.practice_15;

import javax.swing.*;
import java.util.ArrayList;

public class Pattern {
    private State S1, S2, S3, S4, S5 = new State();

    public Pattern() {
        S1.Settings(1, S5,"add_library"); S1.Settings(0, S2,"create_project");
        S2.Settings(1, S4,"drop_db");     S2.Settings(0, S3, "test");
        S3.Settings(1, S5,"add_library"); S3.Settings(0, S4, "drop_db");
        S4.Settings(1, S5,"deploy");      S4.Settings(0, S3,"restart");
        S5.Settings(1, S3,"restart");     S5.Settings(0, S1,"deploy");
    }

    private ArrayList<String> ActionCodeName = new ArrayList<>();
    State CurrentBlock = new State();

    public void getActionCodeName() {
        for(String CurrentName: ActionCodeName) System.out.println(ActionCodeName);
    }

    public void Processing(int CommandName){
        for (int i = 0; i < S1.getConnections().size(); i++)
            if (S1.getConnections().get(i) == CommandName){
                ActionCodeName.add(S1.getCommandNames().get(i));
                S1 = S1.getStates().get(i);
            }
    }
}
