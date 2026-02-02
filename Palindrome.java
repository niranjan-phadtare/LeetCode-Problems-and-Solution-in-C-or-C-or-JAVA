import java.util.*;
public class Main{
    public static void main(String args[]){
        char s[] = {'m','a','d','a','m','\0'};
        int n = 4;
        int i = 0;
        while(i < n){
            if(s[i]==s[n]){
                i++;
                n--;
            }
            else{
                System.out.println("Given String is Not a Palindrome");
            }
        }
        System.out.println("Given String is a Palindrome");
    }
}
