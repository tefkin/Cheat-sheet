using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cheat_Sheet_C_Sharp
{
    class Program
    {
                
        static void Main(string[] args)
        {

            try
            {




                //http://www.microsoftvirtualacademy.com/Content/ViewContent.aspx?et=7684&m=7669&ct=27111

                Console.WriteLine("Hello World");



                //**********************************************************************************************************************


                // String code
                string myString = "This is a test strong for c:\\drive";
                // must use double \\ for \
                Console.WriteLine(myString);
                // What about double quotation marks?
                string myString3 = "This is a double quote \" ";
                Console.WriteLine(myString3);
                // New line: use \n
                // List of special characters http://is.gd/escape_sequence

                // Remember strings allow substituting in variables
                string myString4 = string.Format("Make :{0} ", "Cat");

                // Can also format output - Currency format
                string myString5 = string.Format("{0:C}", 123.456);
                Console.WriteLine(myString5);

                // Currency - C, Number of digits - N, Percentage - P
                // Can build your own format {0:(###) ###-####} where the # represent the numbers in the sequence
                // http://is.gd/string_format

                // Can also use + operator mystring  +=

                // Instead of using string use stringbuilder. Uses less memory and is faster

                StringBuilder myString6 = new StringBuilder();

                for (int i = 0; i < 100; i++)
                {
                    myString6.Append("--");
                    myString6.Append(i);

                }

                Console.WriteLine(myString6);

                //various strong functions
                myString5.Substring(2, 4);
                myString5.ToUpper();
                myString5.Replace(" ", "--");
                int test = myString5.Length;
                //trim off white
                myString5.Trim();
                //Can chain commands 
                int test2 = myString5.Trim().Length;
                // Strong class hsa lots of methods. Its worth learning them.

                // text reading code
                StreamReader myReader = new StreamReader("Values.txt");
                string line = "";

                while (line != null)
                {
                    line = myReader.ReadLine();
                    if (line != null)
                        Console.WriteLine(line);

                }

                myReader.Close();

                //**********************************************************************************************************************


                //Reference assembles
                //Right click project name
                //	Assembly
                //o	Framework
                //o	Browse, browse
                //o	Goto dll
                //	Recheck reference list in solution explorer
                //	Can now use its classes but might need to include the namespace



                //**********************************************************************************************************************


                //Dates and Times

                DateTime myValue = DateTime.Now;
                Console.WriteLine(myValue);
                Console.WriteLine(myValue.ToString()); //same as above
                Console.WriteLine(myValue.ToShortDateString());
                Console.WriteLine(myValue.ToShortTimeString());
                Console.WriteLine(myValue.ToLongDateString());

                // Date math
                DateTime myValue2 = myValue.AddDays(3);
                Console.WriteLine(myValue2);
                // add includes days months years hours minutes etc
                // Can chain link calls like with strings
                Console.WriteLine(myValue2.AddYears(5).ToShortDateString());
                // Just give me the month
                Console.WriteLine(myValue2.Month);
                //Give me day of the week
                Console.WriteLine(myValue2.DayOfWeek);

                //Date constructor
                DateTime myBirthday = new DateTime(1969, 12, 7);

                //Date differences
                TimeSpan MyAge = DateTime.Now.Subtract(myBirthday);
                Console.WriteLine(MyAge);



                //**********************************************************************************************************************

                //Classes
                // See outside this block to see car class




                //Class enhancements
                // Static
                //Only one instance. Does not need to be instantiated.

                //Virtual
                //Can be overwritten by child implementation. But doesn’t have to be.

                //Abstract
                //Must be overwritten by child implementation. Does not provide functionality but instead serves as a placeholder/template to guide child class design.

                //Public
                //MoM can be viewed by external users of the class

                //Private
                //A MoM describe as private can be used in this class but not is visible to outside users of the class. Used for helper functions.

                //Override
                //Overrides the method or member of the parent class with a method or member preferred in the child class.

                //Void
                //No return type expected.

                //Interface
                //Life an abstract class. But child can inherit multiple interfaces.

                //Sealed
                //No children are allowed





                Car myNewCar = new Car();

                //setting properties
                myNewCar.Make = "toyota";
                myNewCar.Model = "Corola";
                myNewCar.Year = 1971;
                myNewCar.Color = "White";

                //getting property
                Console.WriteLine(myNewCar.Make);

                Console.WriteLine(myNewCar.DetermineMarketValue());



                // Shorthand class set up and putting values into members
                // Object initaliser syntax:
                Car car1 = new Car() { Make = "fast", Model = "red", Color = "blue", Year = 1990 };



                //Static classes dont require instantiation
                MyStatic.Year = 7;

                Console.WriteLine(MyStatic.Year);

                //Here in bike that inherits from vehicle
                bike MyBike = new bike();
                MyBike.size = 7;

                //Can instantiate abstract classes
                //tool mytool = new tool();
                // but can instantiate an object of a class that inherits from the abstract class
                hammer myhammer = new hammer();
                myhammer.weight = 78;





                //**********************************************************************************************************************

                //Call in  procedure
                string myLine = superSecretFormula();




                // double tab for code snippet

                //**********************************************************************************************************************

                Superhero myHero = Superhero.batman;

                // can use tab tab to speed up switch statements and then enter enter after chossing my hero


                string uservalue = "robin";

                Superhero myvalue;



                //tryparse trys to conver uservalue to type superhero and if so puts that value into myvalue
                if (Enum.TryParse<Superhero>(uservalue, true, out myvalue))
                {
                    switch (myvalue)
                    {
                        case Superhero.batman:
                            Console.WriteLine("batman");
                            break;
                        case Superhero.robin:
                            Console.WriteLine("robin");
                            Console.WriteLine(myvalue);
                            break;
                        case Superhero.superman:
                            Console.WriteLine("superman");
                            break;
                        default:
                            break;
                    }
                }


                //**********************************************************************************************************************

                // Collections

                //Old school collections are not strongly typed. So you can dump any sort of class in them

                //old array definition
                string[] banes = { "bob", "jane" };


                //Arraylist
                System.Collections.ArrayList myArrayList = new System.Collections.ArrayList();

                myArrayList.Add(myhammer);
                myArrayList.Add(MyBike);
                myArrayList.Add(myNewCar);

                //Have to cast the output object o to type car. This works fine when it is a car but not when something else = crash
                //foreach (object o in myArrayList)
                //{
                //    Console.WriteLine(((Car)o).Make);

                //}

                //Dictionary is like a list but you put an index item at the front to make it easy to find

                System.Collections.Specialized.ListDictionary myDictionary = new System.Collections.Specialized.ListDictionary();


                myDictionary.Add(myNewCar.Make, myNewCar);




                //New school collections have strongly typed collection objects. This limits what you can put in the array
                // The type os the collection is between angle brackets
                // comes form using systems.collections.generic

                // Generic list

                List<Car> myList = new List<Car>();

                myList.Add(myNewCar);

                foreach (Car car in myList)
                {
                    Console.WriteLine(car.Model);
                }



                //Generic dictionary

                Dictionary<string, Car> myDictionary3 = new Dictionary<string, Car>();


                myDictionary3.Add(myNewCar.Make, myNewCar);
                Console.WriteLine(myDictionary3["toyota"].Model);
                

                // You can use initialiser syntax also in collections
                List<Car> myList2 = new List<Car>(){
                    new Car {Make = "fast", Model = "red"},
                    new Car {Make = "fast2", Model = "red3231"},
                    new Car {Make = "fast3", Model = "red2"}
                };



                //**********************************************************************************************************************

                // For loops
                for (int i = 0; i < 11; i++)
                {

                }


                for (int k = 0; k < 12; k++)
                {

                }


                // While loops
                int w = 0;
                while (w < 12)
                {
                    w++;
                }

                //**********************************************************************************************************************
                // Switch statement

                int answer = 6;

                switch (answer)
                {
                    case 1:
                        Console.WriteLine("answered 1");
                        break;
                    case 2:
                        Console.WriteLine("answered 2");
                        break;
                    case 6:
                        Console.WriteLine("answered 6");
                        break;
                    default:
                        break;
                }


             //**********************************************************************************************************************



                //Dont use cout, using console class
                Console.WriteLine(myLine);
                Console.WriteLine(superSecretFormula2("Jack"));
                Console.ReadLine();

                //**********************************************************************************************************************
                // Error handling
                
                // Look at the class at the far right of new creation. This lists common exception throws
                // Can put them below in your exception check list
                // need also a finally to tidy up erros anddata conections

                // error handling especially important in dealing with external resources
                // deal with most detailed exceptions first before defaulting to more general exception clauses
                // Dont bother the user if you dont have to



            }
            catch (DirectoryNotFoundException e)
            {
                Console.WriteLine("Coulnd find directory");
            }
            catch (FileNotFoundException e)
            {
                Console.WriteLine("Coulnd find file");
            }
            catch (Exception e)
            {
                Console.WriteLine(" error found {0} ", e.Message);
            }
            finally
            {
                Console.WriteLine(" clean up");
            
            }


        }

        //**********************************************************************************************************************


        //Example of a help method
        private static string superSecretFormula()
        {
            return "hello world";

        }

        private static string superSecretFormula2(string name)
        {
            return String.Format("hello, {0}", name);

        }



    }


    class Car
    {
        public string Make { get; set; }
        public string Model { get; set; }
        public int Year { get; set; }
        public string Color { get; set; }

        // type in prop and then tab tab to bring up a shortcut as above


        public double DetermineMarketValue()
        {
            double carValue = 100;
            if (this.Year > 1990)
                carValue = 10000;
            else
                carValue = 2000;

            return carValue;
        }
    
    
    }

    class Vehicle
    {
        virtual public string Make { get; set; }
        public string Model { get; set; }
        public int Year { get; set; }
        public string Color { get; set; }

    

    }

    class bike : Vehicle
    {
        public int size { get; set; }

    
    }

    abstract class tool
    {
        public int value { get; set; }

    
    }

    class hammer : tool
    {
        public int weight { get; set; }

    }

    sealed class jackhammer : hammer
        { }


    //Cant inherit from a sealed clas
    //class redjackhammer : jackhammer
    //{ }



    static class MyStatic
//Static classes dont require instantiation
        //But all members must also be static
    {
        static public int Year { get; set; }
    
    
    }

    //**********************************************************************************************************************

    enum Superhero
    {
        batman,
        robin,
        superman
        
    }



}
