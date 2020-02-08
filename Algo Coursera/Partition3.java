import java.util.*;
import java.io.*;

public class Partition3 {


    //Runtime for this solution is O(n*m)
    //Space Complexity O(n)
    public static boolean canPartition(int [] nums){
        //simple check to see if numbers added are even or odd, if odd return true
        int total = 0;

        //iterate through array, calculate total of all elements in array
        for(int i :nums){
            total += i;
        }

        //simulate splitting into 3 partitions that sum to the same number
        if(total % 3 != 0)
            return false;

        //in order to implement memoization, we need to introduce 'state' for when we find partiitons, we use a HashMap
        //our keys will be String, Boolean
        return canPartition(nums, 0, 0, total, new HashMap<String, Boolean>());
    }

    public static boolean canPartition(int[] nums, int index, int sum, int total, HashMap<String, Boolean> state){
        //Overloaded method that takes num array, index, sum, total, HashMap for states

        //Our current state is just our index and sum in form ---> 2 10 (for example)
        String currentState = index +""+sum;

        //if our state contains the current, we just return what it is
        //AKA if it was already  computeted in a previous call
        if(state.containsKey(currentState)){
            return state.get(currentState);
        }

        if(sum * 3 == total)
            return true;

        if(sum > total/3 || index >= nums.length)
            return false;


        //boolean value for whether the partition found or NOT
        boolean foundPartition = canPartition(nums, index+1, sum, total, state)
                || canPartition(nums, index+1, sum + nums[index], total, state);

        //we put our currentState into the hashMap
        state.put(currentState,foundPartition);

        //return the foundPartion
        return  foundPartition;

    }

    public static int partition3(int[] nums){
        Boolean partitionFound = canPartition(nums);

        return (partitionFound == true) ? 1:0;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }
        System.out.println(partition3(A));
    }
}

