#include <iostream>
using namespace std;

class Student {
public:
	Student() {
		cout << "Hello, I am a student" << endl;
	}

	~Student() {
		cout << "Good bye, Student out";
	}
};

class Course {
	Student studentArray[10];
};

class University {
public:
	Course courseArray[10];
};

int main() {
	int $ = 1;
	printf("%d", $);
	return 0;
}