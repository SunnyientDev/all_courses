import java.util.*;

class Main {
  public static void main(String[] args) {
    HashMap<String, Integer> map = new HashMap<>();

    map.put("vishal", 10); 
    map.put("sachin", 30); 
    map.put("vaibhav", 20); 
  
    System.out.println("map size: " + map.size());
    System.out.println(map);

    //Just checking
    if(map.containsKey("vishal")){
      Integer a = map.get("vishal");
      System.out.println("value " + a);
    }
  }
}
