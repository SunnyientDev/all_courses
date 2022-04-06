package java_practice.practice_15;

import java.lang.reflect.Array;
import java.util.ArrayList;

public class State {
    private ArrayList<Integer> Connections = new ArrayList<>();
    private ArrayList<State> States = new ArrayList<>();
    private ArrayList<String> CommandNames = new ArrayList<>();

    public void Settings(int Connection, State State, String CommandName){
        Connections.add(Connection);
        States.add(State);
        CommandNames.add(CommandName);
    }

    public ArrayList<Integer> getConnections() {
        return Connections;
    }

    public ArrayList<State> getStates() {
        return States;
    }

    public ArrayList<String> getCommandNames() {
        return CommandNames;
    }
}
