import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException, InterruptedException {
      Worker You = new Worker();

      //do that, while true
      while(true){
        You.getInfo();
        You.DoOperations();
        Thread.sleep((int)(Math.random()*1000+1000));
      }
    }
}