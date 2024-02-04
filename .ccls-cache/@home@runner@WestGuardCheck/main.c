#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool check1_2s(double array[], int ID, double mean, double std)
{
  if ((array[ID] > mean + 2 * std) || (array[ID] < mean - 2 * std))
    return true;
  else
    return false;
}

bool check1_3s(double array[], int ID, double mean, double std)
{
  if ((array[ID] > mean + 3 * std) || (array[ID] < mean - 3 * std))
    return true;
  else
    return false;
}

bool check2_2s(double array[], int ID, double mean, double std)
{
  if (ID < 1)
    return false;
  if (array[ID] > mean + 2 * std)
    if (array[ID-1] > mean + 2 * std)
      return true;
  if (array[ID] < mean - 2 * std)
    if (array[ID-1] < mean - 2 * std)
      return true;
  return false;
}

bool checkR_4s(double array[], int ID, double mean, double std)
{
  if (ID < 1)
    return false;
  if (array[ID] - array[ID-1] > 4 * std)
    return true;
  return false;
}

bool check4_1s(double array[], int ID, double mean, double std)
{
  if (ID < 4)
    return false;
  if ((array[ID] > mean + std) && 
    (array[ID-1] > mean + std) && 
    (array[ID-2] > mean + std) &&
    (array[ID-3] > mean + std))
    return true;
  if ((array[ID] < mean - std) && 
    (array[ID-1] < mean - std) && 
    (array[ID-2] < mean - std) &&
    (array[ID-3] < mean - std))
    return true;
  
  return false;
}

bool check10x(double array[], double mean)
{
  bool violation = true;
  for (int ID = 1; ID < 10; ID++)
    {
      if((array[ID] - mean) * (array[ID+1] - mean) <= 0 )
        violation = false;
    }
  
  return violation;
}

int main(void) {

  double array[] = {7.6, 7.7, 7.7, 8.6, 8.8, 7.6, 7.7, 7.8, 7.7, 7.9};
  double mean = 7.5;
  double std = 0.4;

  for (int ID = 0; ID < 10; ++ID)
    {
      if (check1_3s(array, ID, mean, std))
        printf("ID %d - Rule 1_3s violation\n", ID+1);
      else if (check2_2s(array, ID, mean, std))
        printf("ID %d - Rule 2_2s violation\n", ID+1);
      else if (check1_2s(array, ID, mean, std))
        printf("ID %d - Rule 1_2s violation\n", ID+1);
      if (checkR_4s(array, ID, mean, std))
        printf("ID %d - Rule R_4s violation\n", ID+1);
      if (check4_1s(array, ID, mean, std))
        printf("ID %d - Rule 4_1s violation\n", ID+1);
    }
  if (check10x(array, mean))
    printf("ID 10 - Rule 10x violation\n");
  
  return 0;
}