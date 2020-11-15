// in the process!!!

package Lab_1920_Chatting;

import java.io.*;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner Data_IN = new Scanner(System.in);

        Path path = Paths.get(".")
                .toAbsolutePath()
                .getParent()
                .getParent();
                
        String basePath = "src/Lab_1920_Chatting";
        String mainFile = basePath + "/Main.java";
        String newFile = basePath + "/Copy.txt";
        
        File OneFile = new File(mainFile);
        
        if (OneFile.isDirectory()) {
            String[] list = OneFile.list();

            for (String s : list) {
                System.out.println(Paths.get(basePath, s).toAbsolutePath());
            }
        }
        String mainFilePath = OneFile.getAbsolutePath();
        try {
            try (
                    BufferedReader reader = new BufferedReader(new FileReader(mainFilePath));
                    PrintWriter writer = new PrintWriter(newFile)) {
                String line = reader.readLine();
                while (line != null) {
                    System.out.println(line);
                    writer.write(line);
                    writer.write('\n');
                    sc.nextLine();
                    line = reader.readLine();
                }
            }
        } catch (FileNotFoundException e) {
            System.out.println("Incorrect File path");
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

        System.out.println(path);
    }
}
