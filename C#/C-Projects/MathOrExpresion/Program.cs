using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace MathOrExpresion
{
    class Program
    {

        static void Main(string[] args)
        {
            String inputDate = InputDate();
            bool numWords = CheckExpression(inputDate);
            if (numWords)
            {
                double result = CalculateMath(inputDate);
                Console.WriteLine($"Your math expresion = {result}");
            }
            else
            {
               int result = NumWords(inputDate);
                Console.WriteLine($"In your expression are there {result} words");
            }
            Console.ReadKey();

        }

        static String InputDate()
        {
            String inputDate = "";
            Console.Write("Enter a math expression ( a + b ) or just a sentence: ");
            inputDate = Console.ReadLine();
            return inputDate;
        }

        static Boolean CheckExpression (String inputDate)
        {
            String parent = @"\d+[+|*|/|-]\d+";
            inputDate = inputDate.Replace(" ", String.Empty);
            Regex regex = new Regex(parent);
            MatchCollection matches = regex.Matches(inputDate);
            if(matches.Count > 0)
            {
                regex = new Regex(@"\w+");
                if (regex.Matches(inputDate).Count > 0)
                {
                    return false;
                }
                return true;
            }
            return false;
        }

        static double CalculateMath(String math)
        {
            double result;
            math = math.Replace(" ", String.Empty);
            math = math.Replace(")", String.Empty);
            math = math.Replace("(", String.Empty);
            math = math.Replace(",", String.Empty);
            String parentDelete = @"\d+";
            String[] numList = math.Split(new char[] { '+', '-', '*', '/' });
            Regex regex = new Regex(parentDelete);
            String mathSigns = regex.Replace(math, "");
            result = Double.Parse(numList[0]);
            for (int i = 1; i < numList.Length; i++)
            {
                switch (mathSigns[i - 1])
                {
                    case ('+'):
                        {
                            result += Double.Parse(numList[i]);
                            break;
                        }
                    case ('-'):
                        {
                            result -= Double.Parse(numList[i]);
                            break;
                        }
                    case ('*'):
                        {
                            result *= Double.Parse(numList[i]);
                            break;
                        }
                    case ('/'):
                        {
                            result /= Double.Parse(numList[i]);
                            break;
                        }
                    default:
                        {
                            result += Double.Parse(numList[i]);
                            break;
                        }

                }
            }
            return result;
        }

        static int NumWords (String words)
        {
            String parent = @"\s?\w+\s?";
            Regex regex = new Regex(parent);
            MatchCollection matches = regex.Matches(words);
            return matches.Count;
        }

    }
}
