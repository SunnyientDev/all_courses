//Added Exceptions

import java.util.List;
import java.io.*;

public interface ItemsStore {
    List<Item> getAll()        throws IOException, InterruptedException;
    Item get(int id)           throws IOException, InterruptedException;
    Item addItem(Item item)    throws IOException, InterruptedException;
    Item editItem(Item item)   throws IOException, InterruptedException;
    void deleteItem(Item item) throws IOException, InterruptedException;
}