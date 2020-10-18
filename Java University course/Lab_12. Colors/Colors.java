package com.company;

public enum Colors {
    RED(31), YELLOW(33), BLUE(34), GREEN(32); //with constructor

    private int value;
    private Colors(){}

    private Colors(int value) {
        this.value = value;
    }

    public int getValue() {
        return value;
    }
}
