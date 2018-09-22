;;; Answers the questions in homework 4 and defines the corresponding functions
;;; that do various simple tasks in lisp.
;;; Homework 4
;;; Completion time: 2.5 hrs
;;;
;;; author: Anton Neuhold
;;; version: 1.0

;; Question 2:
; The function "foo" adds the two values (x and y) together and returns the result.
; The code will return (without the interpreter return values):
; 30
; 70
; 90
;
; In Java:
; public static int foo(int x, int y) {
;   return x + y;
; }

;; Question 3:
; This function will recursively print all the elements of the given list. The
; function  will print the following (without the interpreter return values):
; 1
; 2
; 3
; 4
; 5
; 6
; 7
; 8
; 9
; 0
; "a"
; "e"
; "i"
; "o"
; "u"
;
; In Java (this function takes advantage of using an Object array so that it can
; use the toString function of any given object, because it seems that the lisp
; implementation allows any kind of value in a list. This also means that in order
; to use this function, an Object[] array needs to be created with any values to pass
; into it):
; public static void myPrint(Object[] oArray) {
;   if (oArray.equals(null) || oArray.length == 0) {
;     return;
;   } else if (oArray.length == 1) {
;     System.out.println(oArray[0]);
;   } else {
;     System.out.println(oArray[0]);
;     myPrint(Arrays.copyOfRange(oArray, 1, oArray.length));
;   }
; }

;; Question 4
;; An iterative function that calculates the factorial of a positive integer and
;; returns the result.
(defun factorial1 (n)
  (let ((sum 1))
    (dotimes (i n sum)
      (setq sum (* sum (+ 1 i))))))

;; Question 5
;; A recursive function that calculates the factorial of a positive integer and
;; returns the result
(defun factorial2 (n)
  (if (= n 0) 1
    (* n (factorial2(- n 1)))))

;; Question 6
;; This function counts the number of times the symbol 'a occurs within a list, and
;; not within any sublists. An alternate function definition is given in the comment
;; just in case using count isn't allowed.
;
;(defun amount (l) 
;  (if (not (null l)) 
;      (if (equal 'a (car l))
;          (+ (amount (cdr l)) 1)
;        (amount (cdr l)))
;    0))
(defun amount (l) (count 'a l))

;; Question 7
;; A recursive function that returns the Fibonacci number of the given value.
(defun fib (n)
  (cond
   ((= n 0) 0)
   ((= n 1) 1)
   ((> n 1) (+ (fib (- n 1)) (fib (- n 2))))))

;; Question 8
;; Takes the smaller of the two numbers and returns it
(defun small (num-1 num-2)
  (if (< num-1 num-2) num-1 num-2))

;; Question 9
;; Sums the value and all decremented values down to 0. 
(defun sum (n)
  (cond
   ((< n 1) 0)
   ((= n 1) 1)
   (t (+ n (sum (- n 1))))))

;; Question 10:
;; Printed values are surrounded by two back ticks to help differentiate them
;; from the comment
; 1. (setq x '(a b)) ; sets the symbol 'x to the list '(a b). The quote indicates
; that the following list is not to be evaluated, and instead to be treated as
; data. Setq is a non-destructive assignment.
; 2. (setq y '(a b c)) ; sets the symbol 'y to the list '(a b c)
; 3. (print (car x)) ; prints the first element in '(a b) which is the symbol `A`
; 4. (print (car y)) ; prints the first element in '(a b c) which is the symbol `A`
; 5. (print (cdr x)) ; prints the list without the first element of '(a b c) 
; which is `(B)`
; 6. (print (cdr y)) ; prints the list without the first element of '(a b c) 
; which is `(B C)`
; 7. (print (car (cdr x))) ; prints the first element of the list (cdr x) which is the
; symbol `B`
; 8. (print (car (cdr y))) ; prints the first element of the list (cdr y) which is the
; symbol `B`
; 9. (print (cadr x)) ; does the same thing as (car (cdr x)) so it prints the symbol 
; `B`
; 10. (print (cadr y)) ; does the same thing as (car (cdr y)) so it prints the symbol
; `B`
; 11. (print (append x y)) ; append returns a new list that has the last pointer of 
; list x, point to the first cell of list y. So it prints `(A B A B C)`

; test function definition
(defun test ()
  (print "CSE 240 Assignment 4. Anton Neuhold")
  (print (factorial1 100))
  (print (factorial2 100))
  (print (amount '(b c (a) a)))
  (print (fib 7))
  (print (small 5 7))
  (print (sum 5))
)

(test)