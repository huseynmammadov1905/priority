
// Priority Queue template
// class Student olmalidir.
// Ortalamasi en yuxari olan telebe novbeden chixir.

// Likendlist arashdirin.

#include <iostream>
#include <assert.h>
#include <queue>
using namespace std;





class Student {
	string name;
	string surname;
	double avg;

public:

	Student() {
		name = " ";
		surname = " ";
		avg = 0;
	}

	Student(string name, string surname, double avg) {
		this->name = name;
		this->surname = surname;
		this->avg = avg;
	}

	string GetName() { return name; }

	string GetSurName() { return surname; }

	double GetAvg() { return avg; }

	void SetName(const string name) {
		this->name = name;
	}


	void SetSurName(const string surname) {
		this->surname = surname;
	}

	void SetAvg(const double avg) {
		this->avg = avg;
	}

	bool operator>(const Student obj) {
		return avg > obj.avg;
	}

	friend ostream& operator<<(ostream& out, const Student& obj) {
		out << "name : " << obj.name << endl << "surname : " << obj.surname << endl << "avg : " << obj.avg << endl;
		return out;
	}

};


template<class T>
class PriorityQueue {
	T* arr;
	int capacity;
	int count;
	int rear;

	int GetMax() {
		int max = 0;
		for (int i = 0; i < count; i++)
		{
			if (arr[i] > arr[max])
				max = i;
		}
		return max;
	}

public:

	PriorityQueue(int size) {
		arr = new T[size];
		capacity = size;
		count = 0;
		rear = -1;
	}


	bool IsFull() {
		return count == capacity;
	}

	bool IsEmpty() {
		return count == 0;
	}


	void Push(T value) {
		assert(!IsFull());
		arr[++rear] = value;
		count++;


	}

	void  Pop() {
		assert(!IsEmpty());
		int ind = GetMax();

		for (int i = ind; i < count - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		count--;
	}

	void print() {
		for (int i = 0; i < count; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	~PriorityQueue() {
		delete[] arr;
	}
};



int main() {
	PriorityQueue<Student> student(3);
	student.Push(Student("Bahruz", "Nezerov", 100));
	student.Push(Student("Saxa", "Tanriverdiev", 80.5));
	student.Push(Student("Rustam", "Mammadov", 76.66));

	student.print();
	cout << "------------------" << endl;
	system("pause");
	student.Pop();
	student.print();
	cout << "------------------" << endl;
	system("pause");
	student.Pop();
	student.print();

}