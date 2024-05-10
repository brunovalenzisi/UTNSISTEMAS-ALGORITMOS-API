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
      return c-'0'-49+65;
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
   if(n==0){return 0;}
   int r=pow(10,i);
   if(i<0 || r>abs(n)){return -1;}
   return (abs(n)/r)%10;
}

int digitCount(int n)
{
    int grado = 0;
    int resto = abs(n);
    if (n == 0)
    {
        return 1;
    }
    while (resto > 1)
    {
        resto = (resto / 10);
        grado++;
    }

    return grado;
}

string intToString(int i)
{
    if (i == 0)
    {
        return "0";
    }

    int digitos = digitCount(i);
    string salida = "";
    if (i < 0)
    {
        salida += "-";
    }
    for (int j = 0; j <= digitos; j++) 
    {
        int digit = getDigit(i, digitos - j); 
        char c = intToChar(digit);
        salida += c;
    }
    return salida;
}

int stringToInt(string s, int b)
{
    int digitos = length(s);
    bool negativo = false;
    int salida = 0;
    int inicio = 0;

 
    if (s[0] == '-')
    {
        negativo = true;
        inicio = 1; 
    }

    for (int i = inicio; i < digitos; i++)
    {
        char c = s[i];
        salida = salida * b + charToInt(c);
    }

    if (negativo)
    {
        salida *= -1;
    }

    return salida;
}


int stringToInt(string s) // ok
{  
      return stringToInt(s,10);
   return 0;
}

string charToString(char c)
{
   string salida="";
   salida += c;
   return salida;
}

char stringToChar(string s)
{ char c=s[0];
   return c;
}

string stringToString(string s)
{
   return s;
}

string doubleToString(double d)
{  string salida="";
   double D=fabs(d);
   if(d<0){salida+='-';};  
   int parteEntera=floor(D);
   salida+=intToString(parteEntera);
   salida+='.';
   double parteDecimal=D-parteEntera;
   double check=parteEntera;
   int i=1;
   while(check!=D){
   check=parteEntera+(trunc(parteDecimal*pow(10,i)))/(pow(10,i));
   int digit=getDigit((trunc(parteDecimal*pow(10,i))),0);
   char c=intToChar(digit);
   salida+=c;
   i++;}
   
   return salida;
  
}

double stringToDouble(string s)
{
bool negativo=false;
int pos=indexOf(s,'.');
string parteEnteraString="";
string parteDecimalString="";

if(s[0]=='-'){
negativo=true;
parteEnteraString=substring(s,1,pos);
parteDecimalString=substring(s,pos+1);
cout<<"parteEntera: "<<parteDecimalString<<endl;
cout<<"parteDecimal: "<<parteEnteraString<<endl;
}
else{
parteEnteraString=substring(s,0,pos);
parteDecimalString=substring(s,pos+1);
cout<<"parteDecimal: "<<parteDecimalString<<endl;
cout<<"parteEntera: "<<parteEnteraString<<endl;
}


double salida=0;
int parteEnteraInt=stringToInt(parteEnteraString);
int parteDecimalInt=stringToInt(parteDecimalString);
double parteDecimal=parteDecimalInt/pow(10,length(parteDecimalString));
salida+=parteEnteraInt+parteDecimal;
if(negativo){salida*=-1;}


   return salida;
}

bool isEmpty(string s)
{
   return length(s)==0?true:false; 
   
}

bool startsWith(string s, string x)
{  if(x==""){
   if(s[0]==' '){return true;}else{return false;}
}
   string prefijo=substring(s,0,length(x));
 
   return prefijo==x?true:false;
}

bool endsWith(string s, string x)
{if(x==""){
   if(s[length(s)-1]==' '){return true;}else{return false;}
}

   string sufijo=substring(s,length(s)-length(x));
   return sufijo==x?true:false;
}

bool contains(string s, char c)
{
bool salida=false;
for(int i=0;i<length(s);i++){
   if (s[i]==c){salida=true;
   break ;}
}
   return salida;
}

string replace(string s, char oldChar, char newChar)
{ string salida=s;
   for(int i=0;i<length(s);i++){
      if(s[i]==oldChar){salida[i]=newChar;}
   }
   return salida;
}

string insertAt(string s, int pos, char c)
{
   if(pos>=length(s)){return s + c;}
   string prefijo = substring(s,0,pos);
 string sufijo = substring(s,pos);
   return prefijo + c + sufijo;
}

string removeAt(string s, int pos)
{
   if(pos>=length(s)){return substring(s,0,length(s)-1);}
   string prefijo = substring(s,0,pos);
   string sufijo = substring(s,pos+1);
   return prefijo + sufijo;
   return "";
}

string ltrim(string s) {
    int i = 0;
    while (s[i] == ' ') {
        s = removeAt(s, i);
    }
    return s;
}

string rtrim(string s)
{
int i = s.length() - 1;
    while (i >= 0 && s[i] == ' ') {
      s=removeAt(s, i);
        i--; 
    }
    return s;
}

string trim(string s)
{  s=rtrim(s);
   s=ltrim(s);
   return s;
}

string replicate(char c, int n)
{ string salida="";
for(int i=0 ; i<n ; i++){
   salida+=c;
}
   return salida;
}

string spaces(int n)
{
   string s="";
for(int i=0;i<n;i++){
   s+=' ';
}
   return s;
}

string lpad(string s, int n, char c)
{  int l=length(s);
   string salida="";
   if(n>l){
      salida+=replicate(c,n-l);
   }
   salida+=s;
   return salida;
}

string rpad(string s, int n, char c)
{
   int l=length(s);
   string salida="";
   salida+=s;
   if(n>l){
      salida+=replicate(c,n-l);
   }
   return salida;
}

string cpad(string s, int n, char c)
{
   int l=length(s);
   string salida="";
   if(n>l){
      if((n-l)%2>0){
         salida+=replicate(c,(n-l)/2);
         salida+=s;
         salida+=replicate(c,(n-l)/2+1);
      }
      else{
         salida+=replicate(c,(n-l)/2);
         salida+=s;
         salida+=replicate(c,(n-l)/2);
      }
   }
   else{
      salida+=s;
   }
   return salida;
}

bool isDigit(char c)
{
   
   return (c>='0' && c<='9')?true:false;
}

bool isLetter(char c)
{if(c>='A' && c<='Z'){return true;}
else if(c>='a' && c<='z'){return true;}
return false;
}

bool isUpperCase(char c)
{
if(c>='A' && c<='Z'){return true;}
return false;
}

bool isLowerCase(char c)
{
   if(c>='a' && c<='z'){return true;}
return false;
}

char toUpperCase(char c)
{if(isLowerCase(c)){
   int i= charToInt(c);
   char c=intToChar(i-65+10);
   return c;
}
return c;
}

char toLowerCase(char c)
{
   if(isUpperCase(c)){
   int i= charToInt(c);
   char c=intToChar(i+65-10);
   return c;
}
return c;
}

string toUpperCase(string s)
{string salida="";
for(int i =0; i < s.length(); i++){
if(isLowerCase(s[i])){
   salida+=toUpperCase(s[i]);
}else{salida+=s[i];}
}
   return salida;
}

string toLowerCase(string s)
{
  string salida="";
for(int i =0; i < s.length(); i++){
if(isUpperCase(s[i])){
   salida+=toLowerCase(s[i]);
}else{salida+=s[i];}
}
   return salida;
}

int cmpString(string a, string b)
{
   if(a>b){return 1;}
   else if(a<b){return -1;}
   else if(a==b){return 0;}
}

int cmpDouble(double a, double b)
{
   if(a>b){return 1;}
   else if(a<b){return -1;}
   else if(a==b){return 0;}
}

#endif
