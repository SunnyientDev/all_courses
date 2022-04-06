
public class Item {
    private int ID;
    private String Data;
    private String description;
    private boolean Condition;
    
    public Item(int ID, String Data, boolean Condition, String description) {
        this.ID = ID;
        this.Data = Data;
        this.Condition = Condition;
        this.description = description;
    }

    public int getID() { return ID; }
    public String getData() { return Data; }
    public String getdescription() { return description; }

    public voID setID(int ID) { this.ID = ID; }
    public voID setData(String Data) { this.Data = Data;}
    public voID setCond(boolean Cond) { Condition = Cond;}
    public voID setdescription(String description) { this.description = description; }

    public boolean Condition() { return Condition; }

    public String toString() {
        return "Item{" +
                "ID=" + ID +
                ", Data='" + Data + '\'' +
                ", Condition=" + Condition + '\'' +
                '}';
    }
}