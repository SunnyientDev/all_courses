package Lab_25_26;
import java.util.*;

public class HashMapClass<K,V> implements HashMapInterface<K,V> {
    //properties
    private ArrayList<ArrayList<HashMapElement<K,V>>> HashList;
    private int HashMapSize = 8;

    //constuctor
    public HashMapClass() {
        HashList = new ArrayList<>();
        for (int i = 0; i < HashMapSize; i++)
            HashList.add(new ArrayList<>());
    }

    @Override
    public Iterator<V> iterator() {
        return new DesiredIterator();
    }

    //analogue for put method
    @Override
    public void add(K key, V value) {
        int CurrentIndex = key.hashCode() % HashList.size();

        if (HashList.get(CurrentIndex).size() != 0) {
            boolean Condition = false;

            for (int i = 0; i < HashList.get(CurrentIndex).size(); i++) {
                if (HashList.get(CurrentIndex).get(i).getKey().equals(key)) {
                    HashList.get(CurrentIndex).set(i, new HashMapElement<>(key, value));
                    Condition = true; break;
                }
            } if (Condition == true) HashList.get(CurrentIndex).add(new HashMapElement<>(key, value));
        } else HashList.get(CurrentIndex).add(new HashMapElement<>(key, value));
    }

    //get key
    @Override
    public V get(K key) {
        int CurrentIndex = key.hashCode() % HashList.size();

        for (int i = 0; i < HashList.get(CurrentIndex).size(); i++)
            if (HashList.get(CurrentIndex).get(i).getKey().equals(key))
                return HashList.get(CurrentIndex).get(i).getValue();

        return null;
    }

    //delete key
    @Override
    public V remove(K key) {
        int CurrentIndex = key.hashCode() % HashList.size();

        for (int i = 0; i < HashList.get(CurrentIndex).size(); i++) {
            if (HashList.get(CurrentIndex).get(i).getKey().equals(key)) {
                HashMapElement<K, V> HMelement = new HashMapElement<>();

                HMelement.setValue(HashList.get(CurrentIndex).get(i).getValue());
                HashList.get(CurrentIndex).remove(HashList.get(CurrentIndex).get(i));

                return HMelement.getValue();
            }
        } return null;
    }

//Class 'HashMapClass' must either be declared abstract or implement abstract method 'iterator()' in 'Iterable'
    private class DesiredIterator implements Iterator<V> {
        private int ElementIndex = 0;
        private int ArrayIndex = 0;

    //Class 'DesiredIterator' must either be declared abstract or implement abstract method 'hasNext()' in 'Iterator'
    @Override
    public boolean hasNext() {
        if (ElementIndex == HashList.get(ArrayIndex).size()) {
            ElementIndex = 0;
            while(ArrayIndex < HashMapSize && HashList.get(ArrayIndex).size() == 0) ArrayIndex++;
        }
        return ArrayIndex < HashMapSize;
    }

    @Override
    public V next() {
        return HashList.get(ArrayIndex).get(ElementIndex + 1).getValue();
    }
}
}
