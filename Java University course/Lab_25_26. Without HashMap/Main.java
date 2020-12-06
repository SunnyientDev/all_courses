/*
Practical work No. 25-26

Implement interface lessonsJava2020 / HashMapInterface.java at master CAPCHIK / lessonsJava2020 (github.com)
When implementing, DO NOT use the HashMap classes and others from the JDK. You need to implement the functionality yourself.
You can use LinkedList, ArrayList, and others.
 */
package Lab_25_26;

public class Main {
    public static void main(String[] args) {
        HashMapClass<String, Integer> InventionsSheet = new HashMapClass<>();

        InventionsSheet.add("Ultra Mobile PC from LG", 2010);
        InventionsSheet.add("Virtual Reality Helmet", 2012);
        InventionsSheet.add("Laser space communication", 2013);
        InventionsSheet.add("MEMS nanoinjector", 2014);
        InventionsSheet.add("NERD bacterium", 2015);

        //example
        System.out.println("Key NERD bacterium: " + InventionsSheet.get("NERD bacterium"));
    }
}
