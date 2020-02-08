import java.util.*;
import java.math.*;

import static java.lang.Math.min;


public class DpCalc {



    private static List<Integer> dp_sequence(int n){
        //create our return List aka sequence
        List<Integer> sequence = new ArrayList<>();

        //create our array with 1 + the number we are looking for min operations for
        int[] arr = new int[n+1];

        //forloop to iterate from 1 to length of arr
        for(int i = 1; i<arr.length; i++) {
            //we set arr[i] = to prev element + 1
            arr[i] = arr[i - 1] + 1;

            //we check the modulus after this operation for 2 then 3, if they comply we perofrm the operation wehre
            //we take the min of 1 + arr[i/2] or arr[i/3] and we set that to the arr at position i
            if (i % 2 == 0)
                arr[i] = min(1 + arr[i / 2], arr[i]);
            if (i % 3 == 0)
                arr[i] = min(1 + arr[i / 3], arr[i]);
        }

        //next loop starts at our entered value n
        for(int i = n; i>1;){
            //we add the first index to return sequence
            sequence.add(i);

            //if the next value is equal to current val - 1 we set i to thte next (We are decrementing here)
            if(arr[i -1] == arr[i] -1)
                i = i-1;
            else if(i % 2 == 0 && (arr[i/2] == arr[i] -1))
                i = i/2;
            else if(i % 3 == 0 && (arr[i/3] == arr[i] - 1))
                i = i/3;
        }
        sequence.add(1);
        Collections.reverse(sequence);

        return sequence;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Integer> sequence = dp_sequence(n);
        System.out.println(sequence.size() - 1);
        for (Integer x : sequence) {
            System.out.print(x + " ");
        }
    }
}



