import java.util.Random;

abstract class Compartment {
    public abstract String notice();
}

class FirstClass extends Compartment {
    public String notice() {
        return "First Class - Please maintain silence and comfort.";
    }
}

class Ladies extends Compartment {
    public String notice() {
        return "Ladies Compartment - Reserved only for female passengers.";
    }
}

class General extends Compartment {
    public String notice() {
        return "General Compartment - Please avoid overcrowding.";
    }
}

class Luggage extends Compartment {
    public String notice() {
        return "Luggage Compartment - Passenger entry is not allowed.";
    }
}

public class TestCompartment {
    public static void main(String[] args) {

        Compartment[] coach = new Compartment[10];
        Random random = new Random();

        for (int i = 0; i < coach.length; i++) {

            int choice = random.nextInt(4) + 1;

            if (choice == 1) {
                coach[i] = new FirstClass();
            } else if (choice == 2) {
                coach[i] = new Ladies();
            } else if (choice == 3) {
                coach[i] = new General();
            } else {
                coach[i] = new Luggage();
            }
        }

        System.out.println("Railway Coach Details\n");

        for (int i = 0; i < coach.length; i++) {
            System.out.println("Compartment " + (i + 1));
            System.out.println(coach[i].notice());
            System.out.println();
        }
    }
}
