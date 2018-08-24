package homework_1;

/**
* A class for the first step of Homework 1. It goes over a few basic static
* methods such as printing an integer array and selection sort.
* Completion time: 1 hour
*
* @author Anton Neuhold
* @version 1.0
*/
public class Homework {
  // Use a for loop and an if statement to put 1s in the odd positions of the
  // array and 0s in the even positions.
  
  /**
   * Initializes the integer array provided by setting 1s in the odd positions
   * and 0s in the even positions.
   * @param intArray the <code>int[]</code> to be initialized
   */
  public static void initializeArray(int[] intArray) {
    for (int i = 0; i < intArray.length; i++) {
      if (i % 2 == 0) {
        intArray[i] = 0;
      } else {
        intArray[i] = 1;
      }
    }
  }

  /**
   * Prints the provided integer array separated by commas.
   * @param intArray the <code>int[]</code> to be printed
   */
  public static void printArray(int[] intArray) {
    for (int i = 0; i < intArray.length; i++) {
      System.out.print(intArray[i]);
      if (i < intArray.length - 1) {
        System.out.print(", ");
      }
    }
    System.out.println();
  }
  
  /**
   * Sorts the given integer array in descending order using the selection
   * sort algorithm.
   * @param intArray the <code>int[]</code> to be sorted
   */
  public static void selectionSort(int[] intArray) {
    int max, temp;
    for (int i = 0; i < intArray.length - 1; i++) {
      max = i;
      for (int scan = i + 1; scan < intArray.length; scan++) {
        if (intArray[scan] > intArray[max]) { max = scan; }
      }
      temp = intArray[max];
      intArray[max] = intArray[i];
      intArray[i] = temp;
    }
  }
  
  /**
   * Calculates the factorial of the provided integer recursively for all
   * positive values. Negative values return 0. 
   * @param i the <code>int</code> to calculate the factorial for
   * @return the <code>int</code> representing the factorial of <code>i</code>
   * which is within the set of natural numbers starting with 0
   */
  public static int factorial(int i) {
    if (i <= 0) {
      return 0;
    } else if (i == 1) {
      return 1;
    } else {
      return i * factorial(i - 1);
    }
  }
  
  /**
   * Tests this class.
   * @param arg the program arguments as a <code>string[]</code>
   */
  public static void main (String [] arg) {
    int [] a = {3, 5, 6, 8, 12, 13, 16, 17, 18, 20};
    int [] b = {18, 16, 19, 3 ,14, 6};
    int [] c = {5, 2, 4, 3, 1};
    // testing initializeArray
    printArray(a); // print: 3, 5, 6, 8, 12, 13, 16, 17, 18, 20
    initializeArray(a);
    printArray(a); // print: 0, 1, 0, 1, 0, 1, 0, 1, 0, 1
    // testing initializeArray
    printArray(b); // print: 18, 16, 19, 3 ,14, 6
    selectionSort (b);
    printArray(b); // print: 19, 18, 16, 14, 6, 3
    // testing factorial
    System.out.println (factorial (5)); //print: 120
    c[0] = factorial (c[0]);
    c[1] = factorial (c[2]);
    printArray(c); // print: 120, 24, 4, 3, 1
  }
}
