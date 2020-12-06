package Lab_25_26;

public class HashMapElement<K,V> {
    private K Key;
    private V Value;

    public HashMapElement(K key, V value) {
        Key = key;
        Value = value;
    }

    public HashMapElement() {

    }

    public K getKey() {
        return Key;
    }

    public void setKey(K key) {
        Key = key;
    }

    public V getValue() {
        return Value;
    }

    public void setValue(V value) {
        Value = value;
    }
}
