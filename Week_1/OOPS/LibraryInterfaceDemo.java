interface LibraryUser {
    void registerAccount();

    void requestBook();
}

class KidUsers implements LibraryUser {
    int age;
    String bookType;

    @Override
    public void registerAccount() {
        if (this.age < 12)
            System.out.println("You have successfully registered under a Kids Account");
        if (this.age > 12)
            System.out.println("Sorry, Age must be less than 12 to register as a kid");
    };

    @Override
    public void requestBook() {
        if (this.bookType.equals("Kids"))
            System.out.println("Book Issued successfully, please return the book\r\n" + //
                    "within 10 days");
        else {
            System.out.println("Oops, you are allowed to take only kids books");
        }
    };

}

class AdultUser implements LibraryUser {
    int age;
    String bookType;

    @Override
    public void registerAccount() {
        if (this.age > 12)
            System.out.println("You have successfully registered under an Adult Account");
        if (this.age < 12)
            System.out.println("Sorry, Age must be greater than 12 to register as an adult");
    };

    @Override
    public void requestBook() {
        if (this.bookType.equals("Fiction"))
            System.out.println("Book Issued successfully, please return the book\r\n" + //
                    "within 7 days");
        else {
            System.out.println("Oops, you are allowed to take only adult Fiction books");
        }
    };
}

public class LibraryInterfaceDemo {
    public static void main(String[] args) {

        // Test Case 1 - KidUser

        KidUsers kid1 = new KidUsers();
        kid1.age = 10;
        kid1.bookType = "Kids";
        kid1.registerAccount();
        kid1.requestBook();

        KidUsers kid2 = new KidUsers();
        kid2.age = 18;
        kid2.bookType = "Fiction";
        kid2.registerAccount();
        kid2.requestBook();

        // Test Case 2 - AdultUser

        AdultUser adult1 = new AdultUser();
        adult1.age = 5;
        adult1.bookType = "Kids";
        adult1.registerAccount();
        adult1.requestBook();

        AdultUser adult2 = new AdultUser();
        adult2.age = 23;
        adult2.bookType = "Fiction";
        adult2.registerAccount();
        adult2.requestBook();
    }
}