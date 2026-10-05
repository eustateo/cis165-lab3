#include <iostream>
using namespace std;

int main()
{
    int level1_minutes = 78;
    int level2_minutes = 144;
    const int MINUTES_PER_HOUR = 60;

    int level1_hours = level1_minutes / MINUTES_PER_HOUR;
    int level1_remaining = level1_minutes % MINUTES_PER_HOUR;
    int level2_hours = level2_minutes / MINUTES_PER_HOUR;
    int level2_remaining = level2_minutes % MINUTES_PER_HOUR;

    // Subtract total minutes before converting the extra time.
    int extra_minutes = level2_minutes - level1_minutes;
    int extra_hours = extra_minutes / MINUTES_PER_HOUR;
    int extra_remaining = extra_minutes % MINUTES_PER_HOUR;

    cout << "Level 1: " << level1_hours << " hours and "
         << level1_remaining << " minutes" << endl;
    cout << "Level 2: " << level2_hours << " hours and "
         << level2_remaining << " minutes" << endl;
    cout << "Level 2 took longer by: " << extra_hours << " hours and "
         << extra_remaining << " minutes" << endl;

    return 0;
}
