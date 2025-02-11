import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int a;
        String s;
        char b;

        Scanner sc = new Scanner(System.in);
        System.out.print("saisir la valeur de a : ");
        a = sc.nextInt();
        System.out.println("la veleur de a est : " + a);

        Scanner scs = new Scanner(System.in);
        System.out.print("saisir une chaine de carac : ");
        s = scs.nextLine();
        System.out.println("vous avez saisis : " + s);

        System.out.print("saisir un caractere : ");
        b = (scs.nextLine()).charAt(0);
        System.out.println("vous avez saisis le caractere : " + b);

        int []T = new int[3];
        for (int i = 0; i < 3; i++) {
            System.out.println("T[" +i+ "] = ");
            T[i] = sc.nextInt();
        }

        System.out.println("le tableau est : ");
        for (int i = 0; i < 3; i++) {
            System.out.println(T[i]);
        }
    }
}