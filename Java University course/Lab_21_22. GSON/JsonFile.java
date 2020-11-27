import com.google.gson.*;
import java.io.*;
import java.lang.*;
import java.util.*;

public class File  implements ItemsStore{
  Gson gson = new Gson();
  private FileWriter fileWriter;
  private JsonWriter jsonWriter;

  //data.json file
  private String Path = "D:\\Work\\IntelliJ IDEA projects\\lab_20_21\\src\\main\\java\\lab_20_21\\data.json";
  private File file = new File(Path);

  //to sort list
  private void sort(List<Item> Items){
    Items.sort((a, b) -> (int) Math.signum(a.getId() - b.getId()));
  }

  //set up everything in order
  public List<Item> getAll() {
    Type type = new TypeToken<List<Item>>(){}.getType();
    List<Item> Items = null;
    
    try(FileReader fileReader = new FileReader(file)) {
      Items = gson.fromJson(fileReader, type);
    } catch (IOException exception) {
        exception.printStackTrace();
    }
    return Items;
  }

  public Item get(int ID) throws IOException, InterruptedException {
    List<Item> Items = getAll();
    for (Item index:Items){
      if(index.getId() == ID) return index;
    }
    return null;
  }

  public Item addItem(Item item) throws IOException, InterruptedException {
    List<Item> Items = getAll();
    item.setId(getNewID()); Items.add(item); sort(Items);
    
    fileWriter = new FileWriter(path);
    fileWriter.write("[\n");
        
    for (Item i: Items) {
      fileWriter.write(gson.toJson(i));
      if(Items.indexOf(i) != Items.size()-1) fileWriter.write(",");
      fileWriter.write("\n");
    }
    
    fileWriter.write("\n]");
    fileWriter.close();
    return get(item.getId());
  }

  public Item editItem(Item item, int id) throws IOException, InterruptedException {
    List<Item> Items = getAll();
    Items.removeIf(i->i.getId() == id); Items.add(item); sort(Items);
        
    fileWriter = new FileWriter(path);
    fileWriter.write("[\n");
    
    for (Item i:Items){
      fileWriter.write(gson.toJson(i));
      if(Items.indexOf(i) != Items.size()-1) fileWriter.write(",");
      fileWriter.write("\n");
    }
        
    fileWriter.write("\n]"); fileWriter.close();
    return get(item.getId());
  }

  public void deleteItem(int id) throws IOException, InterruptedException {
    List<Item> Items = getAll();
    Items.removeIf(i -> i.getId() == id); sort(Items);
        
    fileWriter = new FileWriter(path);
    fileWriter.write("[\n");
    
    for (Item i:Items) {
      fileWriter.write(gson.toJson(i));
      
      if(Items.indexOf(i) != Items.size()-1) fileWriter.write(",");
      fileWriter.write("\n");
    }
      
      fileWriter.write("\n]"); fileWriter.close();
  }

  private int getNewID(){
    List<Item> Items = getAll();
    ArrayList<Integer> ids = new ArrayList<>();
    
    for (Item i: Items) ids.add(i.getId());
    
    int id = 1;
    while(ids.contains(id)) id++;
    return id;
  }
}