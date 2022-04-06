package com.company;

import javax.swing.*;
import java.util.ArrayList;
import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.atomic.AtomicInteger;

public class Main {
    static AtomicInteger totalSum = new AtomicInteger(); //0 as default

    public static void main(String[] args) throws InterruptedException { //working with blocking method
        long startTime = System.currentTimeMillis();
        ArrayList<Thread> Threads = new ArrayList<>();

        for (int i = 0; i < 10; i++) {
            final int localI = i; //value of the variable cannot be changed
            Thread OneThread = new Thread(()->Work(localI));
            OneThread.start();
            Threads.add(OneThread);
        }

        for (Thread OneThread : Threads){
            System.out.println(OneThread.getState());
            OneThread.join();
        }

        long endTime = System.currentTimeMillis();
        System.out.println("Total time: " + (endTime - startTime));
        System.out.println("Total sum: " + totalSum);
    }

    private static void Work(int index){
        long startTime = System.currentTimeMillis();
        long Result = DoHardWork(index * 1000, 1_000_000);
        long endTime = System.currentTimeMillis();
        System.out.println(index + ": " + Result + " | " + (endTime - startTime));
    }

    private static long DoHardWork(int Start, int Count){
        long number = 0;
        for (int i = 0; i < Count; i++) {
            number += Math.sqrt(Start + i) * Math.pow(i, Start);
            totalSum.incrementAndGet();
        }
        return number;
    }
}
