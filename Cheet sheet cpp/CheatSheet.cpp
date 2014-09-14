// Cheat notes updated 7 26 2014


#include "stdafx.h"
// If you have stdafx / recompiled header, any other includes not in the stdafx.h file will confuse the compiler


//Want for basic programs
// If you have stdafx / recompiled header, any other includes not in the stdafx.h file will confuse the compiler
#include <iostream>		// Console input and output
#include <vector>


//Likely always want me
using namespace std;

//Linking
/// In later versions on wsvc
// View-> property manager
// goto microsoft cpp win32 user files
// reverse click and properties
// gets you to properties pages
//  goto common properties, vc++ directories, Include directories: Put the directory that includes the .hpp
//  goto common properties, vc++ directories, library directories: Put the directory that includes the lib directory
// .dll libraries need to be exporter with compiled code, .lib only needed at compile time
// Dont need libary directory for standard libraries

//re referencing this code in your files
// must include the hpp reference in your main file that uses the function
//must include the cpp in the source file list to be compiled
// CPP file should include the HPP reference

//May need to turn off precomiled header. In VS 2013, highlight project, Alt f7 and turn off header.

//Precompiled Headers
// If you want to use them they arent hard:
// Allow VS to include them in your project. It will include a stdafx.cpp and .h
// Ignore the .cpp
// Put all your projects various .h include references in the stdafx.h file
// Dont put them in any .cpp file including your main
// In each of you .cpp files put as the first line #include "stdafx.h"
// It should have no other includes and should not have any code before it



// Where do my cpp and hpp files go?
// If they are original to this project then usually in the same root diretory as the project file
// if they are in another project and you are using both cpp and hpp probably best to copy across
// if they are the library/dll and associated hpp thenleave where they are and reference them in the properties

//MSVS versions
// VS 2005 - Version 8
// VS 2008 - Version 9
// VS 2010 - Version 10
// VS 2012 - Version 11
// VS 2013 - Version 12

// How to change the librarys and includes in VS 2010 ++
// Load solution, view -> property explorer or manager, Expand all configs interested in updating, select mciro cpp win 32 user (can use ctrl to select multiple files), Properties -> VCC directories
// In the include directory point to the directory with your .h files
// in the library directories, point to your .lib files
// Make sure you hard return to actually lock in the selection

// Dot vs arrows
// Dot operator can't be overloaded, arrow operator can be overloaded. Arrow operator is generally meant to be applied to pointers (or objects that behave like pointers, like smart pointers). Dot operator can't be applied to pointers.
// It's simple, whenever you see x->y know it is the same as (*x).y


// Libraries to explore

//		Cpp
//			GIU
//				VS - > MFC -> MFC Wizard
//				Qt
//				SmartWin 1.0




//		Python
//		Roguewave
//			http://www.roguewave.com/products/imsl-numerical-libraries/c-library/overview/features.aspx
//		Student portfolio toolkit
//			http://wiki.quantsoftware.org/index.php?title=QuantSoftware_ToolKit
//		paid portfolio
//			http://www.rapidquant.com/features
//		algo trading
//			https://github.com/quantopian/zipline
//		Ultra finance backetet
//			https://code.google.com/p/ultra-finance/

// How to do forms in visual studio 2013
//http://www.bogotobogo.com/cplusplus/application_visual_studio_2013.php
// Use template CLR -> Emptty project
// Add new item UI
// In the myform.cpp

//			#include "MyForm.h"
//
//			using namespace System;
//			using namespace System::Windows::Forms;
//
//
//			[STAThread]
//			void Main(array<String^>^ args)
//			{
//				Application::EnableVisualStyles();
//				Application::SetCompatibleTextRenderingDefault(false);
//
//				RandomNumberGenerator::MyForm form;
//				Application::Run(%form);
//			}
//
// Goto properties of project->config prop->Linker->Advanced -> Entry point: type Main
// Goto properties of project->config prop->Linker->system -> subsystem -> Windows


// DB linking in VS 2013
// 1. vs2010 Goto common properties-> Framework -> Add new refer -> .net and add refer to MySQL.data
//    vs2013 Goto common properties-> Framework -> Extension and add refer to MySQL.data
// 2. Add 	using namespace MySql::Data::MySqlClient; to the form.h
// 3. Most coding now done in code section of Myform.h and not .cpp (this just launches us)
//

// Which drill down token to use ::, -> or . ?
//
// Short version:	:: to drill into class or namespace
//					. to drill into an object
//					-> to drill into a pointer object

//Longer version:
//You may be wondering why methods and class members are referenced using the dot(.), double full colon(::) or the arrow(-%gt;).There are three distinct cases where each of these are used :
//The period is used when we want to reference a member(property or method) of an object.The symbol to the left of the dot will always be an object.For example, a Double object such as the “temp” variable defined in our example has a member method named ToString so that we can call it to convert the Double number into a character string representation : temp.ToString(.......)
//The double - colon is used in cases where the method or function(to the right of the ::) is a member of the class or namespace given on the left of the ::.For example, the Show method is a member of the MessageBox class so we call it using : MessageBox::Show(...)
//For another example, note that the string class has a member called Empty that we can refer to as String::Empty.
T//he arrow syntax -> (a minus sign followed by a greater - than sign) is used when the symbol to the left is a pointer to an object.For example, all of the fields and buttons added to a form are declared as pointers to objects.You can see this in the InitializeComponent method that will be set up automatically for you when you first create a Windows Forms application.For example, the TextBox named tbTempF is defined as :
//this->tbTempF = (gcnew System::Windows::Forms::TextBox());

//After it is defined, all references to its member properties and methods should be done using the arrow syntax.For example, to get the Text property of the tbTempF text box we use : tbTempF->Text
//If we wanted to change the background color(BackColor property) of the tbTempF text box, we could make an assignment(using equal sign) such as :



//What do different template types do
// VS 2013
//		ATL: ATL libraries. For COM components. Active X for office. Going out of date. MS version of STL.
//		!MFC: Microsoft Foundation classes. MFC easier than win32. Default goto. Dont need .net at runtime just mfc libraries at compile.
//		General:
//		WIN32: Least assumptions most work.
//		!CLR: Managd code. Needs .NET. Best libraries. Needs .net installed at runtime. limited to windows. Means you dont have to learn a lot of crap.
//		STL: Standard template library.
// VS 2010
//



int _tmain(int argc, _TCHAR* argv[])
{

	//Comments

	//Variable declaration
		double d1, d2;
		//variable declaration often done in header file
		double MyArray[1000];


		typedef vector<double> Vector;
			// uses standard template vector so need to vector library
			// this first line creates a shortcut Vector to defining a variable of type vector<double>
		Vector futureValues(5);
			// This creates a variable using the above type def


		//some basic data structures

		//Vectors
			// Constructors
		vector<long> testVector(10);
		vector<int> testVector;
		vector<float> testVector(5, 1.0);
		vector<int> vectorOne(10, 5);

			//multidimension
		vector<vector<float> > mdVector;
		mdVector.at(row).at(0)



			//Accessing
				//base zero
				//unsafe old way
		vectorOne[index]
				//safe new way
		vectorOne.at(index)


			//adding and deleting elements
			vectorOne.push_back(rand())
			vectorOne.pop_back()

			//  insert middle 6 elements from vectorOne into vectorTwo...
			vectorTwo.insert(vectorTwo.begin() + 5, vectorOne.begin() + 2, vectorOne.end() - 2);

		//  erase third element (index=2) and insert a zero at start (index=0)
					vectorTwo.erase(vectorTwo.begin() + 2);
					vectorTwo.insert(vectorTwo.begin(), 0);
					//begin() returns an iterator to the first element of a vector, while end() returns an iterator to the element just past the last element in a vector.



			//Other methods
			vectorOne.size()

			vector<int> vectorOne(10, 5);
		vectorOne.resize(7);


		//Boost smart pointers
		boost::shared_ptr<Quote> s2yRate(new SimpleQuote(s2yQuote));
		//A Smart Pointer is a C++ object that acts like a pointer, but additionally deletes the object when it is no longer needed.


		// Pointers
		//Pointers are variables that can contain an address of data                              
		//		int* p;

		// To get at that data you must dereference them by putting a star in front of them
		//		MySum = 2 + *p;

		// For Pointer arrarys, you can also dereference by using the [] indexer
		// If you pass in an array of pointers without [], its like a pointer or address
		// but then make sure you deference it later on when you want to use the data

		// For pointers to objects you can also use the arrow and this saves time. The following are equivalent:
		//		print (*p).PV()
		//		print p->PV()

		// Pointers dont start with memory. This memory can be obtained by pointing to existing variable or by use of new
		//		int* p = new SimpleOption;
		// 		int* p = ExistingObjecy (check)
		//Another approach
		//	SimpleOption* opt;
		//	opt = new SimpleOption;
		//	opt->print(); (which is sort of like (*opt).print();
		//	delete opt;

		// As pointers dont have memory assigned at creation, they are flexible (heap). Other explicitly defined are on stack and are cleaned up automatically

		// Its worth talking about references at the same time
		// References get the address of an existing variable. So:
		// int MyVar = 7;
		// int* p = &MyVar;

		// References / addresses cant be changed. (stack memory).

		// Debuging pointers is tricky.
		// Looking at them in watch window just shows meangingless address
		// Instead use a dereference code ary[3][5]

		// Function points
		// These are pointers that point to functions. They allow you to pass functions around.

		// Declare a function pointer 
		//		double (*f)(double x)
		// But it most likely would be  used in another function that do a root seek on a function such as
		//		 double Midpoint( double (*f)(double x))
		//			{ 
		//				res = f(x);
		//			}
		// The confusing thing about this example is that besides the initial tricky pointer reference in the calling funciton, you can treat it as usual. 
		// So see next example:

		// Passing in and out pointers or arrays
		//		complex FixArr[5];
		//		a = compsum(FixArr);
		// Where
		//		Complex compsum(Complex* carr)
		//		{
		//			complex sum = carr[0];
		//			return sum;
		//		}

		// Then in calling code:
		//		double MyFunc (double x) {return x*x*x;}
		//		double d = Midpoint(MyFunc);

		// Smart pointers - Boost
		//		Automatically deletes pointer
		//		a couple of classes
		//	http://www.codeproject.com/Articles/8394/Smart-Pointers-to-boost-your-code


		//Old Pointers
		void Sample1_Plain()
		{
			CSample * pSample(new CSample);

			if (!pSample->Query())
				// just some function...
			{
				delete pSample;
				return;
			}

			pSample->Use();
			delete pSample;

		}

		//Boost pointer equivalent
		#include "boost/smart_ptr.h"


		boost::shared_ptr<IborIndex> indexSixMonths(new
			Euribor6M(rhTermStructure));


		void Sample1_ScopedPtr()
		{
			boost::scoped_ptr<CSample>
				samplePtr(new CSample);

			if (!samplePtr->Query())
				// just some function...
				return;




			samplePtr->Use();

		}







	//input and output
		//Use iostream library
		cout << "Give the first number: ";
		cin >> d1;
		cout << "Give the second number: ";
		cin >> d2;



	//some basic data structures

	//If then else
		if (c == 'a')
		{
			cout << "Max value is: " << Max(d1, d2) << endl;
		}
		else
		{
			cout << "Min value is: " << Min(d1, d2) << endl;
		}


	//looping
		for (long mm = 1; mm <= 10000000; mm *= 12)
		{
			cout << "Periodic: " << mm << ", " << FutureValue(P0, nPeriods, r, mm) << endl;

		}





	//Basic functions
		// Max and Min of two numbers
		double Min(double x, double y)
		{
					if (x < y)
						return x;

					return y;
		}

		// You can pass in the variable address to save space but also allows the function to change variable
		double Min2(double& x, double& y)
		{
			if (x < y)
				return x;

			return y;
		}

		//You can stop inadvertant passparamater value changing by using constant
		double Min3(const double& x, double& y)
		{
			if (x < y)
				return x;

			return y;
		}





	//basic classes
			//Should be done as seperate files. Use the build in class creator

		//This would be in the header file
		class EuropeanOption
		{
		
			double n(double x) const;
	
		};


		//This would be in the code file
		#include "EuropeanOption.hpp"

		EuropeanOption::EuropeanOption()
		{ // Default call option

			init();
		}

		EuropeanOption::~EuropeanOption()
		{

		}


		double EuropeanOption::Delta() const
		{
			if (optType == "C")
				return CallDelta();
			else
				return PutDelta();

		}

		// Short hand member initilisation done as part of the contructor function
		double EuropeanOption::EuropeanOption(double External_r, double External_sigma) : r(External_r), sigma(External_sigma)
		{
			// EMPTY

		}


}

