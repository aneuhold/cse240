package homework_1;

import java.util.Arrays;

public class TestClass {

  public static void main(String[] args) {
    Object[] intArray = {0, 1, 2, 3};
    myPrint(intArray);
  }
  
  public static void myPrint(Object[] oArray) {
    if (oArray.equals(null) || oArray.length == 0) {
      return;
    } else if (oArray.length == 1) {
      System.out.println(oArray[0]);
    } else {
      System.out.println(oArray[0]);
      myPrint(Arrays.copyOfRange(oArray, 1, oArray.length));
    }
  }

}
