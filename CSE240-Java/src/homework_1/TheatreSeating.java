package homework_1;

/**
* Works as a tool to keep track of theatre seats, and who has reserved them.</br>
* Homework 1 </br>
* Completion time: 1.25 hrs
* 
* @author Anton Neuhold
* @version 1.0
*/
public class TheatreSeating {
  /** 
   * The <code>Patron[][]</code> instance representing the seating arrangement
   * for the theatre.
   */
  Patron[][] seating;
  
  /**
   * Creates the theatre seating array with the given number of rows and
   * columns. Each seat in the theater is populated with a default patron
   * until a new one is assigned.
   * @param rowNum the <code>int</code> representing the number of rows for the
   * theatre
   * @param columnNum the <code>int</code> representing the number of columns 
   * for the theatre
   */
  public TheatreSeating(int rowNum, int columnNum) {
    this.seating = new Patron[rowNum][columnNum];
    for (int i = 0; i < this.seating.length; i++) {
      for (int j = 0; j < this.seating[0].length; j++) {
        this.seating[i][j] = new Patron();
      }
    }
  }
  
  /**
   * Returns the {@link Patron} at the given row and column starting at 0. If
   * the seating location is invalid, a new Patron object is returned.
   * @param row the <code>int</code> indicating the row starting at 0
   * @param col the <code>int</code> indicating the column starting at 0
   * @return the Patron object located at the row and column
   */
  public Patron getPatronAt(int row, int col) {
    if (checkBoundaries(row, col)) {
      return this.seating[row][col];
    } else {
      return new Patron();
    }
  }
  
  /**
   * Attempts to assign the given {@link Patron} to the given row and column.
   * The row and column start at 0. Returns false if the location is invalid, 
   * or if the location is already taken by another patron.
   * @param row the <code>int</code> indicating the row starting at 0
   * @param col the <code>int</code> indicating the column starting at 0
   * @param tempPatron the Patron to be assigned to the given location
   * @return <code>true</code> if the patron was successfully assigned to the
   * row and column
   */
  public boolean assignPatronAt(int row, int col, Patron tempPatron) {
    if (checkBoundaries(row, col) &&
        this.seating[row][col].getFirstName().equals("***") &&
        this.seating[row][col].getLastName().equals("***")) {
      this.seating[row][col] = tempPatron;
      return true;
    } else {
      return false;
    }
  }
  
  /**
   * Checks if the given <code>row</code> and <code>col</code> are valid
   * locations in the Theatre. <code>row</code> and <code>col</code> start
   * at 0.
   * @param row the <code>int</code> indicating the row starting at 0
   * @param col the <code>int</code> indicating the column starting at 0
   * @return <code>true</code> if the given <code>row</code> and 
   * <code>col</code> indicate a valid seating location
   */
  public boolean checkBoundaries(int row, int col) {
    if (row >= 0 &&
        row < this.seating.length &&
        col >= 0 &&
        col < this.seating[0].length) {
      return true;
    } else {
      return false;
    }
  }
  
  /**
   * Creates a string representing the {@link TheatreSeating} object. This 
   * will return a string consisting of the each {@link Patron} object's 
   * <code>String</code> in each row and column. An example output of 3 rows
   * and columns with some patrons seated is below: </br>
   * <code>
   * M.G. *.*. J.C. </br>
   * *.*. *.*. M.M. </br>
   * D.D. C.C. *.*. </br>
   * </code>
   * @return a <code>String</code> representing the current seating
   * arrangement for the Theatre.
   */
  public String toString() {
    String result = "";
    for (int row = 0; row < this.seating.length; row++) {
      for (int col = 0; col < this.seating[0].length; col++) {
        result += this.seating[row][col] + " ";
      }
      result += "\n";
    }
    return result;
  }
}
