import java.util.HashSet;

public class Solution {

    public static void findPairs(int [] values, int target){
        //use a hashSet to store the values

        HashSet<Integer> set = new HashSet<Integer>();

        for (int i = 0; i<values.length; i++){
            //compliment is the number we need to find to form the pair with values[i] to = target
            int compliment = target - values[i];

            if(set.contains(compliment)){
                System.out.println("Pair with given taget "+target+" is ("+compliment+", "+values[i]+")");
                return;
            }
            set.add(values[i]);
        }
        System.out.println("No Valid Pairs");
    }



    public static void main(String[] args){
//        System.out.println("TEST");
        int arr[] = {14, 13, 6 ,7 ,8 , 10, 1, 2};
        int arr2[] = {14, 13, 6 ,7 ,8 , 10, 1};
        int arr3[] = {2,2};
        int arr4[] = {2};
        int arr5[] = {14, 13, 6, 7, 8, 10, 1};
        int arr6[] = {14, 13, 6, 7, 8, 10, 1};
        int arr7[] = {};

        findPairs(arr,3);
        findPairs(arr2,3);
        findPairs(arr3,4);
        findPairs(arr4,4);
        findPairs(arr5,-1);
        findPairs(arr6,0);
        findPairs(arr6,1);
    }
}
