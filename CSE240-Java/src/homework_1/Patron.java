package homework_1;

/**
* A class containing the aspects of a Patron.</br>
* Homework 1 </br>
* Completion time: 45 min
* 
* @author Anton Neuhold
* @version 1.0
*/
public class Patron {
  /** 
   * The {@link String} instance representing the Patron's last name.
   */
  private String lastName;
  /** 
   * The {@link String} instance representing the Patron's first name.
   */
  private String firstName;
  
  /**
   * Constructs a {@link Patron} object with the first and last name of "***".
   */
  public Patron() {
    this.lastName = "***";
    this.firstName = "***";
  }
  
  /**
   * Constructs a {@link Patron} object with the given patron info string.
   * If the string does not contain a last name, the last name becomes "***"
   * by default.
   * @param patronInfo a <code>String</code> containing the first and last
   * name of the patron. The string can be separated by spaces or some other
   * non-word delimiter.
   */
  public Patron(String patronInfo) {
    String[] name = patronInfo.split("\\W");
    this.firstName = name[0];
    if (name.length <= 1) {
      this.lastName = "***";
    } else {
      this.lastName = name[1];
    }
  }
  
  /**
   * @return the lastName
   */
  public String getLastName() {
    return lastName;
  }

  /**
   * @return the firstName
   */
  public String getFirstName() {
    return firstName;
  }

  /**
   * Creates a string representing the Patron object. This will return the 
   * first character of the first name followed by the first character of the
   * last name. For example <code>J.D.</code> for <code>Jeff Daniels</code>.
   * @return a <code>String</code> representing the first and last initial of
   * the patron
   */
  public String toString() {
    return this.firstName.charAt(0) + "." + this.lastName.charAt(0) + ".";
  }
  
}
