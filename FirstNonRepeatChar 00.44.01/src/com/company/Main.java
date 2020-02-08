package com.company;

import jdk.swing.interop.SwingInterOpUtils;

import java.sql.SQLOutput;
import java.util.HashMap;
import java.util.Scanner;

public class Main {

    public  static char firstNonRepeatHash(String input){
        //Create the HashMap for storing frequency count for characters
        HashMap<Character, Integer> charFrequency = new HashMap();

        //iterate through each position of the given string; use for loop
        for(int i = 0; i<input.length(); i++){

            //charAt returns a char value at a given position in the string
            char c = input.charAt(i);

            //the if/else logic here checkts to see if the map has a value for the given character c
            //if it does, we add 1 to the already existing count hence the c, charFrequency.get(c)+1
            if(charFrequency.containsKey(c)){
                charFrequency.put(c,charFrequency.get(c)+1);
            }
            else{
                charFrequency.put(c,1);
            }
        }
        for (int i = 0; i<input.length(); i++){
            char c = input.charAt(i);
            if(charFrequency.get(c) == 1) return c;
        }

        return '_';
    }

    public static char firstNonRepeatArr(String input){
        int[] charCount = new int[26];
        //array to keep track of char counts

        //loop goes through string, for each char we take that char- 'a' and increment the count
        for(char c: input.toCharArray()) charCount[c-'a']++;

        //second loop to check array for first c that == 1
        for(char c: input.toCharArray()){
            if(charCount[c-'a'] == 1)return c;
        }

        //if nothing
        return '_';
    }

    public static char firstNonRepeatIndex(String input){

        //loop goes through whole length of string
        //if checks the index of the string at pos i if it equals the last indexOf that means it appears only ONCE!
        for(int i = 0; i<input.length(); i++){
            if(input.indexOf(input.charAt(i)) == input.lastIndexOf(input.charAt(i))){
                return  input.charAt(i);
            }
        }
        return '_';
    }






    public static void main(String [] args){

//        Scanner in = new Scanner(System.in);
//
//        System.out.println("Please enter a String: ");
//        String test1 = in.nextLine();

        String test1 = "aabbcddezzffg"; //--->c

        String test2 = "aabbzfyy"; //--->z

        String test3 = "aabbwt"; //--->w

        System.out.println("Finding the first non repeating char using hashMap: "+firstNonRepeatHash(test1));
        System.out.println( "Finding the first non repeating char using arr method: "+firstNonRepeatArr(test1));
        System.out.println("Finding the firsat non repeating char using index method: "+firstNonRepeatIndex(test1));
        System.out.println();

        System.out.println("Finding the first non repeating char using hashMap: "+firstNonRepeatHash(test2));
        System.out.println( "Finding the first non repeating char using arr method: "+firstNonRepeatArr(test2));
        System.out.println("Finding the firsat non repeating char using index method: "+firstNonRepeatIndex(test2));
        System.out.println();

        System.out.println("Finding the first non repeating char using hashMap: "+firstNonRepeatHash(test3));
        System.out.println( "Finding the first non repeating char using arr method: "+firstNonRepeatArr(test3));
        System.out.println("Finding the firsat non repeating char using index method: "+firstNonRepeatIndex(test3));

    }
}
