# include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>      
using namespace std;

const string WHITESPACE = " \n\r\t\f\v";

string ltrim(const string& s)
{
	size_t start = s.find_first_not_of(WHITESPACE);
	return (start == string::npos) ? "" : s.substr(start);
}

string rtrim(const string& s)
{
	size_t end = s.find_last_not_of(WHITESPACE);
	return (end == string::npos) ? "" : s.substr(0, end + 1);
}

string trim(const string& s)
{
	return rtrim(ltrim(s));
}

bool startsWith(string mainStr, string toMatch)
{
	if (mainStr.find(toMatch) == 0)
		return true;
	else
		return false;
}

class Facet
{
private :
	float normal[3];
	float vertex1[3];
	float vertex2[3];
	float vertex3[3];
public :
	void setnormal(float x, float y, float z)
	{
		float arr[] = {x,y,z};
		for (int i = 0; i < 3; i++)
		{
			normal[i] = arr[i];
		}
	}
	void shownormal()
	{
		for (int i = 0; i < 3; i++)
		{
			cout << normal[i] << "\t";
		}
		cout << endl;
	}
	void setvertex1(float x, float y, float z)
	{
		float arr[] = { x,y,z };
		for (int i = 0; i < 3; i++)
		{
			vertex1[i] = arr[i];
		}
	}
	void showvertex1()
	{
		for (int i = 0; i < 3; i++)
		{
			cout << vertex1[i] << "\t";
		}
	}
	
	void setvertex2(float x, float y, float z)
	{
		float arr[] = { x,y,z };
		for (int i = 0; i < 3; i++)
		{
			vertex2[i] = arr[i];
		}
	}
	void showvertex2()
	{
		for (int i = 0; i < 3; i++)
		{
			cout << vertex2[i] << "\t";
		}
	}

	void setvertex3(float x, float y, float z)
	{
		float arr[] = { x,y,z };
		for (int i = 0; i < 3; i++)
		{
			vertex3[i] = arr[i];
		}
	}
	void showvertex3()
	{
		for (int i = 0; i < 3; i++)
		{
			cout << vertex3[i] << "\t";
		}
	}
	void showfacet()
	{
		shownormal();
		showvertex1();
		showvertex2();
		showvertex3();
	}
};

float arr[100][3];
float arr1[100][3];

int main()
{
	ifstream fin;
	fin.open("E:/CCTech/4-9-2020/cube.stl");
	string str;
	string stri;
    int nooffacets = 0;
	int noofvertices = 0;
	string m = "facet normal";
	string z = "vertex";
	int v = 0;
	int ko = 0;
	while (getline(fin, str))
	{
		stri = trim(str);
		if (startsWith(stri, m))
		{
			nooffacets++;
		}
		if (startsWith(stri, z))
		{
			noofvertices++;
		}
	}
	fin.close();

	
	fin.open("E:/CCTech/4-9-2020/cube.stl");

	while (getline(fin, str))
	{
		stri = trim(str);
		if (startsWith(stri, m))
		{
			string stringvalues = stri;
			//cout << stringvalues << endl;
			istringstream iss(stringvalues);
			int e = 0;
			for (int n = 0; n < 5; n++)
			{
				string val;
				iss >> val;
				if (n > 1)
				{
					arr[v][e] = std::stof(val);
					e++;
				}
			}
			v++;
		}
		if (startsWith(stri, z))
		{
			string strings = stri;
			istringstream iff(strings);
			int ok = 0;
			for (int n = 0; n < 4; n++)
			{
				string cal;
				iff >> cal;
				if (n > 0)
				{
					arr1[ko][ok] = stof(cal);
					ok++;
				}
			}
			ko++;
		}
	}
	fin.close();

	Facet *f = new Facet[12];
	for (int i = 0; i < nooffacets; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			f[i].setnormal(arr[i][j], arr[i][j + 1],arr[i][j + 2]);
			
		}
		f[i].shownormal();
	}
  
	/*for (int i = 0; i < 36; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr1[i][j] << "\t";
		}
		cout << endl;
	 }*/
	 
	int op = 0;
	for (int i = 0; i < nooffacets; i++)
	{
		
		for (int j = 0; j < 1; j++)
		{
			f[i].setvertex1(arr1[op][j], arr1[op][j + 1], arr1[op][j + 2]);
		}
		op = op + 3;
		
	}

	int os = 1;
	for (int i = 0; i < nooffacets; i++)
	{

		for (int j = 0; j < 1; j++)
		{
			f[i].setvertex2(arr1[os][j], arr1[os][j + 1], arr1[os][j + 2]);
		}
		os = os + 3;
		//f[i].showvertex2();
	}

	int om = 2;
	for (int i = 0; i < nooffacets; i++)
	{

		for (int j = 0; j < 1; j++)
		{
			f[i].setvertex3(arr1[om][j], arr1[om][j + 1], arr1[om][j + 2]);
		}
		om = om + 3;
		
	}


	for (int i = 0; i < nooffacets; i++)
	{
		cout << endl;
		f[i].showvertex1();
		cout << endl;
		f[i].showvertex2();
		cout << endl;
		f[i].showvertex3();
	}
	cout << endl;
	f[2].showfacet();
	cout << endl;

	cin.get();
}









