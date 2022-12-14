#include <iostream>
#include <string>

using namespace std;

class MyString
{
public:

	MyString()
	{
		str = nullptr;
		length = 0;
	}

	MyString(const char *str)
	{
		length = strlen(str);
		this->str = new char[length+1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}

		this->str[length] = '\0';
	}

	~MyString()
	{
		delete[] this->str;
	}

	void Print()
	{
		cout << str << endl;
	}

	MyString(const MyString& other)
	{
		length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';

	}

	MyString& operator = (const MyString &other)
	{
		if (this->str != nullptr)
		{
			delete[] str;
		}

		length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';

		return *this;
	}

	MyString operator + (const MyString& other)
	{
		MyString newstr;

		int thisLength = strlen(this->str);
		int otherLength = strlen(other.str);

		length = thisLength + otherLength;

		newstr.str = new char[thisLength + otherLength + 1];

		int i = 0;
		for (;i < thisLength; i++)
		{
			newstr.str[i] = this->str[i];
		}

		for (int j = 0; j < otherLength; j++,i++)
		{
			newstr.str[i] = other.str[j];
		}
		newstr.str[thisLength + otherLength] = '\0';

		return newstr;
	}

	bool operator == (const MyString& other)
	{
		if (this->length != other.length)
		{
			return false;
		}

		for (int i = 0; i < this->length; i++)
		{
			if (this->str[i] != other.str[i])
			{
				return false;
			}
		}
		return true;
	}

	bool operator !=(const MyString& other)
	{
		return !(this->operator==(other));
	}

	char &operator [] (int index)
	{
		return this->str[index];
	}

	int Length()
	{
		return length;
	}

	MyString(MyString&& other)
	{
		this->length = other.length;
		this->str = other.str;
		other.str = nullptr;
	}

private:

	char* str;
	int length;

};

int main()
{
	setlocale(LC_ALL, "Russian");
	system("color 0A");

	MyString str("Hello");
	MyString str2("World");

	MyString result = str + str2;
	result.Print();

	return 0;
}