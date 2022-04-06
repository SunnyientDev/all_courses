package Lab_27_28;

public class Task {
    private Data data;
    private String type;
    private int id;

    //generate
    public Data getData() {
        return data;
    }

    public void setData(Data data) {
        this.data = data;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String toString() {
        return "Task{" +
                "data=" + data +
                ", type='" + type + '\'' +
                ", id=" + id +
                '}';
    }
}
