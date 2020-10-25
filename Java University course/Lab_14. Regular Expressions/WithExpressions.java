package com.company;

import javax.xml.crypto.Data;
import java.util.*;
import java.util.regex.Pattern;
import java.util.regex.*;

public class WithExpressions {
    public static void main(String[] args){
        Scanner Data_IN = new Scanner(System.in);
        String Word;

        int RulesCount = Data_IN.nextInt();
        Map<String, String> Rule = new HashMap<>();
        String Key, Value;
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
        StringBuilder RegEx = new StringBuilder();

        for (int i = 0; i < RuleConverted.size(); i++) {
            RegEx.append(RuleConverted.get(i).getKey());

            if(i < RuleConverted.size() - 1){
                RegEx.append("|");
            }
        }

        Pattern OnePattern = Pattern.compile(RegEx.toString());
        Matcher OneMathcer = OnePattern.matcher(Word);

        //result
        String Result = OneMathcer.replaceAll(index->Rule.get(index.group()));
        System.out.println("Result: " + Result);
    }
}
