#pragma once
#include <vector>

class string
{
private:
	//char* m_rawString;
	char* m_rawString = new char[0];
	int m_length;

public:
	string(char* charArray);
	string(const string & str);
	~string();
	int GetLength();
	static int GetLength(const string & str);
	static int GetLength(const char* charArray);
	char operator [] (const int & index);
	bool Compare(const string & str);
	static bool Compare(const string & str1, const string & str2);
	void Append(const string & str);
	static void Append(string & base, const string & strToAppend);
	void Prepend(const string & strToPrepend);
	static void Prepend(string & base, const string & strToPrepend);
	char* GetRaw();
	void SetToLowerCase();
	void SetToUpperCase();
	bool FindSubString(const string & str);
	static bool FindSubString(const string & strToSearch, const string & str);
	bool FindSubString(const string & str, const int & index);
	static bool FindSubString(const string & strToSearch, const string & str, const int & index);
	bool ReplaceSubString(const string & subString, const string & replace);
	static bool ReplaceSubString(const string & stringToSearch, const string & subString, const string & replace);
	void operator = (char* charArray);
	void operator = (const string & str);

};