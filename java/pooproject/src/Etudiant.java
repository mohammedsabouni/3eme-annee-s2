public class Etudiant {
    public String cin;
    private String nom;
    protected String prenom;
    int age;

    public Etudiant(String cin, String nom, String prenom, int age){
        this.cin = cin;
        this.nom = nom;
        this.prenom = prenom;
        this.age = age;
    }

    public void afficher(){
        System.out.println("cin : " + cin + " nom : " + nom + " prenom : " + prenom + " age : " + age );
    }
}
