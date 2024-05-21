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



bool checkAbhimanyuCanCross(vector<int> &enemyPowerList, int totalNumberOfSkips, int totalNumberOfRecharge, int initialPower)
{
    /**
     * @brief Update the array
     * since at 3rd and 7th circle the enemies can regenerate themselves with half of their initial power 
     * and can attack Abhimanyu at the 4th and the 8th circle
     * Hence we can update the enemy power for the 4th enemy and the 8th enemy
     */
    updateEnemyPowerList(enemyPowerList);


    int currRemainingPower = initialPower;
    int totalNumberOfEnemies = enemyPowerList.size();

    /**
     * @brief Approach
     * When Abhimanyu will not enough power to fight then 
     * we can have two options either to recharge or to skip the fight 
     * using the greedy technique explained below: 
     *      1. If abhimanyu can get enough power to fight with the current enemy by just recharging 
     *         then he should recharge instead of skipping the fight. 
     *      2. Abhimanyu should skip only when after recharging also he will not be able to pass the
     *         circle.
     */


    for(int i = 0; i<totalNumberOfEnemies; i++)
    {
        int currEnemyPower = enemyPowerList[i];
        if(currRemainingPower >= currEnemyPower)
        {
            /* then abhimanyu can pass this circle */
            currRemainingPower = currRemainingPower - currEnemyPower;
            continue;
        }
        

        if((initialPower >= currEnemyPower) && (totalNumberOfRecharge > 0))
        {
            /*
                Abhimanyu will be able to pass the circle after recharging. 
                then it is better to recharge and pass the circle instead of skipping.
            */
            currRemainingPower = initialPower - currEnemyPower;
            totalNumberOfRecharge = totalNumberOfRecharge - 1;
        }
        else if(totalNumberOfSkips > 0)
        {
            /*this means that he is not able to pass the circle even after recharging hence skipping is the way*/
            totalNumberOfSkips = totalNumberOfSkips - 1;
        }
        else
        {
            /* finally no ways in which he can pass the circle hence returning false */
            return false;
        }
    } 



    /* finally he was able to cross all the circles */ 
    return true;

}




void displayOutput(vector<int> &enemyPowerList, int totalNumberOfSkips, int totalNumberOfRecharge, int initialPower, bool canCross)
{
    cout << "For input : " << endl; 
    cout << "Initial Power          p  : " << initialPower << endl;
    cout << "Total Skips Allowed    a  : " << totalNumberOfSkips << endl;
    cout << "Total Recharge Allowed b  : " << totalNumberOfRecharge << endl;
    cout << "List of enemy's Power  k[]: ";

    for(int i = 0;i<enemyPowerList.size();i++)
    {
        cout << enemyPowerList[i] << " ";
    }


    cout << endl;
    cout << "Output : " << boolalpha << canCross << endl;
    cout << "----------------------------------------------------------------" << endl; 
    cout << "----------------------------------------------------------------" << endl;


}





int main()
{
    /**
     * @brief 
     * Following are the assumptions for this problem
     *  1. When Abhimanyu recharge his power then his power will become as initial power p
     *  2. Power values cannot be negative.
     *  3. a, b and k[] will also consists of positive integers
     *  4. Array size is fixed i.e 11 
     */
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
    displayOutput(enemyPowerList, a, b, p, canPassCircles);

    // test case 2
    a = 2;
    b = 3;
    p = 20;

    enemyPowerList = {8, 2, 4, 10, 12, 16, 18, 5, 2, 7, 6};
    canPassCircles = checkAbhimanyuCanCross(enemyPowerList, a, b, p);
    displayOutput(enemyPowerList, a, b, p, canPassCircles);

    // test case 3
    a = 2;
    b = 3;
    p = 20;

    enemyPowerList = {8, 2, 4, 10, 12, 16, 18, 5, 2, 7, 6};
    canPassCircles = checkAbhimanyuCanCross(enemyPowerList, a, b, p);
    displayOutput(enemyPowerList, a, b, p, canPassCircles);

    // test case 4
    a = 0;
    b = 10;
    p = 20;

    enemyPowerList = {8, 2, 4, 10, 12, 16, 18, 5, 2, 7, 6};
    canPassCircles = checkAbhimanyuCanCross(enemyPowerList, a, b, p);
    displayOutput(enemyPowerList, a, b, p, canPassCircles);


    // test case 5
    a = 0;
    b = 0;
    p = 0;

    enemyPowerList = {8, 2, 4, 10, 12, 16, 18, 5, 2, 7, 6};
    canPassCircles = checkAbhimanyuCanCross(enemyPowerList, a, b, p);
    displayOutput(enemyPowerList, a, b, p, canPassCircles);

    // test case 6
    a = 0;
    b = 0;
    p = 0;

    enemyPowerList = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    canPassCircles = checkAbhimanyuCanCross(enemyPowerList, a, b, p);
    displayOutput(enemyPowerList, a, b, p, canPassCircles);
    
    // test case 7
    a = 0;
    b = 0;
    p = 66;

    enemyPowerList = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    canPassCircles = checkAbhimanyuCanCross(enemyPowerList, a, b, p);
    displayOutput(enemyPowerList, a, b, p, canPassCircles);

    // say everything went fine 
    return 0;

}