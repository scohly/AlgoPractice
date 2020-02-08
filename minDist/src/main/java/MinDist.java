import java.util.Scanner;

public class MinDist {

    public static int EditDistance(String str1, String str2) {
        //write your code here
        int table[][] = new int[str1.length()+1][str2.length()+1];

        for(int i = 0; i<table[0].length; i++)
            table[0][i]= i;
        for(int i=0; i<table.length;i++)
            table[i][0] = i;

        for(int i = 1; i <= str1.length(); i++){
            for(int j = 1; j <= str2.length(); j++){
                if(str1[i-1] == str2[j-1])
            }
        }


        return 0;
    }

    private int min(int a, int b, int c){
        int l = Math.min(a,b);
        return Math.min(l,c);
    }

    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);

        String s = scan.next();
        String t = scan.next();

        System.out.println(EditDistance(s, t));
    }


}
