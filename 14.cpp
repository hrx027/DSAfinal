#include <iostream>
using namespace std;
#include <vector>

int findFloor(int  nums[], int target,int size)
{
    int left = 0;
    int right = size - 1;
    int floor = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
        {
            return nums[mid];
        }

        if (nums[mid] < target)
        {
            floor = nums[mid];
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return floor;
}

int findCeil(int  nums[], int target,int size)
{
    int left = 0;
    int right = size- 1;
    int ceil = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
        {
            return nums[mid];
        }

        if (nums[mid] > target)
        {
            ceil = nums[mid];
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return ceil;
}

int findPeak(int  nums[],int size)
{
    int left = 0;
    int right = size - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[mid + 1])
        {
            return nums[mid];
        }

        if (nums[mid] < nums[mid + 1])
        {
            left = mid + 1;
        }
        else
        {
            // If nums[mid] == nums[mid + 1], move either left or right
            right = mid;
        }
    }

    return nums[left];
}

int findMinimum(int  nums[], int size)
{
    int left = 0;
    int right = size - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    return nums[left];
}

int main()
{
    int rotatedArray[] = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int size=9;
    int target = 4;
    
    int floor = findFloor(rotatedArray, target,size);
    int ceil = findCeil(rotatedArray, target,size);
    int peak = findPeak(rotatedArray,size);
    int minimum = findMinimum(rotatedArray,size);

    std::cout << "Floor: " << floor << std::endl;
    std::cout << "Ceil: " << ceil << std::endl;
    std::cout << "Peak: " << peak << std::endl;
    std::cout << "Minimum: " << minimum << std::endl;

    return 0;
}