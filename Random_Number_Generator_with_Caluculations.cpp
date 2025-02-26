#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
   srand(time(0));
   
   rand();

    int num;

   cout << "How many samples do you want to generate? ";
   int n_samples;
   cin >> n_samples;

    double stored_samples[n_samples] = { }; //array to store our random numbers

   cout << "\nWhat is the maximum value? ";
   int max;
   cin >> max;
   
   cout << "\nWhat is the minimum value? ";
   int min;
   cin >> min;
   
   cout << "\nWhat is the delta value? ";
   double delta;
   cin >> delta;
   cout << endl;

   int count = 0;
   double sum = 0;
   double variance;
   double std_dev;
  
   if (min > max || delta > max - min) //Input validation
   {
       cout << "Minimum or delta value is not acceptable.";
   }
   
   else
   {
       do
   {
      
      for(int i = 0; i < 20; i++) // loop for rows
  {
      for (int j = 0; j < 4; j++) //Loop for columns and average
      {
        
        if (count++ >= n_samples)
        {
            break;
        }
        int num = (rand() % (int(max/delta)- int (min/delta + 1)) + int (min/delta));

        sum += num * delta;
        
        cout << fixed << setw(11) << setprecision(3) << num * delta << " ";
        
        stored_samples[count - 1] = num * delta;
    
      }
      
      cout << endl;
  }
   } while (count < n_samples);
   

   }

   cout << " + " << endl;
   cout << "------------------------------------------------" << endl;

   cout << "Sum: " << sum << endl;
   
   double average = sum / n_samples; //Computation for average
   
   for(int i = 0; i < n_samples; i++) //Variance numerator for-loop
   {
       variance += pow((stored_samples [i]) - average, 2);
   }

   cout << "Average: " << fixed << setprecision(3) << average << endl;
   
   variance = variance/n_samples; //denominator portion of variance
   
   cout << "Variance: " << fixed << setprecision(3) << variance << endl;
   
   std_dev = sqrt(variance);
   
   cout << "Standard Deviation: " << fixed << setprecision(3) << std_dev << endl;
   
}
