#include<bits/stdc++.h>

using namespace std;

const int regenerateEnemyIndex1 = 3;
const int regenerateEnemyIndex2 = 7;

void updateEnemyPowerList(vector<int> &enemyPowerList)
{
    // Updating the enemyPowerList as mentioned as follows (0 - based indexing): 
    // enemyPowerList[3] = enemyPowerList[3] + enemyPowerList[2]/2 
    // enemyPowerList[7] = enemyPowerList[7] + enemyPowerList[6]/2

    enemyPowerList[regenerateEnemyIndex1] = enemyPowerList[regenerateEnemyIndex1] + enemyPowerList[regenerateEnemyIndex1-1]/2;

    enemyPowerList[regenerateEnemyIndex2] = enemyPowerList[regenerateEnemyIndex2] + enemyPowerList[regenerateEnemyIndex2-1]/2;

    return;
}

// function to actually solve the problem for this purpose 
bool checkAbhimanyuCanCross(vector<int> &enemyPowerList, int totalNumberOfSkips, int totalNumberOfRecharge, int initialPower)
{
    // since at 3rd and 7th circle the enemies can regenerate themselves with half of their initial power 
    // and can attack Abhimanyu at the 4th and the 8th circle
    // Hence we can update the enemy power for the 4th enemy and the 8th enemy
    updateEnemyPowerList(enemyPowerList);

    int currRemainingPower = initialPower;
    int totalNumberOfEnemies = enemyPowerList.size();

    // this means that the power is not enough to fight 
    // we can have two options either to recharge or to skip the fight 
    // using the greedy technique explained below: 
    //     1. If abhimanyu can get enough power to fight with the current enemy by just recharging 
    //        then he should recharge instead of skipping the fight. 
    //
    //     2. Abhimanyu should skip only when after recharging also he will not be able to pass the
    //        circle. 


    for(int i = 0; i<totalNumberOfEnemies; i++)
    {
        int currEnemyPower = enemyPowerList[i];

        if(currRemainingPower >= currEnemyPower)
        {
            // then abhimanyu can pass this circle 
            currRemainingPower = currRemainingPower - currEnemyPower;
            continue;
        }
        

        if((initialPower >= currEnemyPower) && (totalNumberOfRecharge > 0))
        {
            // Abhimanyu will be able to pass the circle after recharging. 
            // then it is better to recharge and pass the circle.
            currRemainingPower = initialPower - currEnemyPower;
            totalNumberOfRecharge = totalNumberOfRecharge - 1;
        }
        else if(totalNumberOfSkips > 0)
        {
            // this means that he is not able to pass the circle even after recharging hence skipping is the way
            totalNumberOfSkips = totalNumberOfSkips - 1;

            // no change in current remaining power
        }
        else
        {
            // otherwise there are no ways in which he can pass the circle hence returning false 
            return false;
        }
    } 



    // if control reaches here this means he was able to cross all the circles 
    return true;

}

int main()
{
    int totalNumberOfEnemies = 11;
    int a = 0;
    int b = 0;
    int p = 0;
    vector<int> enemyPowerList;

    // test case 1 
    a = 2;
    b = 5;
    p = 20;

    enemyPowerList = {8, 2, 4, 10, 12, 16, 18, 5, 2, 7, 6};

    bool canPassCircles = checkAbhimanyuCanCross(enemyPowerList, a, b, p);


    cout << canPassCircles << endl;

    // say everything went fine 
    return 0;

}