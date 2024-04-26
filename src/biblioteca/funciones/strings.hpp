#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int length(string s)
{
   int i = 0;
   int n = 0;
   while (s[i] != '\0')
   {
      i++;
      n++;
   }
   return n;
}

int charCount(string s, char c)
{
   int i = 0;
   int n = 0;
   while (s[i] != '\0')
   {
      if (s[i] == c)
      {
         n++;
      }
      i++;
   }
   return n;
}

string substring(string s, int d, int h)
{
   int i = d;
   string salida = "";
   if (d > h || h > length(s) || d < 0)
   {
      return "";
   }

   while (s[i] != '\0' && i < h)
   {
      salida += s[i];
      i++;
   }
   return salida;
}

string substring(string s, int d) // ok
{
   string salida = "";
   int i = d;
   if (d > length(s))
   {
      return "";
   }
   while (s[i] != '\0' && i <= length(s))
   {
      salida += s[i];
      i++;
   }
   return salida;
}

int indexOf(string s, char c) // ok
{
   int i = 0;
   int j = -1;
   while (s[i] != '\0')
   {
      if (s[i] == c)
      {
         j = i;
         break;
      }
      i++;
   }
   return j;
}

int indexOf(string s, char c, int offSet) // ok
{
   {
      int i = 0;
      int j = -1;
      while (s[i] != '\0')
      {
         if (s[i] == c && i >= offSet)
         {
            j = i;
            break;
         }
         i++;
      }
      return j;
   }
}

int indexOf(string s, string toSearch) // ok
{
   int i = 0;
   int j = -1;
   if (toSearch == "")
   {
      return -1;
   }
   while (s[i] != '\0')
   {
      string sub = substring(s, i, i + length(toSearch));
      if (toSearch == sub)
      {
         j = i;
         break;
      }
      i++;
   }
   return j;
}

int indexOf(string s, string toSearch, int offset) // ok
{
   int i = 0;
   int j = -1;
   if (toSearch == "")
   {
      return -1;
   }
   while (s[i] != '\0')
   {
      string sub = substring(s, i, i + length(toSearch));
      if (toSearch == sub && i >= offset)
      {
         j = i;
         break;
      }
      i++;
   }
   return j;
}

int lastIndexOf(string s, char c)
{
   int i = 0;
   int j = -1;
   while (s[i] != '\0')
   {
      if (s[i] == c)
      {
         j = i;
      }
      i++;
   }
   return j;
}

int indexOfN(string s, char c, int n)

{
   if (n <= 0)
   {
      return -1;
   }
   int count = 0;
   int i = 0;
   int j = -1;
   while (s[i] != '\0')
   {
      if (s[i] == c)
      {
         j = i;
         count++;
      }
      if (count == n)
      {
         break;
      }
      i++;
   }
   if (n > count)
   {
      return length(s);
   }
   else
   {

      return j;
   }
}

int charToInt(char c)
{
   if(c>='0'&& c<='9'){
   return c-'0';
   }else if(c>='A'&& c<='Z'){
      return c-'0'-7;
   }else if(c>='a'&& c<='z'){
      return c-'0'-39;
   }


   
}

char intToChar(int i)
{
   
    if (i >= 0 && i <= 9) {
        return i + '0'; 
    }
    
    else if (i >= 10 && i <= 35) {
        return i - 10 + 'A'; 
    }
    else if (i >= 65 && i <= 90) {
        return i - 65 + 'a'; 
    }
    
    else {
        return '\0';
    }
}

int getDigit(int n, int i)
{
int r=pow(10,i);
   if(i<0 || r>abs(n)){return -1;}
   return (abs(n)/r)%10;
}

int digitCount(int n)
{int grado=1;
int resto=abs(n);
   while (resto>1)
   {
      resto=(resto/10);
      grado++;
   }
   
   return grado;
}

string intToString(int i)
{
   return "";
}

int stringToInt(string s, int b) // ok
{
   return 0;
}

int stringToInt(string s) // ok
{
   return 0;
}

string charToString(char c)
{
   return "";
}

char stringToChar(string s)
{
   return 'X';
}

string stringToString(string s)
{
   return "";
}

string doubleToString(double d)
{
   return "";
}

double stringToDouble(string s)
{
   return 1.1;
}

bool isEmpty(string s)
{
   return true;
}

bool startsWith(string s, string x)
{
   return true;
}

bool endsWith(string s, string x)
{
   return true;
}

bool contains(string s, char c)
{
   return true;
}

string replace(string s, char oldChar, char newChar)
{
   return "";
}

string insertAt(string s, int pos, char c)
{
   return "";
}

string removeAt(string s, int pos)
{
   return "";
}

string ltrim(string s)
{
   return "";
}

string rtrim(string s)
{
   return "";
}

string trim(string s)
{
   return "";
}

string replicate(char c, int n)
{
   return "";
}

string spaces(int n)
{
   return "";
}

string lpad(string s, int n, char c)
{
   return "";
}

string rpad(string s, int n, char c)
{
   return "";
}

string cpad(string s, int n, char c)
{
   return "";
}

bool isDigit(char c)
{
   return true;
}

bool isLetter(char c)
{
   return true;
}

bool isUpperCase(char c)
{
   return true;
}

bool isLowerCase(char c)
{
   return true;
}

char toUpperCase(char c)
{
   return 'X';
}

char toLowerCase(char c)
{
   return 'X';
}

string toUpperCase(string s)
{
   return "";
}

string toLowerCase(string s)
{
   return "";
}

int cmpString(string a, string b)
{
   return 0;
}

int cmpDouble(double a, double b)
{
   return 0;
}

#endif
