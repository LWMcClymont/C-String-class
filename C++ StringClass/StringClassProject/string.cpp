#include "string.h"

string::string(char* charArray)
{
	int len = GetLength(charArray);
	m_length = len;
	m_rawString = new char[len + 1];
	
	for (int i = 0; i < len; i++)
	{
		m_rawString[i] = charArray[i];
	}

	m_rawString[len] = '\0';
}

string::string(const string & str)
{
	int len = str.m_length;
	m_length = len;
	m_rawString = new char[len + 1];

	for (int i = 0; i < len; i++)
	{
		m_rawString[i] = str.m_rawString[i];
	}

	m_rawString[len] = '\0';

}

string::~string()
{
	delete[] m_rawString;
}

int string::GetLength()
{
	return m_length;
}

int string::GetLength(const string & str)
{
	return str.m_length;
}

int string::GetLength(const char * charArray)
{
	int indexCount = 0;

	while (*(charArray + indexCount) != '\0') 
	{
		indexCount++;
	}

	return indexCount;
}

char string::operator[](const int & index)
{
	return m_rawString[index];
}

bool string::Compare(const string & str)
{
	if (m_length == str.m_length)
	{
		for (int i = 0; i < m_length; i++)
		{
			if (m_rawString[i] != str.m_rawString[i])
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}

	return true;
}

bool string::Compare(const string & str1, const string & str2)
{
	if (str1.m_length == str2.m_length)
	{
		for (int i = 0; i < str1.m_length; i++)
		{
			if (str1.m_rawString[i] != str2.m_rawString[i])
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}

	return true;
}

void string::Append(const string & str)
{
	char* curString = m_rawString;
	int curLength = m_length;

	int len = m_length + str.m_length;
	m_length = len;
	m_rawString = new char[len + 1];

	int secondStringIndex = 0;

	for (int i = 0; i < len; i++)
	{
		if (i < curLength)
		{
			m_rawString[i] = curString[i];
		}
		else
		{
			m_rawString[i] = str.m_rawString[secondStringIndex++];
		}
	}

	m_rawString[len] = '\0';
}

void string::Append(string & base, const string & strToAppend)
{
	char* curString = base.m_rawString;
	int curLength = base.m_length;

	int len = base.m_length + strToAppend.m_length;
	base.m_length = len;
	base.m_rawString = new char[len + 1];

	int secondStringIndex = 0;

	for (int i = 0; i < len; i++)
	{
		if (i < curLength)
		{
			base.m_rawString[i] = curString[i];
		}
		else
		{
			base.m_rawString[i] = strToAppend.m_rawString[secondStringIndex++];
		}
	}

	base.m_rawString[len] = '\0';
}

void string::Prepend(const string & strToPrepend)
{
	char* curString = m_rawString;
	int curLength = m_length;

	int len = m_length + strToPrepend.m_length;
	m_length = len;
	m_rawString = new char[len + 1];

	int secondStringIndex = 0;

	for (int i = 0; i < len; i++)
	{
		if (i < strToPrepend.m_length)
		{
			m_rawString[i] = strToPrepend.m_rawString[i];
		}
		else
		{
			m_rawString[i] = curString[secondStringIndex++];
		}
	}

	m_rawString[len] = '\0';
}

void string::Prepend(string & base, const string & strToPrepend)
{
	char* curString = base.m_rawString;
	int curLength = base.m_length;

	int len = base.m_length + strToPrepend.m_length;
	base.m_length = len;
	base.m_rawString = new char[len + 1];

	int secondStringIndex = 0;

	for (int i = 0; i < len; i++)
	{
		if (i < strToPrepend.m_length)
		{
			base.m_rawString[i] = strToPrepend.m_rawString[i];
		}
		else
		{
			base.m_rawString[i] = curString[secondStringIndex++];
		}
	}

	base.m_rawString[len] = '\0';
}

char * string::GetRaw()
{
	return m_rawString;
}

void string::SetToLowerCase()
{
	int upperCaseRangeMax = 90;
	int upperCaseRangeMin = 65;

	for (int i = 0; i < m_length; i++)
	{
		int asciiNum = ((int)*(m_rawString + i));
		if (asciiNum >= upperCaseRangeMin && asciiNum <= upperCaseRangeMax)
		{
			// + 32 is equivilent to uppercase ascii value.
			m_rawString[i] = asciiNum + 32;
		}
	}
}

void string::SetToUpperCase()
{
	int lowerCaseRangeMax = 122;
	int lowerCaseRangeMin = 97;

	for (int i = 0; i < m_length; i++)
	{
		int asciiNum = ((int)*(m_rawString + i));
		if (asciiNum >= lowerCaseRangeMin && asciiNum <= lowerCaseRangeMax)
		{
			// - 23 is equivilent to lowercase ascii value;
			m_rawString[i] = asciiNum - 32;
		}
	}
}

bool string::FindSubString(const string & str)
{
	char first = str.m_rawString[0];
	int correct = 0;

	for (int i = 0; i < m_length; i++)
	{
		correct = 0;

		if (m_rawString[i] == first)
		{
			int baseCurIndex = i;
			for (int ii = 0; ii < str.m_length; ii++)
			{
				if (m_rawString[baseCurIndex++] != str.m_rawString[ii])
				{
					break;
				}
				
				correct++;
			}

			if (correct == str.m_length)
			{
				return true;
			}
		}
	}

	return false;
}

bool string::FindSubString(const string & strToSearch, const string & str)
{
	char first = str.m_rawString[0];
	int correct = 0;

	for (int i = 0; i < strToSearch.m_length; i++)
	{
		correct = 0;

		if (strToSearch.m_rawString[i] == first)
		{
			int baseCurIndex = i;
			for (int ii = 0; ii < str.m_length; ii++)
			{
				if (strToSearch.m_rawString[baseCurIndex++] != str.m_rawString[ii])
				{
					break;
				}

				correct++;
			}

			if (correct == str.m_length)
			{
				return true;
			}
		}
	}

	return false;
}

bool string::FindSubString(const string & str, const int & index)
{
	char first = str.m_rawString[index];
	int correct = 0;

	return false;
}

bool string::FindSubString(const string & strToSearch, const string & str, const int & index)
{
	return false;
}

bool string::ReplaceSubString(const string & subString, const string & replace)
{
	return false;
}

bool string::ReplaceSubString(const string & stringToSearch, const string & subString, const string & replace)
{
	return false;
}

void string::operator=(char * charArray)
{
	int len = GetLength(charArray);
	m_length = len;
	m_rawString = new char[len + 1];

	for (int i = 0; i < len; i++)
	{
		m_rawString[i] = charArray[i];
	}

	m_rawString[len] = '\0';
}

void string::operator=(const string & str)
{
	int len = str.m_length;
	m_length = len;
	m_rawString = new char[len + 1];

	for (int i = 0; i < len; i++)
	{
		m_rawString[i] = str.m_rawString[i];
	}

	m_rawString[len] = '\0';
}