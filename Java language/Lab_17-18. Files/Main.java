package Lab_17_Files_vs_Markdown;

import java.io.*;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;

public class Main {
    static PrintWriter MarkdownFile;

    static {
        try {
            PrintWriter MarkdownFile = new PrintWriter("result.md");
        } catch (FileNotFoundException OneException) {
            OneException.printStackTrace();
        }
    }

    public static void SearchJavaFiles(String PathToFile){
        File CurrentFile = new File(PathToFile);

        if(CurrentFile.isDirectory()){
            String[] PathFiles = CurrentFile.list();

            for (String s: PathFiles){
                SearchJavaFiles(PathToFile + "/" + s);
            }
        }

        if(CurrentFile.isFile()){
            if(CurrentFile.getName().endsWith(".java")){
                try(BufferedReader Reader =  new BufferedReader(new FileReader(PathToFile))){
                    MarkdownFile.write("##" + PathToFile + "\n'''java\n");
                    String line = Reader.readLine();

                    while (line != null){
                        MarkdownFile.write(line + "\n");
                        line = Reader.readLine();
                    }
                    MarkdownFile.write("'''\n");
                } catch (FileNotFoundException OneException){
                    OneException.printStackTrace();
                } catch (IOException OneException){
                    OneException.printStackTrace();
                }
            }
        }
    }

    public static void main(String[] args) {
        String basePath = "D:\\Work\\IntelliJ IDEA projects\\Java_Test\\src";
        File OneFile = new File(basePath);

        String[] Files = OneFile.list(); String[] Paths = new String[Files.length];
        for (int i = 0; i < Files.length; i++) {
            Paths[i] = basePath + "\\" + Files[i];
            SearchJavaFiles(Paths[i]);
        }
        MarkdownFile.close();
    }
}
