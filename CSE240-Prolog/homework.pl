% A prolog database that answers the questions in homework 5 within comments,
% mostly. All of the rules and facts that could be outside of a commment, and
% were asked for, are.
% Homework 5
% Completion time: 3 hours
% 
% @author Anton Neuhold
% @version 1.0

% Question 2:
hot(weather).
likes(_, weather) :- hot(weather).

% Question 3:
% They both produce the same result. This is because prolog knows how to use
% these operators "+" in both infix, and prefix form. Internally it uses
% infix notation for these calculations.

% Question 4:
woman(jane).
man(john).
healthy(john).
healthy(jane).
wealthy(john).
traveler(Person) :- healthy(Person), wealthy(Person).
can_travel(Person) :- traveler(Person).
% ?- can_travel(X). returns "X = john"
% ?- healthy(X), wealthy(X). returns "X = john"

% Question 5:
vegetarian(jose).
vegetarian(james).
vegetable(carrot).
vegetable(egg_plant).
% likes(jose, X) :- vegetable(X).
loves(Who, egg_plant) :- vegetarian(Who).
% "vegetable(X)." returns "X = carrot" then if ";" is pressed it also returns 
% "X = egg_plant" becuase it will return any of the names that have the 
% vegetable relationship.
% "vegetable(potato)." returns "false" because potato is not one of the names
% with the vegetable relationship.
% "likes(jose, What)" returns all of the vegetables because jose likes all 
% vegetables. So it will return "What = carrot" then if ";" is pressed it will
% also return "What = egg_plant".
% "likes(Who, egg_plant)" returns "Who = jose" because he likes all vegetables.
% "loves(Who, egg_plant)" returns "Who = jose" and "Who = james" because all
% vegetarians love egg_plant.

% Question 6:
% Part a is written as inline comments after each line.
fib(1,1). % The fibonacci number of 1 is 1. Base case 1
fib(2,1). % The fibonacci number of 2 is 1. Base case 2
fib(N,R) :- N >= 3, N1 is N-1, N2 is N-2, fib(N1,R1), fib(N2,R2), R is R1+R2.
% The fibonacci number of N is R if N is more than or equal to 3, and N1 is
% N-1, and N2 is N-2, and the fibonacci number of N1 is R1, and the fibonacci
% number of N2 is R2, and R is R1+R2. 
% Part b:
% The fibonacci number of 3 starts by testing the fact of fib(1,1), where
% 3 is not equal to 1. 
% Then it moves on to the fact fib(2,1) where 3 does not equal 2. 
% Then it moves on to fib(N,R), where N is substituted for 3. 
%% The first condition is tested that N >= 3 which it is.
%% The second condition determines that N1 is N-1, so N1 is 2.
%% The third condition tests N2 is N-2, so N2 is 1.
%% The fourth condition tests fib(N1,R1), where N1 is 2.
%%% fib(1,1) is tested but 2 is not equal to 1
%%% fib(2,1) is tested, which unifies fib(2,R1) so R1 is 1.
%% The fifth condition tests fib(N2,R2) where N2 is 1.
%%% fib(1,1) is tested, which unifies fib(1,R2) so R2 is 1.
%% The sixth condition is tested which is R is R1+R2 so R is 2.
% fib(3,R) is unified so R is 2. 
% Part c:
% fib(9,R) is 34, because it is the 9th (starting at 0) value in the fibonacci
% sequence. This asks prolog what R would have to be for the first argument of
% fib to be 9. 
% fib(9,9) is asking prolog (or the database) if a situation where the first
% argument of fib can be 9, and the second or the result, can also be 9, which
% there is not, so it returns false.

% Question 7:
% a)
reads_programming_book(john).
% b)
% likes(Person, sparky) :- asu_student(Person).
% c)
% ?- likes(Who, sparky).
% d)
hates(jane, City) :- big(City), crowded(City).

% Question 8:
sum(1,1). % Base case, where the sum of 1 is 1.
sum(Number,Result) :- Number >= 2, Number1 is Number-1, 
  sum(Number1, Result1), Result is Number+Result1.

% Question 9:
% loves(Person, Something) :- owns(Person, Something).






















