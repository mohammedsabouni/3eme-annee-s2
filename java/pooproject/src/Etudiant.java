public class Etudiant {
    private String cin;
    public String nom;
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

    public String getCin(){
        return cin;
    }

    public void setCin(String cin){
        this.cin = cin;
    }
}
