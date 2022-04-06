package com.company;

import javax.xml.crypto.Data;
import java.util.*;
import java.util.regex.*;

public class WithoutExpression {
    public static void main(String[] args){
        Scanner Data_IN = new Scanner(System.in);

        Map<String, String> Rule = new HashMap<>();
        String Key, Value;
        String Word;

        String SubString;
        boolean Condition = false; //we're checking substring and key equivalence for match task
        String Result = "";

        int RulesCount = Data_IN.nextInt();
        //rule entry
        while(true){
            if(RulesCount == 0) break;
            Key = Data_IN.next();
            Value = Data_IN.next();
            Rule.put(Key, Value);
            RulesCount--;
        }

        Word = Data_IN.next();
        //convert Map to Array list for convenience of working with iterators
        List<Map.Entry<String, String>> RuleConverted = new ArrayList<>(Rule.entrySet());

        for (int i = 0; i < Word.length(); i++) {
            Condition = false;

            for (int j = 0; j < RuleConverted.size(); j++) {

                //if key length plus i is not greater than word length, make new substring
                if (!(RuleConverted.get(j).getKey().length() + i > Word.length())) {
                    //SubString is equal to substring from i to Key length
                    SubString = Word.substring(i, i + RuleConverted.get(j).getKey().length());

                    if (SubString.equals(RuleConverted.get(j).getKey())) { //if it matches, condition is performed
                        Condition = true;
                        Result += RuleConverted.get(j).getValue();
                        i += RuleConverted.get(j).getKey().length() - 1;
                        break;
                    }
                }
            }
            if(!Condition) Result += Word.charAt(i);
        }
        System.out.println(Result);
    }
}
